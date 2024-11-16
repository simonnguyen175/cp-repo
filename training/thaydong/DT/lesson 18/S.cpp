#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 18; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 18; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i ++)
        cin >> a[i];

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int j = 1; j <= 18; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1; i <= m; i ++){
        int j = i;
        while ( j < m && a[j+1] == a[i] )
            j ++;
        cont.insert({i, j});
        j --;
    }

    cin >> q;
    while ( q -- ){
        char type;
        cin >> type;

        if ( type == t ){
            int l, r, u;
            cin >> l >> r >> u;

        }
    }

    return 0;
}
