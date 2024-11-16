#include<bits/stdc++.h>
#define pb push_back
#define eps 1e-12
#define ll long long
using namespace std;
const int N = 100;
const ll oo = 1e18;

int n, m, s, t, maxflow;
float x;
vector<int> adj[N];
float org[N*N];
int trace[N];
queue<int> q;
struct edg{
    int u, v;
    ll capa, flow;
};
vector<edg> edges;

void add(int u, int v, float w){
    adj[u].pb(edges.size());
    org[edges.size()] = w;
    edges.pb({u, v, 0, 0});

    adj[v].pb(edges.size());
    org[edges.size()] = 0;
    edges.pb({v, u, 0, 0});
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

bool check(float mid){
    for (int i = 0; i < edges.size()-1; i ++){
        edges[i].capa = (int)org[i] / mid;
        edges[i].flow = 0;
    }
    edges[edges.size()-1].capa = x;
    edges[edges.size()-1].flow = 0;

//    for (auto it : edges)
//        cout << it.u << ' ' << it.v << ' ' << it.capa << ' ' << it.flow << '\n';

    maxflow = 0;
    while ( findPath() ){
        ll delta = oo;
        for (int v = t; v != s; v = edges[trace[v]].u)
            delta = min(delta, edges[trace[v]].capa-edges[trace[v]].flow);
        for (int v = t; v != s; v = edges[trace[v]].u){
            edges[trace[v]].flow += delta;
            edges[trace[v]^1].flow -= delta;
        }
        maxflow += delta;
    }

    return ( maxflow == x );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("B.inp", "r") ){
        freopen("B.inp", "r", stdin);
        freopen("B.out", "w", stdout);
    }

    cin >> n >> m >> x;
    for (int i = 1; i <= m; i ++){
        int u, v;
        float w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    s = n+1, t = n;
    adj[s].pb(edges.size());
    edges.pb({s, 1, 0, 0});

    float l = 0, r = 1e6, mid, res;
    for (int i = 1; i <= 300; i ++){
        mid = ( l + r ) / 2;
        if ( check(mid) ) l = mid + eps, res = mid;
        else r = mid - eps;
    }


    cout << fixed << setprecision(10) << res * x;

    return 0;
}
