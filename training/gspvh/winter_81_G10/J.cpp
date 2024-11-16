#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

void ckmx(int &a, int b){
    if ( c[a] < c[b] ) a = b;
}

void dfs(int u, int pu){
    par[u] = pu;
    f[u][0].f = u;
    for (auto it : adj[u]){
        int v = it.fi, w = it.se;
        if ( v == pu ) continue;
        dfs(v, u);
        for (int i = 0; i <= k; i ++)
            ckmx(f[u][min(w+i, k)], f[v][i]);
    }
}

void dfs1(int u){
    for (int i = 0; i <= adj[u].size()+1; i ++)
    for (int j = 0; j <= k; j ++)
        pre[i][j] = suf[i][j] = 0;

    for (int i = 1; i <= adj[u].size(); i ++){
        int v = adj[u][i-1].fi, w = adj[u][i-1].se;

        for (int j = 1; j <= k; j ++)
            pre[i][j] = pre[i-1][j];

        if ( v != par[u] )
        for (int j = w; j <= k; j ++)
            pre[i][j] = ckmx(pre[i][j], f[v][j-w]);
    }
    for (int i = adj[u].size(); i >= 1; i --){
        int v = adj[u][i-1].fi, w = adj[u][i-1].se;

        for (int j = 1; j <= k; j ++)
            suf[i][j] = suf[i+1][j];

        if ( v != par[u] )
        for (int j = w; j <= k; j ++)
            suf[i][j] = ckmx(suf[i][j], f[v][j-w]);
    }

    g[v][0] = v;
    for (int i = 1; i <= adj[u].size(); i ++){
        int v = adj[u][i-1].fi, w = adj[u][i-1].se;

        if ( v == par[u] ) continue;

        for (int j = 0; j <= k; j ++){
            ckmx(g[v][min(w+j, k)], g[u][j]);
            ckmx(g[v][min(w+j, k)], pre[i-1][j]);
            ckmx(g[v][min(w+j, k)], suf[i+1][j]);
        }

        dfs1(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> sub >> n >> k;
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (int i = 1; i <= n; i ++)
        cin >> c[i];

    dfs(1, 0);
    g[1][0] = 1;
    dfs1(1);

    for (int u = 1; u <= n; u ++){
        int id = 0;

        for (int i = k; i >= 1; i --){
            ckmx(g[u][i], g[u][i+1]);
            s[i] += c[g[u][i]];
        }

        for (int v : adj[u]) if ( x != par[u] ){
            id = 0;
            for (int i = k; i >= 0; i --){
                ckmx(f[v][i], f[v][i+1]);
                s[min(w+i, k)] += c[f[v][min(w+i, k)]] ;
            }
        }

        ll tmp = s[(k+1)/2];
        if ( tmp > ans ){
            res.clear();
            if ( g[u][(k+1)/2] ) res.pb(g[u][(k+1)/2]);
            for (auto it : adj[u]){
                int v = it.fi, w = it.se;
                if ( v == par[u] ) continue;
                if ( f[v][max(0, (k+1)/2-w)] )
                res.pb(f[v][max(0, (k+1)/2-w)]);
            }
        }

        for (int i = 1; i <= n; i ++)

    }

    cout << ans;

    return 0;
}
