#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 5;
const int M = 1e4 + 5;

int n, x, y;
pi a[N], dp[N][M];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n, [&](pi x, pi y){
        return x.se < y.se;
    });
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= x; j ++)
        dp[i][j] = {-1, -1};

    int ans = 0;
    dp[0][0] = {0, y};
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= x; j ++) if ( dp[i][j].fi != -1 ){
        ans = max(ans, dp[i][j].fi);
        if ( i == n ) continue;

        // pick fi
        if ( j + a[i+1].fi <= x ){
            int nj = j+a[i+1].fi;
            if ( dp[i+1][nj].fi < dp[i][j].fi + 1 ){
                dp[i+1][nj] = {dp[i][j].fi + 1, dp[i][j].se};
            }
            else if ( dp[i+1][nj].fi == dp[i][j].fi + 1 )
            if ( dp[i+1][nj].se < dp[i][j].se )
                dp[i+1][nj].se = dp[i][j].se;
        }

        // pick se
        if ( dp[i][j].se >= a[i+1].se ){
            if ( dp[i+1][j].fi < dp[i][j].fi + 1 )
                dp[i+1][j] = {dp[i][j].fi + 1, dp[i][j].se - a[i+1].se};
            else if ( dp[i+1][j].fi == dp[i][j].fi + 1 )
            if ( dp[i+1][j].se < dp[i][j].se - a[i+1].se )
                dp[i+1][j].se = dp[i][j].se - a[i+1].se;
        }

        // pick none
        if ( dp[i+1][j].fi < dp[i][j].fi ) dp[i+1][j] = dp[i][j];
        else if ( dp[i+1][j].fi == dp[i][j].fi )
        if ( dp[i+1][j].se < dp[i+1][j].se ) dp[i+1][j].se = dp[i][j].se;
    }

    cout << ans;

    return 0;
}
