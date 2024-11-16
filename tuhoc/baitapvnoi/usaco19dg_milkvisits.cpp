#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m;
int t[N], h[N], p[N][21], a[N], b[N], c[N];
vector<int> adj[N], que[N], col[N];
bool ok[N];

void dfs1(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs1(v, u);
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

void dfs2(int u, int pu){
    col[t[u]].pb(u);

    for (int id : que[u]) if ( col[c[id]].size() ){
        int x = col[c[id]].back();
//        cout << u << ' ' << id << ' ' << x << '\n';
        if ( h[x] <= h[u] && h[x] >= h[lca(a[id], b[id])] )
            ok[id] = 1;
    }

    for (int v : adj[u]) if ( v != pu )
        dfs2(v, u);

    col[t[u]].pop_back();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("usaco19dg_milkvisits.inp", "r") ){
        freopen("usaco19dg_milkvisits.inp", "r", stdin);
        freopen("usaco19dg_milkvisits.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> t[i];
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 0;
    dfs1(1, 0);

    for (int i = 1; i <= 20; i ++)
    for (int u = 1; u <= n; u ++)
        p[u][i] = p[p[u][i-1]][i-1];

    for (int i = 1; i <= m; i ++){
        cin >> a[i] >> b[i] >> c[i];
        que[a[i]].pb(i);
        if ( b[i] != a[i] ) que[b[i]].pb(i);
    }
//
//    for (int i = 1; i <= n; i ++){
//        cout << i << " : \n";
//        for (int id : que[i]) cout << id << ' ';
//        cout << '\n';
//    }

    dfs2(1, 0);

    for (int i = 1; i <= m; i ++) cout << ok[i];

    return 0;
}
