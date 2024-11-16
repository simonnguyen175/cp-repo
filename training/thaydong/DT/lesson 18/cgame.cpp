#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n;
vector<int> adj[N];
int h[N], d[N], f[N];

void dfs(int u, int pu){
    if ( adj[u].size() == 1 && pu )
        d[u] = 0;

    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        dfs(v, u);
        d[u] = min(d[u], d[v] + 1);
    }
}

void dfs1(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        dfs1(v, u);
        f[u] += f[v];
    }

    if ( h[u] >= d[u] ) f[u] = 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= n; i ++)
        d[i] = n + 1;

    dfs(1, 0);

    dfs1(1, 0);

    cout << f[1];

    return 0;
}
