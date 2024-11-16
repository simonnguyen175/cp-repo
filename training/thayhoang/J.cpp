#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int n, m;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

namespace sub1{
    int fib[5005], dp[5005];

    void solve(){
        fib[0] = fib[1] = 1;
        for (int i = 2; i <= m; i ++)
            fib[i] = add(fib[i-1], fib[i-2]);

        dp[1] = 1;
        for (int i = 2; i <= m; i ++){
            dp[i] = Pow(fib[i], n);
            for (int j = i - 1; j >= 1; j --)
                dp[i] = add(dp[i], -mul(dp[j], Pow(fib[i-j], n)));
        }

        cout << dp[m] << '\n';
    }
}

namespace sub2{
    int c[105][105];
    vector<vector<int>> dp;

    void solve(){
        c[0][0] = 1;
        for (int i = 1; i <= n; i ++){
            c[i][0] = 1;
            for (int j = 1; j <= i; j ++)
                c[i][j] = add(c[i-1][j], c[i-1][j-1]);
        }

        dp.resize(m+2);
        for (int i = 0; i <= m; i ++)
            dp[i].resize(n+2);

        dp[1][0] = 1;
        for (int i = 1; i < m; i ++)
        for (int j = 0; j <= n; j ++) if ( dp[i][j] ){
            for (int k = 1; k <= n - j; k ++)
                dp[i+1][k] = add(dp[i+1][k], mul(dp[i][j], c[n-j][k]));
        }

        int ans = 0;
        for (int i = 1; i <= n; i ++)
            ans = add(ans, dp[m][i]);

        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n;

    if ( m <= 5000 ) sub1::solve();
    else
        sub2::solve();

    return 0;
}
