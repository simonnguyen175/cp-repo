#include<bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9;

int t, n, m, s, f, k;
vector<ii> adj[N], adv[N];
int ds[N], df[N];

void init(){
    cin >> n >> m >> k >> s >> f;
    for (int i = 1; i <= n; i ++) adj[i].clear(), adv[i].clear();
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adv[v].push_back({w, u});
    }
}

void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    for (int i = 1; i <= n; i ++) ds[i] = oo;
    for (int i = 1; i <= n; i ++) df[i] = oo;
    ds[s] = 0, df[f] = 0;

    heap.push({0, s});
    while ( heap.size() ){
        int u = heap.top().se;
        int du = heap.top().fi;
        heap.pop();
        for (auto it : adj[u]){
            int v = it.se, w = it.fi;
            if ( ds[v] > du + w ){
                ds[v] = du + w;
                heap.push({ds[v], v});
            }
        }
    }

    heap.push({0, f});
    while ( heap.size() ){
        int u = heap.top().se;
        int du = heap.top().fi;
        heap.pop();
        for (auto it : adv[u]){
            int v = it.se, w = it.fi;
            if ( df[v] > du + w ){
                df[v] = du + w;
                heap.push({df[v], v});
            }
        }
    }
}

void solve(){
    dijkstra();
    int ans = ds[f];

    for (int i = 1; i <= k; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        int opt1 = ds[u] + w + df[v];
        int opt2 = ds[v] + w + df[u];
        ans = min({ans, opt1, opt2});
    }

    cout << ( ans == oo ? -1 : ans ) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    while ( t -- ){
        init();
        solve();
    }
}
