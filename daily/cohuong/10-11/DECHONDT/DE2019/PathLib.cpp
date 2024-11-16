#include<bits/stdc++.h>
#define simon "PathLib"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<ll, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const ll oo = 1e18;

int n, m, x, y, s, t;
vector<ii> adj[N];
ll d1[N], dn[N], dx[N], dy[N], mnx[N], mny[N], ans;
bool vis[N];

void dijkstra(int x, ll d[]){
    priority_queue<ii, vector<ii>, greater<ii>> heap;

    for (int i = 1; i <= n; i ++)
        d[i] = oo;

    d[x] = 0;
    heap.push({0, x});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.se;
            ll w = it.fi;

            if ( d[v] > du + w ){
                d[v] = du + w;
                heap.push({d[v], v});
            }
        }
    }
}

void dfs(int u){
    vis[u] = 1;
    mny[u] = dy[u];
    mnx[u] = dx[u];

    for ( auto it : adj[u] ){
        int v = it.se; ll w = it.fi;
        if ( d1[u] + w + dn[v] == d1[t] ){
            if ( vis[v] == 0 ) dfs(v);

            mny[u] = min(mny[v], mny[u]);
            mnx[u] = min(mnx[v], mnx[u]);

            ans = min({ans, dx[u] + mny[u], dy[u] + mnx[u]});
        }
    }

    ans = min({ans, dx[u] + mny[u], dy[u] + mnx[u]});
}

void solve(){
    memset(vis, 0, sizeof vis);
    ans = dx[y];

    dfs(s);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> s >> t >> x >> y;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    dijkstra(s, d1);
    dijkstra(t, dn);

    dijkstra(x, dx);
    dijkstra(y, dy);

    solve();

    return 0;
}
