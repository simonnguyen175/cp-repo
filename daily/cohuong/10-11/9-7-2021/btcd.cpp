#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9 + 5;

struct edge{
    int u, v, w;
    bool operator > (const edge& a) const{
        return w > a.w;
    }
};

int n, m, k;
vector<edge> edges;
int Par[N], Rank[N], h[N];
vector<pi> adj[N];
pi p[N][25];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[v] == Rank[u] ) Rank[u] ++;
        return true;
    }
    else return false;
}

void makeKruskal(){
    for (int i = 1; i <= n; i ++)
        Par[i] = i, Rank[i] = 0;
    for (auto it : edges){
        int u = it.u, v = it.v, w = it.w;
        if ( Join(u, v) ){
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
    }
}

void dfs(int u, int pu){
    for (int i = 1; i <= log2(n); i ++){
        p[u][i].fi = p[p[u][i-1].fi][i-1].fi;
        p[u][i].se = min(p[u][i-1].se, p[p[u][i-1].fi][i-1].se);
    }

    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;
        h[v] = h[u] + 1;
        p[v][0].fi = u;
        p[v][0].se = w;
        //cout << u << ' ' << v << ' ' << w << '\n';
        dfs(v, u);
    }
}

int lca(int u, int v){
    int res = oo;
    if ( h[u] < h[v] ) swap(u, v);

    int diff = h[u] - h[v];

    for (int i = log2(n); i >= 0; i --)
        if ( h[p[u][i].fi] >= h[v] ){
            res = min(res, p[u][i].se);
            u = p[u][i].fi;
            //cout << u << ' ' << res << '\n';
        }

    //cout << u << ' ' << v << '\n';

    if ( u == v ) return res;

    for (int i = log2(n); i >= 0; i --)
        if ( p[u][i].fi != p[v][i].fi ){
            res = min({res, p[u][i].se, p[v][i].se});
            u = p[u][i].fi;
            v = p[v][i].fi;
        }

    return res = min({res, p[u][0].se, p[v][0].se});
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }
    sort(edges.begin(), edges.end(), greater<edge>());

    makeKruskal();


    h[0] = -1;
    h[1] = 0;
    dfs(1, 0);

    cin >> k;
    for (int i = 1; i <= k; i ++){
        int u, v;
        cin >> u >> v;
        //cout << "test " << i << '\n';
        cout << lca(u, v) << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if ( fopen("btcd.inp", "r") ){
        freopen("btcd.inp", "r", stdin);
        freopen("btcd.out", "w", stdout);
    }

    solve();

    return 0;
}
