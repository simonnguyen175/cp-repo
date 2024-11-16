#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const ll oo = 1e15;

int n, m, d;
ll a[N], b[N], p[N];
string s;
ll dp[N][N][15];
struct btk{
    int i, j, t;
    char x;
} trace[N][N][15];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> d;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    cin >> s;
    s = ' ' + s;
    int k = 0;
    p[1] = 0;
    for (int i = 2; i <= m; i ++){
        while ( k > 0 && s[k+1] != s[i] )
            k = p[k];
        if ( s[k+1] == s[i] ) k ++;
        p[i] = k;
    }

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
    for (int t = 0; t <= m; t ++)
        dp[i][j][t] = -oo;

    if ( s[1] == 'R' ){
        if ( m == 1 ) dp[1][1][1] = -a[1] + d;
        else dp[1][1][1] = -a[1];
        dp[1][0][0] = -b[1];
    }
    else{
        if ( m == 1 ) dp[1][0][1] = -b[1] + d;
        else dp[1][0][1] = -b[1];
        dp[1][1][0] = -a[1];
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= i; j ++)
    for (int t = 0; t <= m; t ++) if ( dp[i][j][t] != -oo ){
//        cout << i << ' ' << j << ' ' << t << ' ' << dp[i][j][t] << '\n';
        int pre;
        if ( t ){
            if ( s[t] == 'R' ) pre = 0;
            else pre = 1;
        }
        else{
            if ( s[1] == 'R' ) pre = 1;
            else pre = 0;
        }
//        cout << pre << '\n';

        /// red
        int cur = t;
        while ( cur && s[cur+1] != 'R' ) cur = p[k];
        if ( s[cur+1] == 'R' ) cur ++;

        if ( cur == m ){
            if ( dp[i+1][j+1][cur] < dp[i][j][t] - a[j+1] + a[j] + d ){
                dp[i+1][j+1][cur] = dp[i][j][t] - a[j+1] + a[j] + d;
                trace[i+1][j+1][cur] = {i, j, t, 'R'};
            }
        }
        else{
            if ( dp[i+1][j+1][cur] < dp[i][j][t] - a[j+1] + a[j] ){
                dp[i+1][j+1][cur] = dp[i][j][t] - a[j+1] + a[j];
                trace[i+1][j+1][cur] = {i, j, t, 'R'};
            }
        }

        /// blue
        cur = t;
        while ( cur && s[cur+1] != 'B' ) cur = p[k];
        if ( s[cur+1] == 'B' ) cur ++;

        if ( cur == m ){
            if ( dp[i+1][j][cur] < dp[i][j][t] - b[i-j+1] + b[i-j] + d ){
                dp[i+1][j][cur] = dp[i][j][t] - b[i-j+1] + b[i-j] + d;
                trace[i+1][j][cur] = {i, j, t, 'B'};
            }
        }
        else{
            if ( dp[i+1][j][cur] < dp[i][j][t] - b[i-j+1] + b[i-j] ){
                dp[i+1][j][cur] = dp[i][j][t] - b[i-j+1] + b[i-j];
                trace[i+1][j][cur] = {i, j, t, 'B'};
            }
        }
    }

    ll ans = -oo;
    int ci, cj, ct;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= m; j ++){
        if ( ans <= dp[n][i][j] ){
            ci = n, cj = i, ct = j;
            ans = dp[n][i][j];
        }
    }

    cout << ans << '\n';

    /// trace
    string res = "";
    while ( ci > 1 ){
        btk tmp = trace[ci][cj][ct];
        res += tmp.x;
        ci = tmp.i, cj = tmp.j, ct = tmp.t;
    }

    if ( cj == 1 ) res += 'R';
    else res += 'B';

    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}
