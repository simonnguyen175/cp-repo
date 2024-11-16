#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 4e3 + 5;

int n, m, q;
int par[N], sz[N], p[N][15], mx[N][15], h[N];
vector<pi> adj[N];
struct edge{
    int u, v, w;
};

int Find(int u){
    if ( u == par[u] ) return u;
    else return par[u] = Find(par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( sz[u] < sz[v] ) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
    return false;
}

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;
        p[v][0] = u;
        mx[v][0] = w;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int get(int u, int v){
    int res = 0;
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 12; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] ){
            res = max(res, mx[u][i]);
            u = p[u][i];
        }

    if ( u == v ) return res;

    for (int i = 12; i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            res = max({res, mx[u][i], mx[v][i]});
            u = p[u][i];
            v = p[v][i];
        }

    return max({res, mx[u][0], mx[v][0]});
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("water.inp", "r") ){
        freopen("water.inp", "r", stdin);
        freopen("water.out", "w", stdout);
    }

    cin >> n >> m;
    vector<edge> edg;
    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        edg.pb({u, v, w});
    }

    sort(edg.begin(), edg.end(), [&](edge a, edge b){
        return a.w < b.w;
    });

    for (int i = 1; i <= n; i ++) par[i] = i, sz[i] = 1;
    ll s = 0;
    for (auto it : edg)
        if ( Join(it.u, it.v) ){
            adj[it.u].pb({it.v, it.w});
            adj[it.v].pb({it.u, it.w});
            s += it.w;
        }

    h[1] = 1;
    dfs(1, 0);
    for (int j = 1; j <= 12; j ++)
    for (int i = 1; i <= n; i ++){
        p[i][j] = p[p[i][j-1]][j-1];
        mx[i][j] = max(mx[i][j-1], mx[p[i][j-1]][j-1]);
    }

    cin >> q;
    while ( q -- ){
        int u, v;
        cin >> u >> v;
        cout << s - get(u, v) << '\n';
    }

    return 0;
}
