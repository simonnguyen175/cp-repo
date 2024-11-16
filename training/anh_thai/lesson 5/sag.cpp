#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, k, m;
vector<pi> edges;
vector<int> G[N], adj[N], ad[N];
int f[N], g[N], ans[N], root[N];

void dfs(int u){
    for (int v : G[u]) if ( !root[v] ){
        root[v] = root[u];
        dfs(v);
    }
}

void dag1(int u){
    f[u] = 1;
    for (int v : adj[u]){
        if ( f[v] == -1 ) dag1(v);
        f[u] = max(f[u], f[v] + 1);
    }
}

void dag2(int u){
    g[u] = 1;
    for (int v : ad[u]){
        if ( g[v] == -1 ) dag2(v);
        g[u] = max(g[u], g[v] + 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("sag.inp", "r") ){
        freopen("sag.inp", "r", stdin);
        freopen("sag.out", "w", stdout);
    }

    cin >> n >> k >> m;
    for (int i = 1; i <= m; i ++){
        int x, y;
        char c;
        cin >> x >> c >> y;
        if ( c == '<' ) edges.pb({x, y});
        if ( c == '>' ) edges.pb({y, x});
        if ( c == '=' ) G[x].pb(y), G[y].pb(x);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if ( !root[i] ) root[i] = ++cnt, dfs(i);

    for (auto it : edges){
        adj[root[it.fi]].pb(root[it.se]);
        ad[root[it.se]].pb(root[it.fi]);
    }

    memset(f, -1, sizeof f);
    for (int i = 1; i <= cnt; i ++)
        if ( f[i] == -1 ) dag1(i);

    memset(g, -1, sizeof g);
    for (int i = 1; i <= cnt; i ++)
        if ( g[i] == -1 ) dag2(i);

    for (int i = 1; i <= cnt; i ++)
        if ( f[i] + g[i] - 1 == k ) ans[i] = 'a' + g[i] - 1;

    for (int i = 1; i <= n; i ++)
        if ( !ans[root[i]] ) cout << '?';
        else cout << (char) ans[root[i]];

    return 0;
}
