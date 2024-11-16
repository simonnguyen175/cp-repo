#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e2 + 5;

int n, m, k, s, t;
int c[N];
vector<int> adj[N];

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
};
///

int id(int x, int y, int n){
    return (x-1)*n + y;
}

bool check(int mid){
    s = id(n, mid+1, mid+1) + 1, t = id(n, mid+1, mid+1) + 2;
    DinicFlow df(t);

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j < mid; j ++){
        df.addEdge(id(i, j+1, mid+1), id(i, j+2, mid+1), df.INF);
        for (int v : adj[i])
            df.addEdge(id(i, j+1, mid+1), id(v, j+2, mid+1), 1);
    }

    df.addEdge(s, id(1, 1, mid+1), k);
    for (int i = 1; i <= k; i ++)
        df.addEdge(id(c[i], mid+1, mid+1), t, 1);

    return df.maxFlow(s, t) == k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> c[i];

    int lo = 1, hi = 2*n, res = -1;
//    cout << check(3) << '\n';
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res << '\n';

    return 0;
}
