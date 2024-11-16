#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n, m;
struct edge{
    int u, v, w, id;
    bool operator < (const edge &a) const{
        return w < a.w;
    }
} edges[N];
int Par[N], Rank[N], mst[N];
int p[N][20], mxe[N][20], h[N];
int sh[N], ans[N];
vector<edge> adj[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[u] = v;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    else return false;
}

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.v;
        if ( v == pu ) continue;
        p[v][0] = u;
        mxe[v][0] = it.w;
        sh[v] = it.id;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

pi get(int u, int v){
    int res = 0;
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 19; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] ){
            res = max(res, mxe[u][i]);
            u = p[u][i];
        }

    if ( u == v ) return {u, res};

    for (int i = 19; i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            res = max({res, mxe[u][i], mxe[v][i]});
            u = p[u][i]; v = p[v][i];
        }

    res = max({res, mxe[u][0], mxe[v][0]});

    return {p[u][0], res};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w, i};
    }

    sort(edges + 1, edges + 1 + m);
    memset(mst, 0, sizeof mst);

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 1;

    for (int i = 1; i <= m; i ++)
        if ( Join(edges[i].u, edges[i].v) ){
            adj[edges[i].u].pb({0, edges[i].v, edges[i].w, edges[i].id});
            adj[edges[i].v].pb({0, edges[i].u, edges[i].w, edges[i].id});
            mst[i] = 1;
        }

    h[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= 19; i ++)
    for (int u = 1; u <= n; u ++){
        p[u][i] = p[p[u][i-1]][i-1];
        mxe[u][i] = max(mxe[u][i-1], mxe[p[u][i-1]][i-1]);
    }

    for (int i = 1; i <= n; i ++) Par[i] = i;

    for (int i = 1; i <= m; i ++) if ( !mst[i] ){
        pi tmp = get(edges[i].u, edges[i].v);
        int u = Find(edges[i].u), v = Find(edges[i].v);
        ans[edges[i].id] = tmp.se;

        while ( h[u] > h[tmp.fi] ){
            Par[u] = p[u][0];
            ans[sh[u]] = edges[i].w;
            u = Find(u);
        }

        while ( h[v] > h[tmp.fi] ){
            Par[v] = p[v][0];
            ans[sh[v]] = edges[i].w;
            v = Find(v);
        }
    }

    for (int i = 1; i <= m; i ++)
        cout << ans[i] - 1 << ' ';

    return 0;
}
