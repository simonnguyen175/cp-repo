#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n;
int a[N], f[N][20], l[N], r[N];

int get(int u, int v){
    int k = __lg(v-u+1);
    return max(f[u][k], f[v-(1<<k)+1][k]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        f[i][0] = a[i];
    }

    for (int j = 1; j <= 19; j ++)
    for (int i = 1; i + (1<<j) <= n; i ++)
        f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);

    stack<int> stk;
    for (int i = 1; i <= n; i ++){
        while ( stk.size() && a[stk.top()] > a[i] ) stk.pop();
        if ( stk.size() ) l[i] = stk.top();
        else l[i] = 0;
        stk.push(i);
    }
    while ( stk.size() ) stk.pop();
    for (int i = n; i >= 1; i --){
        while ( stk.size() && a[stk.top()] > a[i] ) stk.pop();
        if ( stk.size() ) r[i] = stk.top();
        else r[i] = n+1;
        stk.push(i);
    }

//    for (int i = 1; i <= n; i ++) cout << l[i] << ' ' << r[i] << '\n';

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        if ( !l[i] ) ans += r[i] - i;
        else{
            int lo = 1, hi = l[i], res;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( get(mid, l[i]) < a[i] ) res = mid, hi = mid - 1;
                else lo = mid + 1;
            }
//            cout << i << ' ' << l[i] << ' ' << res << '\n';
            ans += 1LL * ( l[i] - res + 1 ) * ( r[i] - i );
        }
    }

    ans += 1LL*n*(n-1)/2;

    cout << ans;

    return 0;
}
