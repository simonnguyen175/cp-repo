#include<bits/stdc++.h>
#define simon "bitonic"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const ll oo = 1e13;

int n;
ll c[N][N], dp[N][N], ans = oo;

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> c[i][j];
}

void solve(){
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dp[i][j] = oo;

    dp[1][1] = 0; dp[1][2] = c[2][1]; dp[2][1] = c[1][2];

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        if ( i == j ) continue;

        if ( i > j ){
            if ( i == j + 1 )
                for (int k = 1; k <= j - 1; k ++)
                    dp[i][j] = min(dp[i][j], dp[k][j] + c[k][i]);
            else dp[i][j] = dp[i-1][j] + c[i-1][i];
        }

        if ( i < j ){
            if ( j == i + 1 )
                for (int k = 1; k <= i - 1; k ++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + c[j][k]);
            else dp[i][j] = dp[i][j-1] + c[j][j-1];
        }
     }

     ans = oo;

     for (int i = 2; i <= n - 2; i ++)
        ans = min({ans, dp[n-1][i] + c[n-1][n] + c[n][i], dp[i][n-1] + c[i][n] + c[n][n-1]});

    cout << ans;
}


int main(){
    file();
    init();
    solve();
    return 0;
}
