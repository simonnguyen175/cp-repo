#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;

namespace sub1{
	ll dp[1005][1005];
	void solve(){
		dp[0][0] = 1;
		for (int i = 0; i <= n; i ++){
			for (int j = 1; j <= n; j ++){
				dp[i][j] = dp[i][j-1];
				if ( j <= i )
                    dp[i][j] = (dp[i][j] + dp[i-j][max(j-2, 0)]) % MOD;
			}
		}
		cout << dp[n][n];
	}
}

namespace sub2{
    ll f[N][400];

    void solve(){

        f[0][0] = 1;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= sqrt(i); j ++){
                // a[1] = 1
                if ( i-1 >= 2*(j-1) )
                (f[i][j] += f[i-1-2*(j-1)][j-1]) %= MOD;
                // a[1] > 1
                (f[i][j] += f[i-j][j]) %= MOD;
            }

        ll ans = 0;
        for (int i = 1; i <= sqrt(n); i ++)
            ( ans += f[n][i] ) %= MOD;

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;

    //if ( n <= 1000 ) sub1::solve();
    //else
        sub2::solve();

    return 0;
}
