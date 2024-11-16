#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e9;

int n, m, w, b;
int g[N][N], f[N][N];
vector<int> adj[N], ad[N];

void dfs(int u, int v){
    if ( g[u][v] != -1 ) return;
    g[u][v] = 0;
    for (int x : adj[u]) dfs(x, v), g[u][v] |= ( 1 - g[x][v] );
    for (int x : ad[v]) dfs(u, x), g[u][v] |= ( 1 - g[u][x] );
}

int get(int u, int v){
    if ( f[u][v] != -1 ) return f[u][v];
    f[u][v] = ( g[u][v] ? oo : 0 );

    for (int x : adj[u]){
        if ( g[u][v] && !g[x][v] ) f[u][v] = min(get(x, v) + 1, f[u][v]);
        if ( !g[u][v] && g[x][v] ) f[u][v] = max(get(x, v) + 1, f[u][v]);
    }

    for (int x : ad[v]){
        if ( g[u][v] && !g[u][x] ) f[u][v] = min(get(u, x) + 1, f[u][v]);
        if ( !g[u][v] && g[u][x] ) f[u][v] = max(get(u, x) + 1, f[u][v]);
    }

    return f[u][v];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> w >> b;

    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        ad[v].pb(u);
    }

    memset(g, -1, sizeof g);
    memset(f, -1, sizeof f);

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dfs(i, j);

    cout << get(w, b);

    return 0;
}
