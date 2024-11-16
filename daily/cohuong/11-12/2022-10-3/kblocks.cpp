#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e16;

int n, k;
int a[N];
ll dp[105][105];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	if ( fopen("kblocks.inp", "r") ){
	   freopen("kblocks.inp", "r", stdin);
	   freopen("kblocks.out", "w", stdout);
	}

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= k; j ++)
        dp[i][j] = oo;

    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= k; j ++){
        int mx = 0;
        for (int t = i; t >= 1; t --){
            mx = max(mx, a[t]);
            dp[i][j] = min(dp[i][j], dp[t-1][j-1] + mx);
        }
    }

    cout << dp[n][k];

    return 0;
}
