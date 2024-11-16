#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, m, s, t;
struct edge{
    int u, v, capa, flow;
};
vector<edge> edg;
vector<int> adj[N];
queue<int> q;
int trace[N];
int maxflow = 0;

void addE(int u, int v, int capa){
    adj[u].pb(edg.size());
    edg.pb({u, v, capa, 0});
    adj[v].pb(edg.size());
    edg.pb({v, u, 0, 0});
}

bool findPath(){
    for (int i = 1; i <= n; i ++)
        trace[i] = -1;
    trace[s] = edg.size();
    q.push(s);
    while ( q.size() ){
        int u = q.front();
        q.pop();

        for (int id  : adj[u]){
            int v = edg[id].v;
            if ( trace[v] != -1 || edg[id].flow >= edg[id].capa ) continue;
            q.push(v);
            trace[v] = id;
        }
    }
    return trace[t] != -1;
}

void incPath(){
    int delta = oo;
    for (int v = t; v != s; v = edg[trace[v]].u){
        delta = min(delta, edg[trace[v]].capa - edg[trace[v]].flow);
    }

    for (int v = t; v != s; v = edg[trace[v]].u){
        edg[trace[v]].flow += delta;
        edg[trace[v]^1].flow -= delta;
    }

    maxflow += delta;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, c;
        cin >> u >> v >> c;
        addE(u, v, c);
    }

    while ( findPath() )
        incPath();

    cout << maxflow;

    return 0;
}
