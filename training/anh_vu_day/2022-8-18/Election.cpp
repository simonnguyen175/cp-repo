#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, timeDfs;
vector<int> adj[N];
int tin[N], tout[N], p[N][20], h[N], f[N][2], bit[N];
struct elections{
    int a, b, c;
};
vector<elections> ele[N];

void dfs(int u, int pu){
    tin[u] = ++timeDfs;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
    tout[u] = timeDfs;
}

int lca(int u, int v){
    if ( h[u] <= h[v] ) swap(u, v);
    for (int i = 19; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 19; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void update(int u, int v){
    for (; u <= n; u += u&-u)
        bit[u] += v;
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res += bit[u];
    return res;
}

void go(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        go(v, u);
        f[u][0] += f[v][1];
    }

    f[u][1] = f[u][0];
    for (auto it : ele[u])
        f[u][1] = max(f[u][1], f[u][0] + get(tin[it.a]) + get(tin[it.b]) + it.c);

    update(tin[u], f[u][0]-f[u][1]);
    update(tout[u]+1, f[u][1]-f[u][0]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("in.inp", "r") ){
        freopen("in.inp", "r", stdin);
        freopen("out.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);
    for (int j = 1; j <= 19; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    cin >> m;
    for (int i = 1; i <= m; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        int p = lca(a, b);
        ele[p].pb({a, b, c});
    }

//    for (int i = 1; i <= n; i ++){
//        cout << i << " : \n";
//        for (auto it : ele[i])
//            cout << it.a << ' ' << it.b << ' ' << it.c << '\n';
//    }

    go(1, 0);

    cout << max(f[1][0], f[1][1]);

    return 0;
}
