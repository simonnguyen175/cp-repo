#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e2 + 5;
const int oo = 1e9;

int n, m, s, t;
struct gra{
    int v, w, c;
};
struct node{
    int du, u, cost;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
vector<gra> adj[N];
int d[N][N*N];

void dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= 100*n; j ++)
        d[i][j] = oo;
    d[s][0] = 0;
    heap.push({0, s, 0});
    while ( heap.size() ){
        int u = heap.top().u;
        int cost = heap.top().cost;
        int du = heap.top().du;
        heap.pop();

        if ( d[u][cost] != du ) continue;

        for (auto it : adj[u]){
            int v = it.v, w = it.w, c = it.c;
            if ( d[v][cost+c] > du + w ){
                d[v][cost+c] = du + w;
                heap.push({du+w, v, cost+c});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, w, c;
        cin >> u >> v >> c >> w;
        adj[u].pb({v, w, c});
        adj[v].pb({u, w, c});
    }

    dijkstra();
    int cur = oo, ans = 0;
    for (int i = 0; i <= 100*n; i ++){
        if ( d[t][i] == oo ) continue;
        if ( cur > d[t][i] ) ans ++;
        cur = min(cur, d[t][i]);
    }

    cout << ans;

    return 0;
}
