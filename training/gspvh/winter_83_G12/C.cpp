#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 4e3 + 5;

int n;
int d[N][N], sz[N], sz1[N], f[N], ans[N];
vector<int> adj[N], ad[N];

void dfs(int u, int pu){
    d[u][u] = sz[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        for (int i = 1; i <= n; i ++)
            d[u][i] |= d[v][i];
        sz[u] += sz[v];
    }
}

void go(int u, int pu, int x){
    if ( d[x][u] == 1 ) f[u] = 1;
    sz1[u] = 1;

    for (int v : ad[u]) if ( v != pu ){
        go(v, u, x);
        f[u] += f[v];
        sz1[u] += sz1[v];
    }

    if ( u != 1 ){
        int k = max({f[u], sz[x]-f[u], sz1[u]-f[u], n-sz[x]-(sz1[u]-f[u])});
//        cout << u << ' ' << f[u] << ' ' << k << '\n';
        ans[k] ++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("twotrees.inp", "r", stdin);
    freopen("twotrees.out", "w", stdout);

    cin >> n;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        ad[u].pb(v);
        ad[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 2; i <= n; i ++){
//        cout << i << " : \n";
        for (int j = 1; j <= n; j ++) f[j] = 0, sz1[j] = 0;
        go(1, 0, i);
    }

    for (int i = 0; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
