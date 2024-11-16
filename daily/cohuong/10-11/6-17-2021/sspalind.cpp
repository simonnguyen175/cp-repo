#include<bits/stdc++.h>
#define simon "sspalind"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e3 + 5;

string s;
int n, dp[N][N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void init(){
    cin >> s;
    s = ' ' + s;
    n = s.size();
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++)
        dp[i][i] = 1;
}

void solve(){
    int ans = 1;
    for (int i = n; i >= 1; i --)
        for (int j = i + 1; j <= n; j ++){
            if ( s[i] == s[j] )
                dp[i][j] = max({dp[i+1][j-1] + 2, dp[i+1][j], dp[i][j-1]});
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            ans = max(ans, dp[i][j]);
        }
    cout << ans;
}

int main(){
    file();
    init();
    solve();
    return 0;
}
