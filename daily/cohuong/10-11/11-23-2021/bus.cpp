#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const ll oo = 1e15;

int n, m;
ll C[N], D[N], d[N];
vector<int> adj[N];
vector<pi> g[N];

void bfs(int x){
    queue<int> q;
    for (int i = 1; i <= n; i ++) d[i] = -1;
    d[x] = 0; q.push(x);

    while ( q.size() ){
        int u = q.front(); q.pop();
        for (int v : adj[u])
        if ( d[v] == -1 ){
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    for (int i = 1; i <= n; i ++)
        if ( d[i] <= D[x] )
            g[x].pb({i, C[x]});
}

void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    d[1] = 0; heap.push({d[1], 1});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();
        if ( du != d[u] ) continue;
        for (auto it : g[u]){
            int v = it.fi;
            ll w = it.se;
            if ( d[v] > du + w ){
                d[v] = du + w;
                heap.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("bus.inp", "r") ){
        freopen("bus.inp", "r", stdin);
        freopen("bus.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> C[i] >> D[i];

    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++) bfs(i);

    dijkstra();

    cout << d[n];

    return 0;
}
