#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int K = 650;
const int MOD = 1e9 + 7;

int n, q, s;
int dp[K][N], ans = 0;

int mul(int a,int b){
    return 1LL * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> q;

    dp[0][0] = 1;

    for (int i = 0; i < K; i ++)
    for (int j = 0; j < N; j ++){
        if ( i > 0 && j > n )
            dp[i][j] = add(dp[i][j], -mul(2, dp[i-1][j-n-1]));

        if ( i > 1 && j > 2 * n + 1 )
            dp[i][j] = add(dp[i][j], -dp[i-2][j-2*n-2]);

        if ( i > 0 && j + i < N )
            dp[i][j+i] = add(dp[i][j+i], dp[i][j]);

        if ( j + i + 1 < N && i + 1 < K )
            dp[i+1][j+i+1] = add(dp[i+1][j+i+1], mul(2, dp[i][j]));

        if ( j + i + 2 < N && i + 2 < K )
            dp[i+2][j+i+2] = add(dp[i+2][j+i+2], dp[i][j]);
    }


    while ( q -- ){
        cin >> s;
        ans = 0;
        for (int i = 0; i < K; i ++)
            ans = add(ans, dp[i][s]);
        cout << ans << '\n';
    }

    return 0;
}
