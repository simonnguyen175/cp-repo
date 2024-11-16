#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e4 + 5;

int n, m, q;
set<int> g[N];
int sz[N], par[N], gro[N];
map<int, int> d[N], dis[N];

int dfs(int u, int pu){
    sz[u] = 1;
    for (int v : g[u]) if ( v != pu )
        sz[u] += dfs(v, u);
    return sz[u];
}

int centroid(int u, int pu, int n){
    for (int v : g[u]) if ( v != pu ){
        if ( sz[v] > n/2 ) return centroid(v, u, n);
    }
    return u;
}

void dfs1(int u, int pu, int c, int du){
    d[c][u] = du;
    for (int v : g[u]) if ( v != pu )
        dfs1(v, u, c, du+1);
}

void build(int u, int pu){
    int n = dfs(u, pu);
    int c = centroid(u, pu, n);
    par[c] = pu;

    dfs1(c, pu, c, 0);

    vector<int> tmp(g[c].begin(), g[c].end());
    for (int v : tmp){
        g[c].erase(v);
        g[v].erase(c);
        build(v, c);
    }
}

void Insert(int u){
//    cerr << "insert " << u << " : \n";
    for (int v = u; v != 0; v = par[v])
        dis[v][d[v][u]] ++;
}

void Remove(int u){
//    cerr << "remove " << u << " : \n";
    for (int v = u; v != 0; v = par[v]){
        dis[v][d[v][u]] --;
        if ( !dis[v][d[v][u]] ) dis[v].erase(d[v][u]);
    }
}

void Que(int u){
//    cerr << "query " << u << " : \n";

    int mnd = n+1;
    for (int v = u; v != 0; v = par[v]) if ( dis[v].size() )
        mnd = min(mnd, dis[v].begin()->fi + d[v][u]);

    int cnt = 0;
    for (int v = u; v != 0; v = par[v]) if ( dis[v].size() )
        if ( dis[v].begin()->fi + d[v][u] == mnd )
            cnt += dis[v].begin()->se;

    cout << mnd << ' ' << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> q;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    build(1, 0);
    for (int i = 1, u; i <= m; i ++){
        cin >> u;
        gro[u] = 1;
        Insert(u);
    }

    int type, u;
    while ( q -- ){
        cin >> type >> u;

        if ( type == 1 )
            if ( gro[u] ) Remove(u), gro[u] = 0;
            else Insert(u), gro[u] = 1;

        if ( type == 2 )
            Que(u);
    }

    return 0;
}
