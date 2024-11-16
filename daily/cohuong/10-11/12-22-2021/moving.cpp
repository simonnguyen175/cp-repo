#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int K = 5e3 + 5;
const long long oo = 1e15;

int t, n, m, k;
int s[K], f[K];
long long c[N][N], dp[K][5];

void solve(){
    cin >> n >> m >> k;

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        if ( i != j ) c[i][j] = oo;
        else c[i][j] = 0;

    for (int i = 1; i <= m; i ++){
        int u, v; long long w; cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
        c[v][u] = min(c[v][u], w);
    }

    for (int l = 1; l <= n; l ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if ( c[i][j] > c[i][l] + c[l][j] )
            c[i][j] = c[i][l] + c[l][j];

    for (int i = 1; i <= k; i ++)
        cin >> s[i] >> f[i];

    for (int i = 0; i <= k; i ++)
    for (int j = 0; j <= 3; j ++)
        dp[i][j] = oo;

    dp[1][1] = c[1][s[1]];
    dp[1][0] = dp[1][1] + c[s[1]][f[1]];
    // dp[i][0] den don i hien tai ko con don nao da giao xong don i
    // dp[i][1] den don i hien tai con don i dang o vi tri s[i]
    // dp[i][2] den don i hien tai con don i dang o vi tri f[i-1]
    // dp[i][3] den don i hien tai con don i va don i - 1

    for (int i = 2; i <= k; i ++){
        dp[i][3] = min({dp[i][3], dp[i-1][1] + c[s[i-1]][s[i]], dp[i-1][2] + c[f[i-2]][s[i]]});
        dp[i][2] = min(dp[i][2], dp[i][3] + c[s[i]][f[i-1]]);
        dp[i][1] = min(dp[i][1], dp[i-1][0] + c[f[i-1]][s[i]]);
        dp[i][0] = min({dp[i][0], dp[i][1] + c[s[i]][f[i]], dp[i][2] + c[f[i-1]][f[i]]});
    }

    if ( dp[k][0] != oo )
        cout << dp[k][0] << '\n';
    else cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("moving.in", "r") ){
        freopen("moving.in", "r", stdin);
        freopen("moving.out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
