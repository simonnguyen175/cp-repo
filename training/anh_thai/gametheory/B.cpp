#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int n, m;
int a[N][N], s[N][N];
bool col[N][5], row[N][5], dp[N][N];

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        cin >> a[i][j];
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        s[i][j] = ( s[i][j] % 3 + 3 ) % 3;
    }

    memset(dp, 0, sizeof dp);
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);

    for (int i = 1; i <= n; i ++) col[i][0] = 1;
    for (int i = 1; i <= m; i ++) row[i][0] = 1;

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            int rem = ( s[i][j] + 2 ) % 3;
            if ( col[i][rem] || row[j][rem] ) dp[i][j] = 1;
            col[i][s[i][j]] |= !dp[i][j];
            row[j][s[i][j]] |= !dp[i][j];
        }
    }

    cout << dp[n][m] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    for (int i = 1; i <= 5; i ++)
        solve();

    return 0;
}
