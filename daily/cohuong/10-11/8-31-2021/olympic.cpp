#include<bits/stdc++.h>
#define simon "olympic"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<ll, int>
#define pb push_back
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e15;

int n, m, k, c;
bool isCity[N];
vector<pi> adj[N];
ll d[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> k >> c;

    memset(isCity, 0, sizeof isCity);

    for (int i = 1; i <= k; i ++){
        int u; cin >> u;
        isCity[u] = 1;
    }

    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    // dijkstra
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = oo;
    d[c] = 0; heap.push({d[c], c});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (auto it : adj[u]){
            int v = it.se; ll w = it.fi;
            if ( d[v] > du + w ){
                d[v] = du + w;
                heap.push({d[v], v});
            }
        }
    }

    vector<pi> ans;
    for (int i = 1; i <= n; i ++)
        if ( isCity[i] ) ans.pb({d[i], i});

    sort(ans.begin(), ans.end());

    for (auto it : ans) cout << it.se << ' ' << it.fi << '\n';

    return 0;
}
