#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll oo=-1e18;

int n, k;
ll a[1001][1001], dp[1001][1001][51] ;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    freopen("grid.inp","r",stdin);
    freopen("grid.out","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            for (int t=0; t<=k; t++)
                dp[i][j][t]==oo;
    if ( a[1][1] >= 0 ) dp[1][1][0]=a[1][1];
    else dp[1][1][1]=a[1][1];
    // di ngang
    for (int j=2; j<=n; j++)
        for (int t=0; t<=k; t++){
            if ( a[1][j] >= 0 ){
                if ( dp[1][j-1][t] != oo )
                    dp[1][j][t]=a[1][j]+dp[1][j-1][t];
            }
            if ( a[1][j] < 0 ){
                if ( t == 0 ) continue;
                if ( dp[1][j-1][t-1] != oo)
                    dp[1][j][t]=a[1][j]+dp[1][j-1][t-1];
            }
        }
    // cot 1
    for (int i=2; i<=n; i++)
        for (int t=0; t<=k; t++){
            if ( a[i][1] >= 0 ){
                if ( dp[i-1][1][t] != oo )
                    dp[i][1][t]=a[i][1]+dp[i-1][1][t];
            }
            if ( a[i][1] < 0 ){
                if ( t == 0 ) continue;
                if ( dp[i-1][1][t-1] != oo )
                    dp[i][1][t]=a[i][1]+dp[i-1][1][t-1];
            }
        }
    for (int i=2; i<=n; i++)
        for (int j=2; j<=n; j++)
            for (int t=0; t<=k; t++){
                if ( a[i][j] < 0 ){
                    if ( t == 0 ) continue;
                    if ( dp[i-1][j][t-1] == oo && dp[i][j-1][t-1] == oo ) continue;
                    dp[i][j][t]=max(dp[i-1][j][t-1]+a[i][j], dp[i][j-1][t-1]+a[i][j]);

                }
                else{
                    if ( dp[i-1][j][t] == oo && dp[i][j-1][t] == oo ) continue;
                    dp[i][j][t]=max(dp[i-1][j][t]+a[i][j], dp[i][j-1][t]+a[i][j]);
                }
            }
    ll ans=oo;
    for (int i=0; i<=k; i++)
        if ( dp[n][n][i] > ans ) ans=dp[n][n][i];
    if ( ans == oo ) cout <<"NO";
    else cout << ans;
    return 0;
}

