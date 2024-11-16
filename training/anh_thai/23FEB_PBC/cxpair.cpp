#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m, timeDfs;
vector<pi> adj[N], bri;
vector<int> g[N];
int num[N], low[N], vis[N];

void dfs(int u, int pu){
    num[u] = low[u] = ++timeDfs;
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        if ( !num[v] ){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if ( low[v] == num[v] ) bri.pb({u, v});
        }
        else low[u] = min(low[u], num[v]);
    }
}

int getsz(int u){
    int res = 1;
    vis[u] = 1;
    for (int v : g[u]) if ( !vis[v] )
        res += getsz(v);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    for (int i = 1; i <= n; i ++) if ( !num[i] )
        dfs(i, 0);

    for (auto it : bri)
        g[it.fi].pb(it.se), g[it.se].pb(it.fi);

    ll ans = 0;
    for (int i = 1; i <= n; i ++) if ( !vis[i] ){
        int tmp = getsz(i);
        ans += 1ll * tmp * (tmp - 1) / 2 - tmp + 1;
    }

    cout << ans;

    return 0;
}
