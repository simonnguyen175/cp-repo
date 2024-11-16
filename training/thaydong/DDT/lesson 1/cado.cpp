#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, k, a[N];
long long dp[N][N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    dp[n+1][1] = 0;
    for (int i = n; i >= 1; i --)
        dp[i][1] = ( dp[i+1][1] + a[i] ) % MOD;

    for (int i = n - 1; i >= 1; i --)
        for (int j = 2; j <= min(n - i + 1, k); j ++)
            dp[i][j] = ( a[i] * (dp[i+1][j-1]) + dp[i+1][j] ) % MOD;

    cout << dp[1][k];

    return 0;
}
