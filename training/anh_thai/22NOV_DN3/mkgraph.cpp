#include<bits/stdc++.h>
#define pb push_back
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int n, m, cnt;
vector<int> adj[N], g[N];
int lab[N], sz[N];

void dfs(int u){
    lab[u] = cnt;
    sz[cnt] ++;
    for (int v : g[u]) if ( !lab[v] )
        dfs(v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int u = 1; u <= n; u ++){
        adj[u].pb(0);
        adj[u].pb(u);
        adj[u].pb(n+1);
        sort(adj[u].begin(), adj[u].end());
        int v = 0;
        for (int i = 0; i < adj[u].size()-1; i ++)
            if ( adj[u][i] + 1 != adj[u][i+1] )
                v = adj[u][i] + 1;
        if ( v ) g[u].pb(v), g[v].pb(u);
    }

    for (int u = 1; u <= n; u ++) if ( !lab[u] ){
        cnt ++;
        dfs(u);
    }

    int ans = 0;
    while ( (1<<ans) < cnt )
        ans ++;
    cout << ans << '\n';
    for (int i = 0; i < ans; i ++){
        for (int j = 1; j <= n; j ++)
            cout << BIT(lab[j], i);
        cout << '\n';
    }

    return 0;
}
