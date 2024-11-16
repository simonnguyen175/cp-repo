#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 7e3 + 5;
const int oo = 1e9;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n, m, nn, s, t, mincost;
int a[N][N];
int d[N], trace[N], inque[N];
vector<int> adj[N];
struct edg{
    int u, v, capa, flow, cost;
    int rem() const { return capa-flow; }
};
vector<edg> edges;
queue<int> q;

int id(int x, int y){
    return m*(x-1)+y;
}

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= m );
}

void add(int u, int v, int capa, int cost){
    adj[u].pb(edges.size());
    edges.pb({u, v, capa, 0, cost});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0, 0, -cost});
}

bool spfa(){
    for (int i = 1; i <= nn+2; i ++){
        d[i] = oo;
        trace[i] = 0;
        inque[i] = 0;
    }

    d[s] = 0, inque[s] = 1, q.push(s);
    while ( q.size() ){
        int u = q.front();
//        cout << u << ' ' << d[u] << '\n';
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];

    nn = m*n, s = nn+1, t = nn+2;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) if ( (i+j) % 2 == 0 ){
        for (int k = 0, x, y; k <= 3; k ++){
            x = i + row[k], y = j + col[k];
            if ( !inside(x, y) ) continue;
            add(id(i,j), id(x,y), 1, a[i][j] != a[x][y]);
        }
        add(s, id(i,j), 1, 0);
    }
    else add(id(i, j), t, 1, 0);

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

    cout << mincost;

    return 0;
}
