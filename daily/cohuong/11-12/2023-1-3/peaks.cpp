#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 239;

int n, k;
int dp[N][35];

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("peaks.inp", "r", stdin);
    freopen("peaks.out", "w", stdout);

    cin >> n >> k;
    dp[0][0] = 1;

    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= k; j ++) if ( dp[i][j] )
        if ( j )
            add(dp[i+1][j], mul(dp[i][j], 2 * j));
        if ( j + 1 <= k )
            add(dp[i+1][j+1], mul(dp[i][j], i + 1 - 2 * j));
    }

    cout << dp[n][k];

    return 0;
}
