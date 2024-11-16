#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], f[N], bit[N];

void update(int u, int v){
    for (; u <= N-5; u += u&-u)
        bit[u] = max(bit[u], v);
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res = max(res, bit[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    int ans = 0, id;
    for (int i = 1, x; i <= n; i ++){
        cin >> a[i];
        f[i] = get(a[i]-1) + 1;
        if ( f[i] > ans ) ans = f[i], id = i;
        update(a[i], f[i]);
    }

    vector<int> lis;
    lis.pb(id);
    int cur = id;
    while ( id ){
        if ( f[id] + 1 == f[cur] && a[id] < a[cur] ){
            lis.pb(id);
            cur = id;
        }
        id --;
    }

    cout << ans << '\n';
    reverse(lis.begin(), lis.end());
    for (int x : lis) cout << x << ' ';

    return 0;
}
