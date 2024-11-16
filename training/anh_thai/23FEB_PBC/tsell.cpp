#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define pb push_back
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9 + 5;

int n, k, nn, s, t;
int w[N];
vector<int> adj[N];
int h[N], p[N][15], id[N][15];

/// DINIC
struct DinicFlow {
    static const long long INF = (long long) 1e18 + 7;
    int numNode, numEdge;
    vector<int> dist, head, work;
    vector<int> point, next;
    vector<long long> flow, capa;

    DinicFlow(int n = 0) {
        numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }

    void init(int n){
        numNode = n;
        numEdge = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }

    int addEdge(int u, int v, long long c1, long long c2 = 0) {
        int ret = numEdge;
        point.push_back(v); capa.push_back(c1); flow.push_back(0); next.push_back(head[u]); head[u] = numEdge++;
        point.push_back(u); capa.push_back(c2); flow.push_back(0); next.push_back(head[v]); head[v] = numEdge++;
        return ret;
    }

    bool bfs(int s, int t) {
        queue<int> q;
        for (int i = 1; i <= numNode; i++) dist[i] = -1;
        dist[s] = 0; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] < 0) {
                dist[point[i]] = dist[u] + 1;
                q.push(point[i]);
            }
        }
        return dist[t] >= 0;
    }
    long long dfs(int s, int t, long long f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = next[i]) if (flow[i] < capa[i] && dist[point[i]] == dist[s] + 1) {
            long long d = dfs(point[i], t, min(f, capa[i] - flow[i]));
            if (d > 0) {
                flow[i] += d;
                flow[i ^ 1] -= d;
                return d;
            }
        }
        return 0;
    }

    long long maxFlow(int s, int t) {
        long long totFlow = 0;
        while (bfs(s, t)) {
            for (int i = 1; i <= numNode; i++) work[i] = head[i];
            while (true) {
                int d = dfs(s, t, INF);
                if (d == 0) break;
                totFlow += d;
            }
        }
        return totFlow;
    }

    int getFlow(int id) const {
        return flow[id];
    }

    bool visited(int node) const {
        return dist[node] >= 0;
    }
} df;
///

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 14; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
         u = p[u][i];

    if ( u == v ) return u;

    for (int i = 14; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void add(int x, int u, int v){
    if ( u == v ) { df.addEdge(x, u, oo); return; }

    int dh = h[u] - h[v];
    for (int i = 0; i <= 14; i ++) if ( BIT(dh, i) ){
        df.addEdge(x, id[u][i], oo);
        u = p[u][i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i <= n; i ++) cin >> w[i];

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);

    for (int j = 1; j <= 14; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    nn = n;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= 14; j ++)
        if ( p[i][j] ) id[i][j] = ++nn;

    df.init(nn + k + 2);
    s = nn + k + 1;
    t = nn + k + 2;

    for (int i = 1; i <= n; i ++){
        if ( p[i][0] ){
            df.addEdge(id[i][0], i, oo);
            df.addEdge(id[i][0], p[i][0], oo);
        }

        for (int j = 1; j <= 14; j ++) if ( p[i][j] ){
            df.addEdge(id[i][j], id[i][j-1], oo);
            df.addEdge(id[i][j], id[p[i][j-1]][j-1], oo);
        }
    }

    for (int i = 1; i <= k; i ++){
        int u, v, c;
        cin >> u >> v >> c;

        df.addEdge(s, nn+i, c);

        if ( u == v ){
            df.addEdge(nn+i, u, oo);
            continue;
        }

        if ( h[u] < h[v] ) swap(u, v);

        for (int j = 14; j >= 0; j --)
            if ( h[p[u][j]] >= h[v] ){
                df.addEdge(nn+i, id[u][j], oo);
                u = p[u][j];
            }

        if ( u == v ) continue;

        for (int j = 14; j >= 0; j --)
            if ( p[u][j] != p[v][j] ){
                df.addEdge(nn+i, id[u][j], oo);
                df.addEdge(nn+i, id[v][j], oo);
                u = p[u][j], v = p[v][j];
            }

        df.addEdge(nn+i, id[u][0], oo);
        df.addEdge(nn+i, id[v][0], oo);
    }

    for (int i = 1; i <= n; i ++)
        df.addEdge(i, t, w[i]);

    cout << df.maxFlow(s, t);

    return 0;
}
