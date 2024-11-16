#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, q;
vector<int> adj[N];
int p[N][25], h[N];

void dfs(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= 20; i ++)
    for (int u = 1; u <= n; u ++)
        p[u][i] = p[p[u][i-1]][i-1];


    cin >> q;
    while ( q -- ){
        int u, v; cin >> u >> v;
        int lca_uv = lca(u, v);
        cout << h[u] + h[v] - 2 * h[lca_uv] << '\n';
    }

    return 0;
}
