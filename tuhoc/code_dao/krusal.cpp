#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;

struct edge{
    int u, v, w;
};

bool cmp(edge a, edge b){
    return a.w < b.w;
}

int n, m;
int cha[N], hang[N];
vector<pair<int, int>> adj[N];

int Find(int u){
    if ( cha[u] != u ) cha[u] = Find(cha[u]);
    return cha[u];
}

bool Join(int u, int v){
    //cout << u << ' ' << Find(u) << ' ' << v <<' ' << Find(v) << '\n';
    u = Find(u); v = Find(v);
    if ( u == v ) return false;

    if ( hang[u] == hang[v] ) hang[u] ++;
    if ( hang[u] < hang[v] ) cha[u] = v;
    else cha[v] = u;
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("krusal.inp", "r", stdin);
    freopen("krusal.out", "w", stdout);
    cin >> n >> m;
    vector<edge> edges(m);

    for (edge &e : edges) cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 1; i <= n; i ++){
        cha[i] = i;
        hang[i] = 0;
    }

    int mst_weight = 0;

    for (edge &e : edges)
        if ( Join(e.u, e.v) ){
            mst_weight += e.w;
            adj[e.u].push_back({e.v, e.w});
            adj[e.v].push_back({e.u, e.w});
        }

    for (int i = 1; i <= n; i ++)
        cout << i << ' ' << adj[i][0].first << ' ' << adj[i][0].second << '\n';

    for (int i = 1; i <= n; i ++)
        cout << cha[i] <<' '<<hang[i] << '\n';

    cout << mst_weight;

    return 0;
}
