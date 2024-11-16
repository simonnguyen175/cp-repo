#include<bits/stdc++.h>
#define simon "feed"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 3e3 + 5;

int n, a[N][3], dp[N][2][2];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int main(){
    file();
    cin >> n;
    for (int j = 0; j <= 2; j ++)
        for (int i = 1; i <= n; i ++)
            cin >> a[i][j];

    dp[1][0][0] = dp[1][1][0] = a[1][0];
    dp[1][0][1] = dp[1][1][1] = a[1][1];

    for (int i = 2; i <= n - 1; i ++){
        dp[i][0][0] = max(dp[i-1][0][1], dp[i-1][1][1]) + a[i][0];
        dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][1][1]) + a[i][1];
        dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][1][0]) + a[i][1];
        dp[i][1][1] = max(dp[i-1][0][0], dp[i-1][1][0]) + a[i][2];
    }

    dp[n][0][0] = max(dp[n-1][0][1], dp[n-1][1][1]) + a[n][0];
    dp[n][1][0] = max(dp[n-1][0][0], dp[n-1][1][0]) + a[n][1];

    cout << max(dp[n][0][0], dp[n][1][0]);

    return 0;
}
