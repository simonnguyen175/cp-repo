#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int  N=1e3+1;

ll m, n, k, a[N], b[N], dp[N][N];

int main(){
    cin >> m >> n >> k;
    for(int i = 1; i<=m; ++i)
        cin >> a[i];
    for(int i = 1; i<=n; ++i)
        cin >> b[i];
    for(int i=0; i<=m; ++i)
        for(int j=0; j <= n; ++j)
            dp[i][j]=LLONG_MAX;
    dp[0][0]=0;
    for(int i=1; i<=m; i++)
        if ( i % k == 0 ) dp[i][0]=dp[i-1][0];
        else dp[i][0]=dp[i-1][0]+a[i];
    for(int i=1; i<=n; i++)
        if ( i % k == 0 ) dp[0][i]=dp[0][i-1];
        else dp[0][i]=dp[0][i-1]+b[i];
    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j)
            if( ( i + j ) % k == 0 )
                dp[i][j]=min(dp[i-1][j], dp[i][j-1]);
            else
                dp[i][j]=min(dp[i-1][j]+a[i], dp[i][j-1]+b[j]);
    cout << dp[m][n];
    return 0;
}
