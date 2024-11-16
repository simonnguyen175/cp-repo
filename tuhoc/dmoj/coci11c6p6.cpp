#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, m;
ll f[(1<<20)], pw2[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        int k, t = 0;
        cin >> k;
        for (int j = 1, x; j <= k; j ++)
            cin >> x, t |= 1<<(x-1);
        f[t] ++;
    }

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++) pw2[i] = pw2[i-1] * 2 % MOD;

    for (int i = 0; i < m; i ++)
    for (int j = 0; j < (1<<m); j ++)
        if ( BIT(j, i) ) f[j] += f[j^(1<<i)];

    for (int i = 0; i < (1<<m); i ++)
        f[i] = ( pw2[f[i]] - 1 + MOD ) % MOD;

    ll ans = 0;
    for (int i = 0; i < (1<<m); i ++)
        if ( (__builtin_popcount(i) + m) % 2 == 0 )
            ans = ( ans + f[i] ) % MOD;
        else ans = ( ans - f[i] + MOD ) % MOD;

    cout << ans;

    return 0;
}
