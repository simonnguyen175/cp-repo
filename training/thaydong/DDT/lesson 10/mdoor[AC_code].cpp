#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e18;

int m, n;
ll C, w[N][N];
bool isdoor[N][N];

namespace sub2{
    ll ans = -oo, dp[N][N];

    void solve(){
        for (int i = 1 ; i <= m; i++)
            dp[i][0] = dp[i][n+1] = -oo;
        for (int i = 1 ; i <= m; i++)
            for (int j = 1 ; j <= n; j++)
                dp[i][j] = max({dp[i - 1][j] , dp[i - 1][j + 1] , dp[i - 1][j - 1]}) + w[i][j];
        for (int i = 1; i <= n; i++) ans = max(ans, dp[m][i]);
        cout << ans;
    }
}

namespace sub3{
    ll dp[33][N][N], g[33], ans;

    void solve(){
        memset(dp, -0x3f, sizeof(dp));
        memset(g, -0x3f, sizeof(g));

        for(int i=1; i<=n; i++) dp[0][1][i] = w[1][i];

        for(int i=2; i<=m; i++)
            for(int j=1; j<=n; j++){
                dp[0][i][j] = max( { dp[0][i-1][j-1], dp[0][i-1][j], dp[0][i-1][j+1] } ) + w[i][j];
                if( isdoor[i][j] ) g[0] = max(g[0], dp[0][i][j]);
            }

        for(int t=1; t<=C; t++)
            for(int i=1; i<=m; i++)
                for(int j=1; j<=n; j++){
                    dp[t][i][j] = max( { dp[t][i-1][j-1], dp[t][i-1][j], dp[t][i-1][j+1] } ) + w[i][j];
                    if( isdoor[i][j] ){
                        dp[t][i][j] = max(dp[t][i][j], g[t-1] + w[i][j]);
                        g[t] = max(g[t], dp[t][i][j]);
                    }
                }

        ans = -oo;
        for(int t=0; t<=C; t++)
            for(int i=1; i<=n; i++)
                ans = max(ans, dp[t][m][i]);
        cout << ans;
    }
}

namespace sub4{
    ll dp[N][N], x, y, z;

    void solve(){
        x = -oo; y = -oo; z = -oo;

        memset(dp, -0x3f, sizeof(dp));

        for(int i = 1; i <= n; i++) dp[1][i] = w[1][i];

        for(int i = 2; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + w[i][j];

        for(int i = 1; i <=m; i ++)
            for(int j = 1; j <= n; j ++)
                if( isdoor[i][j] ) x = max(x, dp[i][j]);

        memset(dp, -0x3f, sizeof(dp));

        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j ++){
                dp[i][j] = max({dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]}) + w[i][j];
                if( isdoor[i][j] ) dp[i][j] = max(dp[i][j], w[i][j]);
            }

        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j ++)
                if( isdoor[i][j] ) y = max(y, dp[i][j]);

        memset(dp, -0x3f, sizeof(dp));

        for(int i = 1; i <= n; i ++) dp[m][i] = w[m][i];

        for(int i = m - 1; i >= 1; i --)
            for(int j = 1; j <= n; j ++)
                dp[i][j] = max({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]} ) + w[i][j];

        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j ++)
                if( isdoor[i][j] ) z = max(z, dp[i][j]);

        cout << x + (C-1)*y + z;
    }
}

int main(){
    cin >> m >> n >> C;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            int t; cin >> t;
            if ( t ) isdoor[i][j] = 1;
        }

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> w[i][j];

    if ( C == 0 ) sub2::solve();
        else if ( C <= 30 ) sub3::solve();
            else sub4::solve();

    return 0;
}
