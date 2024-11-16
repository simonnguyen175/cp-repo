#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        mn[v][0] = w;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges+1, edges+1+m, [](edges a, edges b){
        return a.w < b.w;
    });

    for (int i = 1; i <= n; i ++)
        if ( Join(edges[i].u, edges[i].v) ){
            adj[edges[i].u].pb({edges[i].v, edges[i].w});
            adj[edges[i].v].pb({edges[i].u, edges[i].w});
        }

    h[1] = 1;
    dfs(1, 0);

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++){
        p[i][j] = p[p[i][j-1]][j-1];
        mn[i][j] = min(mn[i][j-1], mn[p[i][j-1]][j-1]);
    }




    return 0;
}
