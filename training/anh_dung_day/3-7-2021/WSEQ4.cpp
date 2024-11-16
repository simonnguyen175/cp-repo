#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo=1e15;

int n, m, k;
ll a[401], dp[2][401][401], ans=oo;

int main(){
    //freopen("WSEQ4.inp","r",stdin);
    //freopen("WSEQ4.out","w",stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

    //khoitao
	for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				for (int t = 0; t <= m; t++)
					dp[i%2][j][t] = oo;
	for (int i=0; i<=m; i++)
        dp[0][i][0]=0;

	//DP
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= min(m,i); j++)
			for (int t = 0; t <= j; t++){
                if ( i == j ){
                    if ( t == 0 )
                        dp[i%2][j][t]=dp[(i-1)%2][j-1][t]+a[i];
                    else
                        dp[i%2][j][t]=min(dp[(i-1)%2][j-1][t-1], dp[(i-1)%2][j-1][t]+a[i]);
                    continue;
                }
                if ( j == 0 ){
                    dp[i%2][j][t] = dp[(i-1)%2][j][t]+ ( i%k ? a[i] : 0 );
                    continue;
                }
                if ( t == 0 ){
                    dp[i%2][j][t] = min(dp[(i-1)%2][j][t] + ((i-j)%k ? a[i] : 0), dp[(i-1)%2][j-1][t]+a[i]);
                    continue;
                }
                dp[i%2][j][t] = min(min(dp[(i-1)%2][j-1][t-1], dp[(i-1)%2][j-1][t]+a[i]), dp[(i-1)%2][j][t]+((i-j)%k ? a[i] : 0));
			}
	for (int j = 0; j <= m; j++)
		ans = min (ans, dp[n%2][j][n/k-(n-j)/k]);
	cout << ans;
	return 0;
}
