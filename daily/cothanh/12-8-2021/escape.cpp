#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9;

int n, m, x, ans = oo;
int t[N], d[N][3][205];
vector<pi> adj[N];
struct spot{
    int u, mod, tim, dis;
    bool operator > (const spot &a) const{
        return dis > a.dis;
    }
};

void dijkstra(){
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= 205; j ++)
            d[i][0][j] = d[i][1][j] = d[i][2][j] = oo;

    priority_queue<spot, vector<spot>, greater<spot>> heap;
    d[1][t[1]][1] = 0;
    heap.push({1, t[1], 1, 0});
    while ( heap.size() ){
        int u = heap.top().u, modu = heap.top().mod;
        int timu = heap.top().tim, disu = heap.top().dis;
        heap.pop();

        if ( disu != d[u][modu][timu] ) continue;

        if ( u == n ) ans = min(ans, disu);

        int v, w, modv, timv;
        for (auto it : adj[u]){
            v = it.fi, w = it.se;
            modv = modu, timv = timu + w;
            if ( t[v] == 1 ){;
                if ( timv > x ) timv = x + 1;
                if ( d[v][modv][timv] > disu + w ){
                    d[v][modv][timv] = disu + w;
                    heap.push({v, modv, timv, disu + w});
                }
            }
            else if ( t[v] != modu && modu != 1 ){
                if ( timv <= x ) continue;
                modv = t[v], timv = 1;
                if ( d[v][modv][timv] > disu + w ){
                    d[v][modv][timv] = disu + w;
                    heap.push({v, modv, timv, disu + w});
                }
            }
            else{
                modv = t[v], timv = 1;
                if ( d[v][modv][timv] > disu + w ){
                    d[v][modv][timv] = disu + w;
                    heap.push({v, modv, timv, disu + w});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("escape.in", "r") ){
        freopen("escape.in", "r", stdin);
        freopen("escape.out", "w", stdout);
    }

    cin >> n >> m >> x;
    for (int i = 1; i <= n; i ++)
        cin >> t[i];
    for (int i = 1; i <= m; i ++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra();

    cout << ans;

    return 0;
}
