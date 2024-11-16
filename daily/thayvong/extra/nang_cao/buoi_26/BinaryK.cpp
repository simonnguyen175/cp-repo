#include<bits/stdc++.h>
#define simon "BinaryK"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const long long MOD = 1e9 + 7;

int n, k;
long long f[N], g[N], ans;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> k;

    // f[i] la so luong xau thoa man ket thuc tai 0
    // g[i] la so luong xau thoa man ket thuc tai 1

    if ( k == 1 ) {cout << 1; return 0;}
    f[1] = f[0] = 1;
    g[1] = g[0] = 1;

    for (int i = 2; i <= n; i ++){
        g[i] = g[i-1] + f[i-1];
        if ( i >= k )
            f[i] = f[i-1] + g[i-1] - g[i-k] + MOD * MOD;
        else
            f[i] = f[i-1] + g[i-1];

        g[i] %= MOD;
        f[i] %= MOD;

        //cout << f[i] <<' '<<g[i] << '\n';

    }

    ans = ( f[n] % MOD + g[n] % MOD ) % MOD ;

    cout << ans;

    return 0;
}
