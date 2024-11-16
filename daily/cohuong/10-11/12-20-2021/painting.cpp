#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll n, m, k, s = 0, ans = 1;
ll f[N];

int main(){
    if ( fopen("painting.inp", "r") ){
        freopen("painting.inp", "r", stdin);
        freopen("painting.out", "w", stdout);
    }

    cin >> n >> m >> k;

    f[0] = 1;
    for (int i = 1; i < k; i ++){
        f[i] = f[i-1] * m % MOD;
        ( s += f[i] ) %= MOD;
    }
    for (int i = k; i <= n; i ++){
        f[i] = s * (m-1) % MOD;
        s = ( s - f[i-k+1] + f[i] + MOD ) % MOD;
    }

    for (int i = 1; i <= n; i ++)
        ( ans *= m ) %= MOD;

    ans = ( ans - f[n] + MOD ) % MOD;

    cout << ans;

    return 0;
}
