#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define simon "LCA"
using namespace std;
const int N = 2e5 + 5;

int n, m, p[N][20], d[N];
vector<int> adj[N];

int mu(int x){
    int res = 1;
    for (int i=1; i<=x; i++)
        res *= 2;
    return res;
}

void dfs(int u, int pu){
    for (auto v : adj[u]){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        int e;
        for (int t=1; t<20; t++){
            if ( (1<<t) > d[v] ) break;
            else e = p[v][t-1];
            p[v][t] = p[e][t-1];
        }
        dfs(v, u);
    }
}

int lca(int x, int y) {
    for (int k = 19; k >= 0; k--)
        if ( d[p[x][k]] >= d[y] )
            x = p[x][k];

    for (int k = 19; k >= 0; k--)
        if ( d[p[y][k]] >= d[x] )
            y = p[y][k];

    for (int k = 19; k >= 0; k--)
        if ( p[x][k] != p[y][k]) {
            x = p[x][k];
            y = p[y][k];
        }

    while (x != y) {
        x = p[x][0];
        y = p[y][0];
    }

    return x;
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> m;
    for (int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for (int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        if ( u == 1 || v == 1 ) cout << 1 << '\n';
        else cout << lca(u, v) << '\n';
    }

    return 0;
}
