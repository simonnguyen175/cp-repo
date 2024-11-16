#include<bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int oo = 1e9;
const int N = 5e5 + 5;

struct edge{
    int u, v, w;
};

bool cmp(edge a, edge b){
    return a.w > b.w;
}

int n, m, k, q;
int g[N], d[N];
int Par[N], Rank[N], ans[N];
set<int> cont[N];
vector<pair<int, int>> adj[N];
edge edges[N];

void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> heap;

    for (int i = 1; i <= n; i ++)
        d[i] = oo;

    for (int i = 1; i <= k; i ++)
        heap.push({0, g[i]}), d[g[i]] = 0;

    while ( heap.size() ){
        int u = heap.top().se, du = heap.top().fi;

        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > du + w ){
                d[v] = du + w;
                heap.push({d[v], v});
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
        edges[i] = {u, v, w};
    }

    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> g[i];

    dijkstra();

    for (int i = 1; i <= m; i ++)
        edges[i].w = min(d[edges[i].u], d[edges[i].v]);

    sort(edges + 1, edges + 1 + m, cmp);

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int s, t;
        cin >> s >> t;
        cont[s].insert(i);
        cont[t].insert(i);
    }
}

void Combine(int u, int v, int w){
    std::set<int>::iterator it;

    if ( cont[u].size() == 0 ){
        for (it = cont[v].begin(); it != cont[v].end(); ++it)
            cont[u].insert(*it);
        return;
    }

    for (it = cont[v].begin(); it != cont[v].end(); ++it){
        auto p = cont[u].find(*it);

        if ( p != cont[u].end() ){
            ans[*p] = w;
            cont[u].erase(p);
        }
        else cont[u].insert(*it);
    }
}

int Find(int u){
    if ( u == Par[u] ) return u;
    return Par[u] = Find(Par[u]);
}

void Join(int u, int v, int w){
    u = Find(u); v = Find(v);

    //cout << "Join " << u << " and " << v << " with size " << w << " : " << '\n';
    if ( u != v ){
        if ( u < v ) swap(u, v);

        Par[v] = u;

        if ( Rank[u] == Rank[v] ) Rank[u] ++;

        Combine(u, v, w);
    }
}

void solve(){
    for (int i = 1; i <= n; i ++)
        Par[i] = i, Rank[i] = 0;

    for (int i = 1; i <= m; i ++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        Join(u, v, w);
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';
}

int main(){
    if ( fopen("evacuation.inp", "r") ){
        freopen("evacuation.inp", "r", stdin);
        freopen("evacuation.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    init();
    solve();

    return 0;
}
