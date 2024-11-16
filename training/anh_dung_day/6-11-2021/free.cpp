#include<bits/stdc++.h>
#define simon "free"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<int, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, m, x, y;
vector<ii> adj[N];
ll d1[N], dn[N], dx[N], dy[N], mnx[N], mny[N], ans;
bool vis[N];

void file(){
    FASTio
    if ( fopen(simon".inp", "r" ) ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

void dijkstra(int s, ll d[]){
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    for (int i = 1; i <= n; i ++)
        d[i] = INT_MAX;
    d[s] = 0;
    heap.push({d[s], s});

    while ( !heap.empty() ){
        int u = heap.top().se, du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.se;
            int w = it.fi;

            if ( d[v] > du + w ) d[v] = du + w, heap.push({d[v], v});
        }
    }
}

void init(){
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    dijkstra(n, dn);
    dijkstra(1, d1);
    dijkstra(x, dx);
    dijkstra(y, dy);
}

void dfs(int u){
    vis[u] = 1;
    for ( auto it : adj[u] ){
        int v = it.se, w = it.fi;
        if ( d1[u] + w + dn[v] == d1[n] ){

            if ( vis[v] == 0 ) dfs(v);
            mny[u] = min(mny[v], dy[u]);
            mnx[u] = min(mnx[v], dx[u]);

            ans = min({ans, dx[u] + mny[u], dy[u] + mnx[u]});
        }
    }
}

void solve(){
    for (int i = 1; i <= n; i ++)
        mny[i] = dy[i], mnx[i] = dx[i];
    memset(vis, 0, sizeof vis);
    ans = dx[y];
    dfs(1);
    cout << ans;
}

int main(){
    file();
    init();
    solve();
    return 0;
}
