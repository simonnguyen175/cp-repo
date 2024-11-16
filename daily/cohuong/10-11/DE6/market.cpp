#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e4 + 5;

int n, c, q, K;
vector<int> adj[N], mar[N];
vector<pi> que[N];
int h[N], d[N], p[N][21], ans[N];
queue<int> Q;

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
        p[v][0] = u;
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void anal(int x){
    if ( que[x].size() <= K ){
        for (int u : mar[x])
        for (auto it : que[x])
            ans[it.se] = min(ans[it.se], h[u] + h[it.fi] - 2 * h[lca(u, it.fi)]);
    }
    else{
        for (int i = 1; i <= n; i ++) d[i] = -1;
        for (int u : mar[x]) d[u] = 0, Q.push(u);
        while ( Q.size() ){
            int u = Q.front();
            Q.pop();

            for (int v : adj[u]) if ( d[v] == -1 )
                d[v] = d[u] + 1, Q.push(v);
        }

        for (auto it : que[x])
            ans[it.se] = min(ans[it.se], d[it.fi]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("market.in", "r") ){
        freopen("market.in", "r", stdin);
        freopen("market.out", "w", stdout);
    }

    cin >> n >> c;

    for (int i = 1, x; i <= n; i ++) cin >> x, mar[x].pb(i);

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int u, x;
        cin >> u >> x;
        que[x].pb({u, i});
    }

    K = sqrt(q);

    memset(ans, 0x3f, sizeof ans);

    for (int x = 1; x <= c; x ++)
        anal(x);

    for (int i = 1; i <= q; i ++) cout << ( ans[i] > n ? -1 : ans[i] ) << '\n';

    return 0;
}
