#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
using namespace std;
const int N = 305;
const ll oo = 1e15;

int n, m, nn, s, t;
vector<int> adj[N];
struct edg{
    int u, v, capa, flow, cost;
    int rem() { return capa-flow; }
};
vector<edg> edges;
int trace[N], inq[N];
ll c[N], d[N];
queue<int> q;

void addEdge(int u, int v, int capa, int cost){
    adj[u].pb(edges.size());
    edges.pb({u, v, capa, 0, cost});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0, 0, -cost});
}

bool spfa(){
    for (int i = 1; i <= nn; i ++)
        d[i] = oo, inq[i] = 0, trace[i] = 0;

    d[s] = 0, inq[s] = 1, q.push(s);
    while ( q.size() ){
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for (int id : adj[u]) if ( edges[id].rem() ){
            int v = edges[id].v;
            if ( d[v] > d[u] + edges[id].cost ){
                trace[v] = id;
                d[v] = d[u] + edges[id].cost;
                if ( inq[v] ) continue;
                q.push(v);
                inq[v] = 1;
            }
        }
    }

    return d[t] != oo;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        char x;
        cin >> x;
        if ( x == 'Y' ) addEdge(i, n+j, 1, 0);
    }

    for (int i = 1; i <= n; i ++) cin >> c[i];

    nn = n + m;
    s = ++nn, t = ++nn;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        addEdge(s, i, 1, c[i]*(2*j-1));
    for (int i = 1; i <= m; i ++)
        addEdge(n+i, t, 1, 0);

    int maxflow = 0;
    ll mincost = 0;
    while ( spfa() ){
        ll delta = oo;
        for (int v = t; v != s; v = edges[trace[v]].u)
            delta = min(delta, edges[trace[v]].rem());
        for (int v = t; v != s; v = edges[trace[v]].u){
            edges[trace[v]].flow += delta;
            edges[trace[v]^1].flow -= delta;
        }
        maxflow += delta;
        mincost += 1LL * delta * d[t];
    }

    if ( maxflow < m ) cout << -1;
    else cout << mincost;


    return 0;
}
