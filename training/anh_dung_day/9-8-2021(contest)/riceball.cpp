#include <bits/stdc++.h>
#define simon "riceball"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 405;

int n, a[N], dp[N][N];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

	cin >> n;

	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		a[i] += a[i-1];
		dp[i][i]=1;
	}

	for (int len = 2; len <= n; len ++){
		for (int i = 1; i <= n-len+1; i ++){
			int j = i + len - 1, r_k = j;
			for (int k = i; k <= j - 1; k ++){
				while( k+1 < r_k && a[j] - a[r_k-1] < a[k] - a[i-1] )
                    r_k --;

				if( k+1 < r_k && a[j] - a[r_k-1] == a[k] - a[i-1] ){
					if( dp[i][k] && dp[r_k][j] && dp[k+1][r_k-1] )
                        dp[i][j] = 1;
				}

				if( a[k] - a[i-1] == a[j] - a[k] ){
					if ( dp[i][k] && dp[k+1][j] )
                        dp[i][j] = 1;
				}
			}
		}
	}

	int ans = 0;

    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)
            if ( dp[i][j] )
                ans = max(ans, a[j] - a[i-1]);

	cout << ans;

	return 0;
}
