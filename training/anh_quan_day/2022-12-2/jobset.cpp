#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, m, s, t;
vector<int> adj[N];
struct edg{
    int u, v, capa, flow;
};
vector<edg> edges;
queue<int> q;
int p[N], trace[N];

void addE(int u, int v, int capa){
    adj[u].pb(edges.size());
    edges.pb({u, v, capa});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0});
}

bool findPath(){
    for (int i = 1; i <= n; i ++) trace[i] = -1;
    trace[s] = edges.size(), q.push(s);
    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (int id : adj[u]) if ( trace[edges[id].v] == -1 && edges[id].flow < edges[id].capa ){
            trace[edges[id].v] = id;
            q.push(edges[id].v);
        }
    }
    return trace[t] != -1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    cin >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        addE(u, v, oo);
    }
    s = ++n, t = ++n;
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        if ( p[i] > 0 ) addE(s, i, p[i]), sum += p[i];
        else addE(i, t, -p[i]);

    int maxflow = 0;
    while ( findPath() ){
        int delta = oo;
        for (int v = t; v != s; v = edges[trace[v]].u)
            delta = min(delta, edges[trace[v]].capa-edges[trace[v]].flow);
        for (int v = t; v != s; v = edges[trace[v]].u){
            edges[trace[v]].flow += delta;
            edges[trace[v]^1].flow -= delta;
        }
        maxflow += delta;
    }

    cout << sum - maxflow;

    return 0;
}
