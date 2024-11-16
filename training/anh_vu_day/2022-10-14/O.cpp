#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, m, k, x, y;
int spe[N], d[N][2], trace[N][2];
vector<pi> adj[N];
struct node{
    int du, u, tu;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};

void dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1; i <= n; i ++)
        d[i][0] = d[i][1] = oo, trace[i][0] = trace[i][1] = 0;
    for (int i = 1; i <= k; i ++){
        int u = spe[i];
        if ( u == x || u == y ) continue;
        d[u][0] = 0;
        trace[u][0] = u;
        heap.push({0, u, 0});
    }

    while ( heap.size() ){
        int u = heap.top().u, du = heap.top().du, tu = heap.top().tu;
        heap.pop();

        if ( du != d[u][tu] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v][0] >= du + w ){
                if ( trace[u][tu] != trace[v][0] )
                    d[v][1] = d[v][0], trace[v][1] = trace[v][0];
                d[v][0] = du + w, trace[v][0] = trace[u][tu];
                heap.push({d[v][0], v, 0});
            }
            else if ( d[v][1] > du + w && trace[u][tu] != trace[v][0] ){
                d[v][1] = du + w, trace[v][1] = trace[u][tu];
                heap.push({d[v][1], v, 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("O.inp", "r") ){
        freopen("O.inp", "r", stdin);
        freopen("O.out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    for (int i = 1; i <= k; i ++)
        cin >> spe[i];

    dijkstra();
    int dxy = oo;
    for (int i = 1; i <= n; i ++)
        if ( d[i][0] + d[i][1] < dxy ){
            dxy = d[i][0] + d[i][1];
            x = trace[i][0], y = trace[i][1];
        }

    int ans = oo;
    dijkstra();

    // x, y cung chang
    for (int i = 1; i <= k; i ++) if ( spe[i] != x && spe[i] != y )
        ans = min(ans, dxy + d[spe[i]][1]);

    // x, y khac chang
    for (int i = 0; i <= 1; i ++)
    for (int j = 0; j <= 1; j ++) if ( trace[x][i] != trace[y][j] )
        ans = min(ans, d[x][i] + d[y][j]);

    cout << ans;

    return 0;
}
