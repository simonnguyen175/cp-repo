#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, m;
int dp[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    dp[0][n] = 1;
    for (int i = 1; i <= m; i ++)
    for (int j = 0; j < n; j ++)
    for (int k = j+1; k <= n; k ++)
        if ( !j ){
            dp[i][j] = add(dp[i][j], dp[i-n][k]);
        else dp[i][j] = add(dp[i][j], mul(dp[i-(n-j)][k], k-j+1));

    cout << dp[m][0];

    return 0;
}
