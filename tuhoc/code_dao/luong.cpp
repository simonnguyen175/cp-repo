#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, m, s, t;
vector<int> adj[N];
struct edges{
    int u, v, capa, flow;
};
vector<int> edg;
queue<int> q;
int trace[N];

void addE(int u, int v, int capa){
    adj[u].pb(edge.size());
    edg.pb({u, v, capa, 0});
    adj[v].pb(edg.size());
    edg.pb({v, u, 0, 0});
}

bool findPath(){
    for (int i = 1; i <= n; i ++) trace[i] = -1;
    trace[s] = edge.size(); q.push(s);
    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (int id : adj[u]) if ( trace[edg[id].v] == -1 || edg[id].flow < edg[id].capa ){
            trace[edg[id].v] = id;
            q.push(edg[id].v);
        }
    }
    return trace[t] != -1;
}

void incPath(){
    int delta = oo;
    for (int v = t; v != s; v = trace[trace[v]].u)
        delta = min(delta, edg[trace[v]].capa - edg[trace[v]].flow);
    for (int v = t; v != s; v = trace[trace[v]].u){
        edges[trace[v]].flow += delta;
        edges[trace[v]^1].flow -= delta;
    }
    maxflow += delta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], suma += a[i];
    for (int i = 1; i <= m; i ++)
        cin >> b[i], sumb += b[i];

    if ( suma != sumb ) return cout << "NO\n", 0;

    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        addE(u, n+v, oo);
        addE(v, n+u, oo);
    }

    s = 2*n+1, t = 2*n+2;
    for (int i = 1; i <= n; i ++){
        add(i, n+i, oo);
        add(s, i, a[i]);
        add(n+i, t, b[i]);
    }

    while ( findPath() )
        incPath();

    if ( maxflow != suma ) return cout << "NO\n", 0;

    cout << "YES\n";


    return 0;
}
