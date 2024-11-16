#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define BIT(x,k) ((x>>k)&1)
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int N = 55;
const int oo = 1e9;

int n, m;
vector<pi> adj[N];
int d[N][N], f[N][13][1<<13], vis[N][13][1<<13];

void Floyd(){
    for (int k = 1; k <= n; k ++)
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    cout << ( d[1][n] == oo ? -1 : d[1][n] ) << '\n';
}

void dfs(int u, int l, int t){
    vis[u][l][t] = 1;

    if ( u == n ){
        f[u][l][t] = 0;
        return;
    }

    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        int nl = ( l + w ) % 13;

        if ( BIT(t, nl) ) continue;
        int nt = t | (1<<nl);
        if ( !vis[v][nl][nt] ) dfs(v, nl, nt);

        if ( f[v][nl][nt] == -1 ) continue;

        if ( f[u][l][t] == -1 ) f[u][l][t] = w + f[v][nl][nt];
        else f[u][l][t] = min(f[u][l][t], w + f[v][nl][nt]);
    }
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        adj[i].clear();
        for (int j = 1; j <= n; j ++)
            d[i][j] = oo;
        d[i][i] = 0;
    }
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        d[u][v] = min(d[u][v], w);
    }

    string type;
    cin >> type;
    if ( type == "False" ) Floyd();
    else{
        for (int i = 1; i <= n; i ++)
        for (int j = 0; j < 13; j ++)
        for (int t = 0; t < (1<<13); t ++){
            f[i][j][t] = -1;
            vis[i][j][t] = 0;
        }
        dfs(1, 0, 1);
        cout << f[1][0][1] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("path13.inp", "r") ){
//        freopen("path13.inp", "r", stdin);
//        freopen("path13.out", "w", stdout);
//    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
