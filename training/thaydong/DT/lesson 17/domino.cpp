#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 20;
const int oo = 1e9;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n, k, s, s1, t;
int a[N][N];
struct edg{
    int u, v, capa, flow, cost;
    int rem() const { return capa-flow; }
};
vector<int> adj[N*N];
vector<edg> edges;
int d[N*N], trace[N*N], inque[N*N];
queue<int> q;

void addE(int u, int v, int capa, int cost){
    adj[u].pb(edges.size());
    edges.pb({u, v, capa, 0, cost});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0, 0, -cost});
}

bool spfa(){
    for (int i = 1; i <= m*n+3; i ++){
        d[i] = oo;
        trace[i] = 0;
        inque[i] = 0;
    }

    d[s] = 0, inque[s] = 1, q.push(s);
    while ( q.size() ){
        int u = q.front();
        q.pop();
        inque[u] = 0;
        for (int id : adj[u]) if ( edges[id].rem() > 0 ){
            int v = edges[id].v;
            if ( d[v] > d[u] + edges[id].cost ){
                d[v] = d[u] + edges[id].cost;
                trace[v] = id;
                if ( !inque[v] ) q.push(v), inque[v] = 1;
            }
        }
    }

    return d[t] != oo;
}

int id(int x, int y){
    return (x - 1) * n + y;
}

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n >> k;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    s = m*n + 1;
    s1 = m*n + 2;
    t = m*n + 3;
    addE(s, s1, k, 0);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( (i + j) % 2 == 0 ){
        addE(s1, id(i, j), 1, 0);
        for (int k = 0; k < 4; k ++){
            int x = i + row[k], y = j + col[k];
            if ( inside(x, y) ){
                addE(id(i, j), id(x, y), 1, - a[i][j] * a[x][y]);
            }
        }
    }
    else{
        addE(id(i, j), t, 1, 0);
    }

    int mincost = 0;
    while ( spfa() ){
        int delta = oo;
        for (int v = t; v != s; v = edges[trace[v]].u)
            delta = min(delta, edges[trace[v]].rem());
        for (int v = t; v != s; v = edges[trace[v]].u){
            edges[trace[v]].flow += delta;
            edges[trace[v]^1].flow -= delta;
        }
        mincost += delta * d[t];
    }

    cout << -mincost;

    return 0;
}
