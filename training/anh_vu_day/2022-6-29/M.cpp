#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m;
vector<int> cont, g[N];
int h[N], f[N], d[N], p[N][21];
queue<int> q;

void dfs(int u, int pu){
    for (int v : g[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        f[v] = f[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[v] > h[u] ) swap(u, v);
    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            u = p[u][i];
            v = p[v][i];
        }

    return p[u][0];
}

void reset(){
    for (int i = 1; i <= n; i ++) d[i] = -1;
    for (int v : cont) q.push(v), d[v] = 0;

    while ( q.size() ){
        int u = q.front();
        q.pop();
        for (int v : g[u]) if ( d[v] == -1 )
            d[v] = d[u] + 1, q.push(v);
    }

    for (int i = 1; i <= n; i ++)
        f[i] = min(f[i], d[i]);

    cont.clear();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1, t, v; i <= m; i ++){
        cin >> t >> v;
        if ( t == 1 ){
            if ( cont.size() == 320 ) reset();
            cont.pb(v);
        }
        else{
            int tmp = n+1;
            for (int u : cont){
                int puv = lca(u, v);
                tmp = min(tmp, h[u] + h[v] - 2*h[puv]);
            }
            cout << min(tmp, f[v]) << '\n';
        }
    }

    return 0;
}
