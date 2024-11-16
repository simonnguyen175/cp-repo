#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, m;
vector<pi> adj[N];
int d[N], par[N];

void dijkstra(){
    for (int i = 1; i <= n; i ++) d[i] = oo;
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    d[1] = 0; heap.push({0, 1});

    while ( heap.size() ){
        int u = heap.top().se, du = heap.top().fi;
        heap.pop();
        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > du + w ){
                par[v] = u;
                d[v] = du + w;
                heap.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra();

    for (int i = 2; i <= n; i ++){
        int tmp = oo;
        for (auto it : adj[i]) if ( it.se + d[par[i]] != d[i] )
            tmp = min(tmp, d[it.fi] + it.se);
        cout << tmp << '\n';
        if ( tmp == oo ) cout << -1 << '\n';
    }



    return 0;
}
