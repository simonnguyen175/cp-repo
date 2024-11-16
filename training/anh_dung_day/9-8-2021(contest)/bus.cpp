#include<bits/stdc++.h>
#define simon "bus"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<ll, int>
#define pii pair<ll, pi>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, q;
int Par[N], Rank[N];
int h[N], p[N][25];
ll d[45][N], len[N];
vector<pii> edges;
vector<pi> adj[N], adjk[N];
set<int> cont;

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    else return false;
}

void dfs(int u, int pu){
    for (int i = 1; i <= log2(n); i ++)
        p[u][i] = p[p[u][i-1]][i-1];

    for (auto it : adjk[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        len[v] = len[u] + it.se;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( u == 1 || v == 1 ) return 1;
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = log2(n); i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = log2(n); i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            u = p[u][i];
            v = p[v][i];
        }

    return p[u][0];
}

void dijkstra(int val, int x){
    for (int i = 1; i <= n; i ++) d[x][i] = oo;
    d[x][val] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    heap.push({0, val});

    while (heap.size()){
        int u = heap.top().se; ll du = heap.top().fi;
        heap.pop();
        if ( du != d[x][u]) continue;
        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[x][v] > du + w ){
                d[x][v] = du + w;
                heap.push({d[x][v], v});
            }
        }
    }
}

void init(){
    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges.pb({w, {u, v}});
    }

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;
    for (auto it : edges){
        int u = it.se.fi, v = it.se.se, w = it.fi;
        if ( Join(u, v) ){
            adjk[u].pb({v, w});
            adjk[v].pb({u, w});
        }
        else{
            cont.insert(u); cont.insert(v);
        }
    }

    h[1] = 0; len[1] = 0;
    dfs(1, 0);

    int cnt = 0;
    for (auto it = cont.begin(); it != cont.end(); it ++)
        dijkstra(*it, ++cnt);
}

void solve(){
    cin >> q;
    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;
        ll res = len[u] + len[v] - 2*len[lca(u, v)];
        int id = 1;
        for (auto it = cont.begin(); it != cont.end(); it ++){
            res = min(res, d[id][u] + d[id][v]);
            id ++;
        }
        cout << res << '\n';
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

    init();
    solve();

    return 0;
}
