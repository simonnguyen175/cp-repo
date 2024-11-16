#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N];
ll dp[N][3][2], f[N][3][2];
vector<int> adj[N];

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu )
        dfs(v, u);

    /// dp(u, 1/2, 0/1) so duong di, 1 trong 2 duong di co the tiep dien
    /// f la mang phu

    /// xuoi
    f[u][1][1] = f[u][1][0] = a[u];
    f[u][2][0] = f[u][2][1] = 0;
    ll mxv = 0;
    for (int i = 0; i < adj[u].size(); i ++){
        int v = adj[u][i];
        if ( v == pu ) continue;

        f[u][2][0] = max({f[u][2][0], f[v][2][0], f[u][1][0] + dp[v][1][0], f[u][2][1] + dp[v][1][1], f[u][1][1] + dp[v][2][1]});
        f[u][2][1] = max({f[u][2][1], dp[v][2][1] + a[u], f[u][1][1] + max(dp[v][1][0], dp[v][1][1]), mxv + dp[v][1][1] + a[u]});

        mxv = max({mxv, dp[v][1][0], dp[v][1][1]});
        f[u][1][0] = max({f[u][1][0], dp[v][1][0], dp[v][1][1] + a[u], f[u][1][1] + dp[v][1][1]});
        f[u][1][1] = max({f[u][1][1], dp[v][1][1] + a[u]});
    }

    for (int i = 1; i <= 2; i ++)
    for (int j = 0; j <= 1; j ++)
        dp[u][i][j] = max(dp[u][i][j], f[u][i][j]);

    /// nguoc
    f[u][1][1] = f[u][1][0] = a[u];
    f[u][2][0] = f[u][2][1] = 0;
    mxv = 0;
    for (int i = adj[u].size()-1; i >= 0; i --){
        int v = adj[u][i];
        if ( v == pu ) continue;

        f[u][2][0] = max({f[u][2][0], f[v][2][0], f[u][1][0] + dp[v][1][0], f[u][2][1] + dp[v][1][1], f[u][1][1] + dp[v][2][1]});
        f[u][2][1] = max({f[u][2][1], dp[v][2][1] + a[u], f[u][1][1] + max(dp[v][1][0], dp[v][1][1]), mxv + dp[v][1][1] + a[u]});

        mxv = max({mxv, dp[v][1][0], dp[v][1][1]});
        f[u][1][0] = max({f[u][1][0], dp[v][1][0], dp[v][1][1] + a[u], f[u][1][1] + dp[v][1][1]});
        f[u][1][1] = max({f[u][1][1], dp[v][1][1] + a[u]});
    }
    for (int i = 1; i <= 2; i ++)
    for (int j = 0; j <= 1; j ++)
        dp[u][i][j] = max(dp[u][i][j], f[u][i][j]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("trash.inp", "r") ){
//        freopen("trash.inp", "r", stdin);
//        freopen("trash.out", "w", stdout);
//    }

    cin >> n;
    ll s = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s += a[i];

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    cout << max(dp[1][2][0], dp[1][2][1]);

    return 0;
}


