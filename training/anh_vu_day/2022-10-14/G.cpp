#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const ll oo = 1e15;

int n;
int a[N], sz[N];
ll f[N][N][2], dp[N][N][2];
vector<int> adj[N];

void ckmn(ll &a, ll b){
    a = min(a, b);
}

// dp[u][i][x] subtree u bo di i canh
// x = 0/1 vung hien tai co may tinh hay ko
// thi min tong vung hien tai bao nhieu

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu )
        dfs(v, u);

    for (int i = 0; i <= adj[u].size(); i ++)
    for (int j = 0; j <= n; j ++)
        f[i][j][0] = f[i][j][1] = oo;

    f[0][0][a[u]<0] = a[u];
    for (int i = 0; i < adj[u].size(); i ++){
        int v = adj[u][i];

        if ( v == pu ){
            for (int j = 0; j <= sz[u]; j ++)
            for (int x = 0; x <= 1; x ++)
                f[i+1][j][x] = f[i][j][x];
            continue;
        }

        for (int j = 0; j <= sz[u]; j ++)
        for (int x = 0; x <= 1; x ++) if ( f[i][j][x] != oo )
        for (int k = 0; k <= sz[v]; k ++)
        for (int y = 0; y <= 1; y ++){
            // cat canh u-v
            if ( dp[v][k][y] < 0 || ( !y && dp[v][k][y] != oo ) )
                ckmn(f[i+1][j+k+1][x], f[i][j][x]);

            // noi canh u-v
            ckmn(f[i+1][j+k][x|y], f[i][j][x] + dp[v][k][y]);
        }

        sz[u] += sz[v] + 1;
    }

    for (int i = 0; i <= sz[u]; i ++)
    for (int x = 0; x <= 1; x ++)
        dp[u][i][x] = f[adj[u].size()][i][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        dp[i][j][0] = dp[i][j][1] = oo;

    dfs(1, 0);

    for (int i = 0; i <= n-1; i ++)
        if ( dp[1][i][1] < 0 || dp[1][i][0] != oo )
            return cout << i, 0;

    return 0;
}
