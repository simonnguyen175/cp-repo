#include<bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int oo = 1e15;
const int N = 5e5 + 5;

int n, m, k, q;
int g[N], d[N];
vector<pair<int, int>> adj[N];

void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> heap;

    for (int i = 1; i <= n; i ++)
        d[i] = oo;

    for (int i = 1; i <= k; i ++)
        heap.push({0, g[i]}), d[g[i]] = 0;

    while ( heap.size() ){
        int u = heap.top().se, du = heap.top().fi;

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
}

signed main(){
    if ( fopen("nuclear.in", "r") ){
        freopen("nuclear.in", "r", stdin);
        freopen("nuclear.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> g[i];

    dijkstra();

    cin >> q;
    while ( q -- ){
        int u;
        cin >> u;
        cout << d[u] << ' ';
    }

    return 0;
}
