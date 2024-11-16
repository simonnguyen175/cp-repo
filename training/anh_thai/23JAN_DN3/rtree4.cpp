#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, nbase, nchain = 1, q;
vector<int> adj[N];
int h[N], child[N], p[N][20], chainHead[N], chainId[N], pos[N];
struct node{
    int sodd, seven, lazy;
} st[4*N];

void dfs(int u, int pu){
    child[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
        child[u] += child[v];
    }
}

void hld(int u){
    if ( !chainHead[nchain] ) chainHead[nchain] = u;
    chainId[u] = nchain;
    pos[u] = ++nbase;

    int mxv = -1;
    for (int v : adj[u]) if ( v != p[u][0] )
        if ( mxv == -1 || child[v] > child[mxv] )
            mxv = v;

    if ( mxv != -1 ) hld(mxv);

    for (int v : adj[u]) if ( v != p[u][0] && v != mxv ){
        nchain ++;
        hld(v);
    }
}

int lca(int u, int v){
    if ( h[v] > h[u] ) swap(u, v);

    for (int i = 17; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 17; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void build(int id, int l, int r){
    if ( l == r ){
        if ( l != 1 ) st[id].seven = 1;
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].seven = st[id*2].seven + st[id*2+1].seven;
}

void add(int id){
    st[id].lazy ^= 1;
    int tmp = st[id].sodd;
    st[id].sodd = st[id].seven;
    st[id].seven = tmp;
}

void down(int id){
    if ( !st[id].lazy ) return;
    add(id*2);
    add(id*2+1);
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        add(id);
        return;
    }

    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);

    st[id].sodd = st[id*2].sodd + st[id*2+1].sodd;
    st[id].seven = st[id*2].seven + st[id*2+1].seven;
}

void upd(int u, int a){
    if ( u == a ) return;
    int uchain = chainId[u], achain = chainId[a];

    while ( true ){
        if ( uchain == achain ){
//            cout << "update " << pos[a]+1 << ' ' << pos[u] << '\n';
            update(1, 1, n, pos[a]+1, pos[u]);
            break;
        }

//        cout << "update " << pos[chainHead[uchain]] << ' ' << pos[u] << '\n';
        update(1, 1, n, pos[chainHead[uchain]], pos[u]);

        u = p[chainHead[uchain]][0];
        uchain = chainId[u];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> q;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    h[1] = 1;
    dfs(1, 0);
    for (int j = 1; j <= 17; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];
    hld(1);
    build(1, 1, n);

//    for (int i = 1; i <= n; i ++)
//        cout << h[i] << ' ' << pos[i] << ' ' << chainId[i] << '\n';

//    cout << st[1].seven << '\n';
    while ( q -- ){
        int u, v;
        cin >> u >> v;
        int puv = lca(u, v);
        upd(u, puv);
        upd(v, puv);
        cout << st[1].sodd << '\n';
    }

    return 0;
}
