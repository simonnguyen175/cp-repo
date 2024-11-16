#include<bits/stdc++.h>
#define simon "space"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const int MOD = 1e9 + 7;

int L, H, K;
ll C[N][N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> L >> H >> K;

    if ( K == 1 ) { cout << ( L + 1 ) * ( H + 1 ) % MOD; return 0; }

    C[0][0] = 1;
    for (int i = 1; i <= 2000; i ++){
        C[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % MOD;
    }

    ll ans = 0;
    for (int x = 0; x <= L; x ++)
    for (int y = 1; y <= H; y ++)
        ( ans += ( !x ? 1 : 2 ) * C[__gcd(x, y)][K-1] % MOD * (L-x+1) % MOD ) %= MOD;

    cout << ans;

    return 0;
}
