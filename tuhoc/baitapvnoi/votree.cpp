#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, q;
vector<int> adj[N];
int st[4 * N], p[N][22], d[N], Log[N];


void dfs(int u, int pu){
    for (int i = 1; i <= Log[d[u]]; i ++)
        p[u][i] = p[ p[u][i-1] ][i-1];

    for (auto v : adj[u]){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int x, int y){
    if ( x == 1 || y == 1 ) return 1;

    if ( d[x] < d[y] ) swap(x, y);

    for (int i = Log[d[x]]; i >= 0; i --)
        if ( d[p[x][i]] >= d[y] )
            x = p[x][i];

    if ( x == y ) return x;

    for (int i = Log[d[x]]; i >= 0; i --)
        if ( p[x][i] != p[y][i] ){
            x = p[x][i];
            y = p[y][i];
        }

    return p[x][0];
}

void buildLca(int id, int l, int r){
    if ( l == r ){
        st[id] = l;
        return;
    }

    int mid = ( l + r ) / 2;

    buildLca(id * 2, l, mid);
    buildLca(id * 2 + 1, mid + 1, r);

    st[id] = lca(st[id * 2], st[id * 2 + 1]);
}

int getLca(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return u;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return lca(getLca(id * 2, l, mid, u, v), getLca(id * 2 + 1, mid + 1, r, u, v));
}

int main(){
    ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(p, 0, sizeof p);
    memset(d, 0, sizeof d);

    Log[1] = 0;
    for (int i = 2; i <= n; i ++)
        Log[i] = Log[i / 2] + 1;

    dfs(1, 0);
    buildLca(1, 1, n);

    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;
        cout << getLca(1, 1, n, u, v) << '\n';
    }

}
