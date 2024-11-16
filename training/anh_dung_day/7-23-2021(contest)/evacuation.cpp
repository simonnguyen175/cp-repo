#include<bits/stdc++.h>
#define simon "evacuation"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<int, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e15;

int n, m, k, q;
int g[N];
vector<ii> adj[N];
ll d[N][N], f[N];

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> heap;
    for (int i = 1; i <= n; i ++)
        d[x][i] = INT_MAX;
    d[x][x] = 0;

    heap.push({0, x});

    while ( heap.size() ){
        int u = heap.top().se;
        int du = heap.top().fi;
        heap.pop();

        for (auto it : adj[u]){
            int v = it.fi;
            int w = it.se;
            if ( d[x][v] > du + w ){
                d[x][v] = du + w;
                heap.push({d[x][v], v});
            }
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i ++) f[i] = oo;
    cin >> k;
    for (int i = 1; i <= k; i ++){
        cin >> g[i];
        dijkstra(g[i]);
        for (int j = 1; j <= n; j ++)
            f[j] = min(f[j], d[g[i]][j]);
    }

    cin >> q;
    while ( q -- ){
        int s, t;
        cin >> s >> t;
        cout << min(f[s], f[t]) << '\n';
    }

    return 0;
}
