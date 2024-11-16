#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 5;
const ll oo = 1e15;

int t, n, m;
ll c[N][N], s[N][N], dp[N][N], ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("sweet.in", "r") ){
        freopen("sweet.in", "r", stdin);
        freopen("sweet.out", "w", stdout);
    }

    cin >> t;

    while ( t -- ){
        cin >> n >> m;

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> c[i][j];

        for (int i = 1; i <= n; i ++)
            sort(c[i] + 1, c[i] + 1 + m);

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            s[i][j] = s[i][j-1] + c[i][j];

        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            dp[i][j] = oo;

        dp[0][0] = 0;
        for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
        for (int k = 0; k <= min(m, n - j); k ++)
            dp[i+1][j+k-1] = min(dp[i+1][j+k-1], dp[i][j] + s[i+1][k] + k * k);

        ans = oo;

        for (int i = 0; i <= n; i ++)
            ans = min(ans, dp[n][i]);

        cout << ( ans == oo ? -1 : ans ) << '\n';
    }

    return 0;
}
