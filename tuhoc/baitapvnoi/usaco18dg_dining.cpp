#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e4 + 5;
const int oo = 2e9;

int n, m, k;
vector<pi> adj[N];
int d[N][2];
struct node{
    int du, u, t;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
int grass[N], yum[N];

void dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1; i <= n; i ++) d[i][0] = d[i][1] = oo;
    d[n][0] = 0; heap.push({0, n, 0});
    if ( grass[n] ) d[n][1] = -yum[n], heap.push({-yum[n], n, 1});

    while ( heap.size() ){
        int u = heap.top().u, du = heap.top().du, t = heap.top().t;
        heap.pop();
        if ( d[u][t] != du ) continue;
        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v][t] > d[u][t] + w ){
                d[v][t] = d[u][t] + w;
                heap.push({d[v][t], v, t});
            }

            if ( !t && grass[v] && d[v][1] > d[u][0] + w - yum[v] ){
                d[v][1] = d[u][0] + w - yum[v];
                heap.push({d[v][1], v, 1});
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

    for (int i = 1, x, y; i <= k; i ++){
        cin >> x >> y;
        grass[x] = 1, yum[x] = y;
    }

    dijkstra();

    for (int u = 1; u < n; u ++)
        cout << ( d[u][1] <= d[u][0] ) << '\n';

    return 0;
}
