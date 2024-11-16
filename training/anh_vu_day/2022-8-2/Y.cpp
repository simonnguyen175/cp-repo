#include<bits/stdc++.h>
#define pi pair<ll, ll>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k;
vector<pi> adj[N];
int Par[N], Rank[N], tele[N], lab[N];
ll d[N];
ll ans;
struct edg{
    int u, v;
    ll w;
};

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        return true;
    }
    return false;
}

void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    for (int i = 1; i <= k; i ++)
        lab[tele[i]] = tele[i];
    for (int i = 1; i <= n; i ++) if ( lab[i] ){
        heap.push({0, i});
        d[i] = 0;
    }

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > d[u] + w ){
                d[v] = d[u] + w;
                lab[v] = lab[u];
                heap.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("Y.inp", "r") ){
        freopen("Y.inp", "r", stdin);
        freopen("Y.out", "w", stdout);
    }

    cin >> n >> m;
    vector<edg> edges;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    cin >> k;
    for (int i = 1, u; i <= k; i ++)
        cin >> tele[i];

    // make edges between k portals
    dijkstra();
    vector<edg> nedg;
    for (auto it : edges){
        int u = it.u, v = it.v;
        ll w = it.w;
        w += d[u] + d[v];
        u = lab[u], v = lab[v];
        if ( u != v ) nedg.pb({u, v, w});
    }

    // kruskal
    sort(nedg.begin(), nedg.end(), [&](edg a, edg b){
        return a.w < b.w;
    });
    for (int i = 1; i <= n; i ++) Rank[i] = 1, Par[i] = i;
    for (auto it : nedg){
        int u = it.u, v = it.v;
        ll w = it.w;
        if ( Join(u, v) ) ans += w;
    }
    ans += d[1];
    cout << ans;

    return 0;
}

