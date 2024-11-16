#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 2e5 + 5;

int n;
int a[N], d[N], p[N][22];

void dfs(int u, int pu){
    for (int i =  1; i <= 20; i ++)
        p[u][i] = p[p[u][i-1]][i-1];
    for (int v : adj[u]){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( d[u] < d[v] ) swap(u, v);
    int diff = d[u] - d[v];
    for (int i = 0; i <= 20; i ++)
        if ( BIT(diff, i) )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 1; i --)
        if ( p[u][i] != p[v][i] ){
            u = p[u][i];
            v = p[v][i];
        }

    return p[u][0];
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++)
        edges.pb({i, j, a[i]+a[j]+d[i]+d[j]-2*d[lca(i, j)]})

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n*(n-1)/2; i ++){
        int u, v; ll w;
        u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if ( Join(u, v) ) ans += w;
    }

    cout << ans;

    return 0;
}
