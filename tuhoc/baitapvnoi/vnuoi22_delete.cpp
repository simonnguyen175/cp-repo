#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;
const ll oo = 1e15;
const ll lim = 1e9 + 7;
const ll MOD = 998244353;

int n, m, k;
map<pi, int> g;
ll d[N], f[N], pw[N];
pi edges[N];
vector<pi> adj[N];

void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    d[1] = 0; f[1] = 1;
    heap.push({0, 1});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > du + w ){
                d[v] = du + w;
                f[v] = f[u];
                heap.push({d[v], v});
            }
            else if ( d[v] == du + w ){
                if ( f[u] == -1 ) { f[v] = -1; continue; }
                f[v] += f[u];
                if ( f[v] > lim ) f[v] = -1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    pw[0] = 1;
    for (int i = 1; i <= k; i++) pw[i] = ( pw[i-1] * 2 ) % MOD;

    int cnt = 0;
    for (int i = 1; i <= k; i ++){
        int u, c;
        cin >> u >> c;
        if ( g[{u, c}] ) { g[{u, c}] ++; continue; }
        edges[++cnt] = {u, c};
        g[{u, c}] = 1;
        adj[1].pb({u, c});
    }

    dijkstra();

    for (int i = 1; i <= n; i ++)
        cout << d[i] << ' ' << f[i] << '\n';
    cout << '\n';

    ll ans = 1;
    for (int i = 1; i <= k; i ++){
        int u = edges[i].fi, c = edges[i].se;
        int num = g[{u, c}];
        if ( d[u] == c ){
            if ( f[u] == 1 ) ( ans *= pw[num-1] ) %= MOD;
            else ( ans *= pw[num] ) %= MOD;
        }
        else ( ans *= pw[num] ) %= MOD;
    }

    cout << ans;
}
