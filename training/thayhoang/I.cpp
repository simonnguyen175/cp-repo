#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k, g1, g2, g3;
char a[N];
int dp[N][55];

void ckmx(int &a, int b){
    if ( a == -1 ) a = b;
    else if ( a < b ) a = b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> k >> g1 >> g2 >> g3;

    int rks = 0, dots = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if ( a[i] == '#' ) rks ++;
        else dots ++;
    }

    memset(dp, -1, sizeof dp);

    dp[0][0] = 0;
    int ans = 0;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= rks; j ++) if ( dp[i][j] != -1 ){
        if ( a[i+1] == '.' && a[i+2] == '#' && a[i+3] == '.' )
            ckmx(dp[i+3][j+1], dp[i][j]);
        if ( a[i+1] == '.' && a[i+2] == '.' )
            ckmx(dp[i+2][j], dp[i][j] + 1);
        ckmx(dp[i+1][j], dp[i][j]);
    }

    for (int j = 0; j <= rks; j ++) if ( dp[n][j] != -1 ){
        int cur = j * g3, rem = n - 2 * dp[n + 1][j] - 3 * j - (rks - j),
    		x = k;
    	cur += min(x, rem) * g1;
    	x -= min(x, rem);
    	if (2 * g1 > g2) {
    		int t = x / 2;
    		cur += min(t, dp[n + 1][j]) * 2 * g1;
    		x %= 2;
    		dp[n + 1][j] -= min(dp[n + 1][j], t);
    	}
    	if (x && g1 > g2 && dp[n + 1][j]) cur += g1, dp[n + 1][j]--;
    	cur += dp[n + 1][j] * g2;

        ans = max(ans, cur);
    }

    cout << ans;

    return 0;
}
