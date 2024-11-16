#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

int n, a[N], dp[N][N];

int main(){
	ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
    if ( fopen("cashier.inp", "r") ){
        freopen("cashier.inp", "r", stdin);
        freopen("cashier.out", "w", stdout);
    }

	cin >> n;
    for(int i = 1; i <= n; i ++)
		cin >> a[i];

	memset(dp, 0x3f, sizeof dp);
    dp[0][0]=0;

    for(int i = 0;i < n; i ++){
    	for(int j = 0;j<=i;j++){
    		dp[i+1][i+1] = min(dp[i+1][i+1],dp[i][0]);
    		dp[i+2][j] = min(dp[i+2][j], dp[i][j] + max(a[i+1], a[i+2]));
    		if( j != 0 ){
                dp[i+1][0] = min(dp[i+1][0], dp[i][j] + max(a[j] , a[i+1]));
                dp[i+2][i+1] = min(dp[i+2][i+1], dp[i][j] + max(a[j], a[i+2]));
                dp[i+2][i+2] = min(dp[i+2][i+2], dp[i][j] + max(a[j], a[i+1]));
            }
		}
	}

	for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= i; j ++)
            cout << i << ' ' << j << ' ' << dp[i][j] << '\n';

	int res=1e9;
	for(int i = 0; i <= n; i ++){
        if ( i > 0 && !( n % 2 ) ) continue;
        res = min(res, dp[n][i] + a[i]);
    }

    cout << res;
	return 0;
}

