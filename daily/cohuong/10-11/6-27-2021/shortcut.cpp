#include<bits/stdc++.h>
#define simon "shortcut"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e4 + 5;

int m, n, t;
int c[N], par[N];
vector<ii> adj[N];
long long cost[N], d[N], ans = 0;

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void dijkstra(){
    for (int i = 1; i <= n; i ++) d[i] = LLONG_MAX;
    d[1] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    heap.push({0, 1});

    while ( heap.size() ){
        int u = heap.top().se, du = heap.top().fi;
        heap.pop();

        for (auto it : adj[u]){
            int v = it.se, w = it.fi;
            if ( d[v] > du + w ){
                d[v] = du + w;
                par[v] = u;
                heap.push({d[v], v});
            }
            else if ( d[v] == du + w )
                if ( par[v] > u ) par[v] = u;
        }
    }
}

void dfs(int u){
    for (auto it : adj[u]){
        int v = it.se, w = it.fi;
        if ( d[v] == d[u] + w && par[v] == u ){
            dfs(v);
            cost[u] += cost[v];
        }
    }
    ans = max(ans, cost[u] * (d[u] - t));
}

int main(){
    file();
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    c[1] = 0;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    dijkstra();
    for (int i = 1; i <= n; i ++) cost[i] = c[i];
    dfs(1);
    cout << ans;

    return 0;
}
