#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long MOD = 1e9;

int n, k;
long long dp[N][2];

int main(){
    cin >> n >> k;
    dp[0][0] = dp[0][1] = 1;
    dp[1][0] = dp[1][1] = 1;

    for (int i = 2; i <= k; i ++){
        dp[i][0] = ( dp[i-1][0] + dp[i-1][1] ) % MOD;
        dp[i][1] = ( dp[i-1][0] + dp[i-1][1] ) % MOD;
    }

    for (int i = k + 1; i <= n; i ++){
        dp[i][0] = ( dp[i-1][0] + dp[i-1][1] - dp[i-k-1][1] + MOD * MOD ) % MOD;
        dp[i][1] = ( dp[i-1][0] + dp[i-1][1] - dp[i-k-1][0] + MOD * MOD ) % MOD;
    }

    cout << ( dp[n][0] + dp[n][1] ) % MOD;

    return 0;
}
