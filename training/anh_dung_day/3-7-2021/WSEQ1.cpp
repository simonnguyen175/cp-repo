#include <bits/stdc++.h>
using namespace std;
const int N=2001;
const long long oo=1e15;

int n, m, k;
int a[N];
long long dp[N][N];

int main(){
    //freopen("WSEQ1.inp","r",stdin);
    //freopen("WSEQ1.out","w",stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    long long ans= oo;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j]=oo;
    dp[0][0]=0;
    for (int i=1; i<=n; i++)
        for (int j=0; j<=i; j++){
            if ( j == 0 ) dp[i][j]= dp[i-1][j];
            else{
                if ( j % k == 0 )
                    dp[i][j]=min(dp[i-1][j-1], dp[i-1][j]);
                else
                    dp[i][j]=min(dp[i-1][j-1]+a[i], dp[i-1][j]);
            }
           // cout << i <<' ' <<j <<' '<<dp[i][j]<<'\n';
        }
    for (int i=0; i<=n; i++){
        if ( n - i > m ) continue;
        ans=min(ans, dp[n][i]);
    }
    cout << ans;
    return 0;
}
