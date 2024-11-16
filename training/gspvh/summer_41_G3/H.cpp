#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int MOD = 998244353;
const ll oo = 1e18;
const int N = 1e6 + 5;

int n, ntribe, m, z;
ll d[N], ans[N], pw[10];
vector<pi> adj[N];
priority_queue<pi, vector<pi>, greater<pi>> heap;

void dijkstra(int x){
    for (int i = 1; i <= n+ntribe; i ++) d[i] = oo;
    d[x] = 0;
    heap.push({0, x});
    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
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

    for (int i = 1; i <= n; i ++){
        if ( d[i] == oo ) d[i] = -1;
        ( ans[i] += d[i] % MOD * pw[x] % MOD + MOD ) %= MOD;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> ntribe >> m;
    for (int i = 1; i <= ntribe; i ++){
        int t, h; cin >> t >> h;
        for (int j = 1, u; j <= t; j ++){
            cin >> u;
            adj[n+i].pb({u, h});
            adj[u].pb({n+i, 0});
        }
    }

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    cin >> z;
    for (int i = 1; i <= z; i ++){
        pw[i] = 1;
        for (int j = 1; j <= i; j ++)
            pw[i] *= i;
    }

    for (int u = 1; u <= z; u ++)
        dijkstra(u);

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
