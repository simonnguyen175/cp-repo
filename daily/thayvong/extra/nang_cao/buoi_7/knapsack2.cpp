#include <bits/stdc++.h>
using namespace std;

struct dat{
    long long w=0, v=0;
};

dat a[1001];
long long n,m ;
long long dp[101][100001],g[101][100001];
long long res=0;

int main(){
    freopen("Knapsack2.inp","r",stdin);
    freopen("Knapsack2.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m ;
    for(int i = 0; i <= n; i++)
        g[i][0] = 1;
    for(int j = 0; j <= m; j++)
        g[0][j] = 1;

    for (int i=1; i<=n; i++)
        cin >> a[i].w ;
    for (int i=1; i<=n; i++)
        cin >> a[i].v ;
    for (int i=1; i<=n; i++)
        for (int j = 1; j<=m ; j++){
            if ( j < a[i].w ){
                dp[i][j] = dp[i-1][j];
                g[i][j] = g[i-1][j];
            }
            else
                {
                    dp[i][j] = dp[i-1][j];
                    g[i][j]  = g[i-1][j];
                    if ( dp[i][j] < dp[i-1][j-a[i].w] + a[i].v )
                        {
                           g[i][j] = g[i-1][j-a[i].w];
                           dp[i][j] = dp[i-1][j-a[i].w] + a[i].v;
                        }
                    else
                        if ( dp[i][j] == dp[i-1][j-a[i].w]+a[i].v )
                            g[i][j] += g[i-1][j-a[i].w];
                }
        }
    long long dem=0;
    cout << dp[n][m] <<"\n";
    cout << g[n][m];
}
