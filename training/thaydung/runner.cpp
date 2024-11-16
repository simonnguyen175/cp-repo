#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 4e5 + 5;

int n;
int h[N], p[N][20], d[N];
vector<int> adj[N];

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 19; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if  ( u == v ) return u;

    for (int i = 19; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void dfs1(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        dfs1(v, u);
        d[u] += d[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    freopen("runner.inp", "r", stdin);
//    freopen("runner.out", "w", stdout);

    cin >> n;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);

    for (int j = 1; j <= 19; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1; i < n; i ++){
        int puv = lca(i, i + 1);
        d[i] ++, d[i+1] ++;
        d[puv] --, d[p[puv][0]] --;
    }

    dfs1(1, 0);

    for (int i = 1; i <= n; i ++)
        cout << d[i] << '\n';

    return 0;
}
