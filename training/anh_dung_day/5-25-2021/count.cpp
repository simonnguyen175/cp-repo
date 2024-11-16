#include<bits/stdc++.h>
#define simon "count"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, p, q;

long long dp[N][N], C[N][N];

void init(){
    dp[0][0] = C[0][0] = 1;
    for (int i = 1; i <= 5000; i ++){
        C[i][0] = 1;
        for (int j = 1; j <= i; j ++){
            dp[i][j] = ( dp[i-1][j-1] + ( dp[i-1][j] * (i-1) ) % MOD ) % MOD;
            C[i][j] = ( C[i-1][j] + C[i-1][j-1] ) % MOD;
        }
    }
}

void solve(){
    while ( cin >> n >> p >> q ){
        if ( n == 0 && p == 0 && q == 0 ) break;

        long long ans = 0;

        for (int i = 1; i <= n; i ++)
            ans = ( ans + ( ( dp[i-1][p-1] * dp[n-i][q-1] ) % MOD * C[n-1][i-1] ) % MOD ) % MOD;
        cout << ans << '\n';
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    init();
    solve();

    return 0;
}
