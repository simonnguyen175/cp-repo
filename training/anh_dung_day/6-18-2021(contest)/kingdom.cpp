#include<bits/stdc++.h>
#define simon "kingdom"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, c[N][N], dp[N][N], ans = INT_MAX;

int main(){
    FASTio
    if ( fopen(simon".inp", "r" ) ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> c[i][j];

    for (int i = 1; i <= n + 1; i ++)
        for (int j = 1; j <= n + 1; j ++)
            dp[i][j] = oo;

    dp[n+1][n+1] = dp[n][n+1] = dp[n+1][n] = 0;

    for (int i = n + 1; i >= 1; i --)
        for (int j = n + 1; j >= 1; j --){
            if ( i == j ) continue;

            if ( i > j ){
                if ( i == j + 1 )
                    for (int k = i + 1; k <= n + 1; k ++)
                        dp[i][j] = min(dp[i][j], dp[i][k] + c[j][k]);
                else dp[i][j] = dp[i][j+1] + c[j][j+1];
            }

            if ( i < j ){
                if ( i + 1 == j )
                    for (int k = j + 1; k <= n + 1; k ++)
                        dp[i][j] = min(dp[i][j], dp[k][j] + c[i][k]);
                else dp[i][j] = dp[i+1][j] + c[i][i+1];
            }
        }

    ans = dp[1][n+1];

    for (int i = 3; i <= n + 1; i ++)
        ans = min({ans, dp[2][i] + c[1][2] + c[1][i], dp[i][2] + c[1][2] + c[1][i]});

    cout << ans;

    return 0;
}
