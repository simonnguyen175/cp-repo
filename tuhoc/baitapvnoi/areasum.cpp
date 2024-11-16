#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

int n, m;
ll x[N+5], y[N+5], f[N+5], g[N+5], s, sx, sy;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> x[i];
    for (int i = 1; i <= m; i ++) cin >> y[i];

    s = 0;
    for (int i = 2; i <= n; i ++){
        f[i-1] = f[i-2] + x[i] - x[i-1];
        ( s += f[i-1] ) %= MOD;
    }

    sx = s;
    for (int i = 2; i < n; i ++){
        sx = ( sx + s - (n-i+1) * f[i-1] % MOD + MOD * MOD ) % MOD;
        s =  ( s - f[i-1] + MOD ) % MOD;
    }

    s = 0;
    for (int i = 2; i <= m; i ++){
        g[i-1] = ( g[i-2] + y[i] - y[i-1] ) % MOD;
        ( s += g[i-1] ) % MOD;
    }

    sy = s;
    for (int i = 2; i < m; i ++){
        sy = ( sy + s - (m-i+1) * g[i-1] % MOD + MOD * MOD ) % MOD;
        s  = ( s - g[i-1] + MOD ) % MOD;
    }

    ll ans = sx * sy % MOD;

    cout << ans;

    return 0;
}

