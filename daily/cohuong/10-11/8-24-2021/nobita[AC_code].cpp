#include<bits/stdc++.h>
#define simon "nobita"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<ll, int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k;
vector<pi> adj[N];
struct edge{
    int u, v; ll w;
    bool operator < (const edge &a){
        return w < a.w;
    }
};
vector<edge> edges;
ll d[N], Par[N], Rank[N], Be[N];
priority_queue<pi, vector<pi>, greater<pi>> heap;

int Find(int u){
    if ( Par[u] == u ) return u;
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

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    // Dijkstra
    for (int i = 1; i <= n; i ++) d[i] = oo;

    cin >> k;
    for (int i = 1; i <= k; i ++){
        int u; cin >> u;
        d[u] = 0; Be[u] = u;
        Par[u] = u; Rank[u] = 0;
        heap.push({d[u], u});
    }

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.se; ll w = it.fi;
            if ( Be[v] )
                edges.pb({Be[u], Be[v], d[v]+d[u]+w});
            if ( d[v] > du + w ){
                d[v] = du + w;
                Be[v] = Be[u];
                heap.push({d[v], v});
            }
        }
    }

    // Kruskal
    ll ans = 0;
    sort(edges.begin(), edges.end());

    //for (auto it : edges)
    //cout << it.u << ' ' << it.v << ' ' << it.w << '\n';

    for (auto it : edges){
        int u = it.u, v = it.v;
        if ( Join(u, v) ) ans += it.w;
    }

    cout << ans + d[1];

    return 0;
}
