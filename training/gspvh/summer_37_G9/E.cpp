#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 4e3;
const int oo = 1e9;

int n, npro, nspo, s, t, pro, spo;
struct edg{
    int u, v, capa, flow, cost;
    int rem() const { return capa-flow; }
};
vector<edg> edges;
vector<int> adj[N];
int a[N], b[N], d[N], trace[N], inque[N];
queue<int> q;

void add(int u, int v, int capa, int cost){
    adj[u].pb(edges.size());
    edges.pb({u, v, capa, 0, cost});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0, 0, -cost});
}

bool spfa(){
    for (int i = 1; i <= n+4; i ++){
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("E.inp", "r") ){
        freopen("E.inp", "r", stdin);
        freopen("E.out", "w", stdout);
    }

    cin >> n >> npro >> nspo;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    s = n+1, t = n+2;
    pro = n+3, spo = n+4;
    add(s, pro, npro, 0);
    add(s, spo, nspo, 0);
    for (int i = 1; i <= n; i ++){
        add(pro, i, 1, -a[i]);
        add(spo, i, 1, -b[i]);
        add(i, t, 1, 0);
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

    vector<int> prog, sport;
    for (auto it : edges) if ( it.flow > 0 ){
        if ( it.u == n+3 ) prog.pb(it.v);
        if ( it.u == n+4 ) sport.pb(it.v);
    }

    cout << -mincost << '\n';
    for (auto x : prog) cout << x << ' '; cout << '\n';
    for (auto x : sport) cout << x << ' '; cout << '\n';

    return 0;
}
