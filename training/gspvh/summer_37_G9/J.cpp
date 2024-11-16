#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 3e3 + 5;
const int oo = 1e9;

int n, k, nn, s, t;
vector<int> cont, adj[N];
struct que{
    int s, t, v;
} query[N];
struct edg{
    int u, v, capa, flow, cost, id;
    int rem() { return capa-flow; }
};
vector<edg> edges;
ll d[N];
int trace[N], inq[N], ans[N];
queue<int> q;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void add(int u, int v, int capa, int cost, int id){
    adj[u].pb(edges.size());
    edges.pb({u, v, capa, 0, -cost, id});
    adj[v].pb(edges.size());
    edges.pb({v, u, 0, 0, cost, id});
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("hotel.inp", "r", stdin);
    freopen("hotel.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> query[i].s >> query[i].t >> query[i].v;
        cont.pb(query[i].s);
        cont.pb(query[i].s + query[i].t);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.end(), cont.end()), cont.end());

    for (int i = 1; i <= n; i ++)
        add(id(query[i].s), id(query[i].s+query[i].t), 1, query[i].v, i);

    for (int i = 2; i <= cont.size(); i ++)
        add(i-1, i, k, 0, 0);

    nn = cont.size();
    s = ++nn, t = ++nn;
    add(s, 1, k, 0, 0);
    add(nn-2, t, k, 0, 0);

    ll mincost = 0;
    while ( spfa() ){
        int delta = oo;
        for (int v = t; v != s; v = edges[trace[v]].u)
            delta = min(delta, edges[trace[v]].rem());
        for (int v = t; v != s; v = edges[trace[v]].u){
            edges[trace[v]].flow += delta;
            edges[trace[v]^1].flow -= delta;
        }
        mincost += 1LL * delta * d[t];
    }

    cout << -mincost << '\n';
    for (auto it : edges) if ( it.id && it.flow == 1 )
        ans[it.id] = 1;
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
