#include<bits/stdc++.h>
#define simon "minesweeper"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n;
string s;
long long dp[N][5];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int main(){
    file();
    cin >> s;
    n = s.size();
    s = ' ' + s;

    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= 4; j ++)
            dp[i][j] = 0;

    // 0 la so 0
    // 1 la so 1 va bom o trai
    // 2 la so 1 va bom o phai
    // 3 la so 2
    // 4 la bom

    if ( s[1] == '?' ) dp[1][4] = dp[1][0] = dp[1][2] = 1;
    if ( s[1] == '1' ) dp[1][2] = 1;
    if ( s[1] == '0' ) dp[1][0] = 1;
    if ( s[1] == '*' ) dp[1][4] = 1;

    for (int i = 2; i <= n; i ++){
        if ( s[i] == '?' ){
            dp[i][0] = ( dp[i-1][1] + dp[i-1][0] ) % MOD;
            dp[i][1] = dp[i-1][4] % MOD;
            dp[i][2] = (dp[i-1][0] + dp[i-1][1] ) % MOD;
            dp[i][3] = dp[i-1][4] % MOD;
            dp[i][4] = ( dp[i-1][4] + dp[i-1][2] + dp[i-1][3] ) % MOD;
        }

        if ( s[i] == '1' ){
            dp[i][1] = dp[i-1][4] % MOD;
            dp[i][2] = ( dp[i-1][0] + dp[i-1][1] ) % MOD;
        }

        if ( s[i] == '2' ){
            dp[i][3] = dp[i-1][4] % MOD;
        }

        if ( s[i] == '0' ){
            dp[i][0] = ( dp[i-1][1] + dp[i-1][0] ) % MOD;
        }

        if ( s[i] == '*' ){
            dp[i][4] = ( dp[i-1][4] + dp[i-1][2] + dp[i-1][3] ) % MOD;
        }

    }

    long long ans = ( dp[n][0] + dp[n][1] + dp[n][4] ) % MOD;

    cout << ans;

    return 0;
}
