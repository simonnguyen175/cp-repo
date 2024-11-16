#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int MOD = 1e9 + 7;

int n, k;
int dp[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    dp[1] = 1;
    // dp[i][j] so cach di chuyen tu 1 -> i buoc nhay den i co do dai la j
    for (int i = 2; i <= n; i ++){
        for (int j = i-1; j >= max(i-3, 1); j --)
            dp[i] = (dp[i] + dp[j]) % MOD; // nhung j co the di chuyen den i
    }
    cout << dp[n];

    return 0;
}
