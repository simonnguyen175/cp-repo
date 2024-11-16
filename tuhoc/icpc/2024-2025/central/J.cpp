#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, q;
vector<int> adj[N];
int h[N], p[N][25];

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        p[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    int k = h[u] - h[v];
    for (int j = 0; (1 << j) <= k; j ++)
        if (k >> j & 1)
            u = p[u][j];
//    cout << u << ' ' << v << '\n';

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            u = p[u][i];
            v = p[v][i];
        }

    return p[u][0];
}

bool chacon(int x, int y){
    int pxy = lca(x, y);
//    cout << x << ' ' << y << ' ' << pxy << '\n';
    if ( pxy == x ) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("tmp.inp", "r") ){
        freopen("tmp.inp", "r", stdin);
        freopen("tmp.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);

    for (int i = 1; i <= 20; i ++)
    for (int u = 1; u <= n; u ++)
        p[u][i] = p[p[u][i-1]][i-1];

    while ( q -- ){
        int x, y, z;
        cin >> x >> y >> z;

        int pxz = lca(x, z);

//        cout << pxz << ' ' << y << '\n';
//        cout << chacon(y, x) << '\n' << chacon(y, z) << '\n' << chacon(pxz, y) << '\n';

        if ( (chacon(y, x) || chacon(y, z)) && chacon(pxz, y) ){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

    return 0;
}

