#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, m;
map<int, int> dis[N];
int sz[N], par[N], used[N], near[N];
vector<int> adj[N];

int dfs(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( !used[v] && v != pu )
        sz[u] += dfs(v, u);
    return sz[u];
}

int centroid(int u, int pu, int n){
    for (int v : adj[u]) if ( !used[v] && v != pu )
        if ( sz[v] > n/2 ) return centroid(v, u, n);
    return u;
}

void dfs1(int u, int pu, int c){
    for (int v : adj[u]) if ( !used[v] && v != pu ){
        dis[c][v] = dis[c][u] + 1;
        dfs1(v, u, c);
    }
}

void build(int u, int pu){
    int n = dfs(u, pu);
    int c = centroid(u, pu, n);

    par[c] = pu;
    dis[c][c] = 0;
    dfs1(c, pu, c);
    used[c] = 1;

    for (int v : adj[c]) if ( !used[v] )
        build(v, c);
}

void add(int u){
    for (int v = u; v > 0; v = par[v])
        near[v] = min(near[v], dis[v][u]);
}

int get(int u){
    int mn = oo;
    for (int v = u; v > 0; v = par[v])
        mn = min(mn, near[v] + dis[v][u]);
    return mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 2, u, v; i <= n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++) near[i] = oo;
    build(1, 0);

    add(1);

    for (int i = 1; i <= m; i ++){
        int t, u;
        cin >> t >> u;
        if ( t == 1 ) add(u);
        else{
            cout << get(u) << '\n';
        }
    }

    return 0;
}
