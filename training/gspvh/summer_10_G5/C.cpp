#include<bits/stdc++.h>
#define simon "delta"
using namespace std;
const int N = 5e5 + 5;
const int MOD = 998244353;

int sub, n, k;
int a[N], pw2[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> sub >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int l = 1, ans = 0;
    deque<int> mx, mn;
    for (int i = 1; i <= n; i ++){
        while ( mx.size() && a[mx.back()] < a[i] ) mx.pop_back();
        while ( mn.size() && a[mn.back()] > a[i] ) mn.pop_back();
        mx.push_back(i);
        mn.push_back(i);
        while ( mx.size() && mn.size() && a[mx.front()]-a[mn.front()] > k && l < i ){
            if ( l == mx.front() ) mx.pop_front();
            if ( l == mn.front() ) mn.pop_front();
            l ++;
        }
        ans = add(ans, i-l+1);
    }
    cout << ans << ' ';

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = add(pw2[i-1], pw2[i-1]);

    sort(a+1, a+1+n);
    l = 1, ans = 0;
    for (int i = 1; i <= n; i ++){
        while ( l < i && a[i]-a[l] > k )
            l ++;
        ans = add(ans, pw2[i-l]);
    }
    cout << ans;

    return 0;
}
