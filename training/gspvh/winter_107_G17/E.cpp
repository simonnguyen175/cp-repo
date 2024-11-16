#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int N = 6425;

int n, d, t;
int pw2[N], dp[N][N], f[N][N], g[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("singer.inp", "r", stdin);
    freopen("singer.out", "w", stdout);

    cin >> n >> d >> t;
    d --;

    pw2[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw2[i] = pw2[i-1] * 2 % MOD;

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= t; j ++){
        if ( i < d ){
            if ( !j ) dp[i][j] = pw2[i];
            else dp[i][j] = 0;
        }

        if ( i >= d ){
            dp[i][j] = add(dp[i][j], add(f[i-1][j], -f[i-d][j]));
            dp[i][j] = add(dp[i][j], g[i-d][j-1]);
            if ( j == i - d + 1 )
                dp[i][j] = add(dp[i][j], 2);
        }

        f[i][j] = add(f[i-1][j], dp[i][j]);
        g[i][j] = add(g[i-1][j-1], dp[i][j]);
    }

    cout << dp[n][t];

    return 0;
}
