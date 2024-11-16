#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;

int n, x;
int a[N], dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    memset(dp, -1, sizeof dp);
    dp[0][x] = 1e9;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= x; j ++){
        if ( j + a[i] <= x ) dp[i][j] = max(dp[i][j], dp[i-1][j+a[i]]);
        dp[i][j] = max(dp[i][j], min(dp[i-1][j], a[i]));
    }

    int ans = 0;
    for (int i = 0; i <= x; i ++)
        if ( dp[n][i] > i ) ans = i;

    cout << ans << '\n';

    return 0;
}
