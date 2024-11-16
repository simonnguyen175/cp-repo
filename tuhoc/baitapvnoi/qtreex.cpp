#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9;

int n, nchain, nbase;
struct gra{
    int v, w, id;
};
vector<gra> adj[N];
int h[N], nchild[N], p[N][15];
pi edg[N];
int chainId[N], chainHead[N], pos[N];
struct node{
    int mx, mn, lazy;
} st[4*N];

void dfs(int u, int pu){
    nchild[u] = 1;
    for (auto it : adj[u]){
        int v = it.v, w = it.w;
        if ( v == pu ) continue;

        h[v] = h[u] + 1;
        dfs(v, u);
        edg[it.id] = {v, w};
        nchild[u] += nchild[v];
        p[v][0] = u;
    }
}

void hld(int u){
    if ( !chainHead[nchain] ) chainHead[nchain] = u;
    chainId[u] = nchain;
    pos[u] = ++nbase;

    int mxv = -1;
    for (auto it : adj[u]){
        int v = it.v;
        if ( v == p[u][0] ) continue;

        if ( mxv == -1 || nchild[v] > nchild[mxv] )
            mxv = v;
    }

    if ( mxv != -1 ) hld(mxv);

    for (auto it : adj[u]){
        int v = it.v;
        if ( v == p[u][0] || v == mxv ) continue;

        nchain ++, hld(v);
    }
}

int lca(int u, int v){
    if ( h[v] > h[u] ) swap(u, v);
    for (int i = 14; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 14; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void Add(int id){
    st[id].lazy ^= 1;
    int tmp = st[id].mn;
    st[id].mn = -st[id].mx;
    st[id].mx = -tmp;
}

void Down(int id){
    if ( !st[id].lazy ) return;
    Add(id*2);
    Add(id*2+1);
    st[id].lazy = 0;
}

void updatePoint(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id].mx = st[id].mn = v;
        st[id].lazy = 0;
        return;
    }
    Down(id);
    int mid = l + r >> 1;
    updatePoint(id*2, l, mid, u, v);
    updatePoint(id*2+1, mid+1, r, u, v);
    st[id].mx = max(st[id*2].mx, st[id*2+1].mx);
    st[id].mn = min(st[id*2].mn, st[id*2+1].mn);
}

void updateRange(int id, int l, int r, int u, int v){
    if ( u > v ) return;
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        Add(id);
        return;
    }
    Down(id);
    int mid = l + r >> 1;
    updateRange(id*2, l, mid, u, v);
    updateRange(id*2+1, mid+1, r, u, v);
    st[id].mx = max(st[id*2].mx, st[id*2+1].mx);
    st[id].mn = min(st[id*2].mn, st[id*2+1].mn);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return -oo;
    if ( u <= l && r <= v ) return st[id].mx;
    Down(id);
    int mid = l + r >> 1;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void Negate(int u, int a){
    int uchain = chainId[u], achain = chainId[a];

    while ( true ){
//        cerr << u << '\n';
        if ( uchain == achain ){
            updateRange(1, 1, n, pos[a]+1, pos[u]);
            break;
        }

        updateRange(1, 1, n, pos[chainHead[uchain]], pos[u]);

        u = p[chainHead[uchain]][0];
        uchain = chainId[u];
    }
}

int Que(int u, int a){
    int uchain = chainId[u], achain = chainId[a];
    int res = -oo;

    while ( true ){
//        cerr << u << ' ';
        if ( uchain == achain ){
            res = max(res, get(1, 1, n, pos[a]+1, pos[u]));
            break;
        }

        res = max(res, get(1, 1, n, pos[chainHead[uchain]], pos[u]));

        u = p[chainHead[uchain]][0];
        uchain = chainId[u];
    }

    return res;
}

void solve(){
    cin >> n;

    nchain = 1, nbase = 0;
    for (int i = 1; i <= n; i ++){
        adj[i].clear();
        chainHead[i] = 0;
    }

    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w, i});
        adj[v].pb({u, w, i});
    }

    h[1] = 1;
    dfs(1, 0);
    hld(1);

    for (int j = 1; j <= __lg(n); j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1; i <= 4*n; i ++) st[i].lazy = 0;
    updatePoint(1, 1, n, 1, -oo);
    for (int i = 1; i < n; i ++)
        updatePoint(1, 1, n, pos[edg[i].fi], edg[i].se);

//    for (int i = 1; i <= n; i ++) cout << chainHead[i] << ' '; cout << '\n';
//    for (int i = 1; i <= n; i ++){
//        cout << h[i] << ' ' << chainId[i] << '\n';
//    }

    string type;
    int u, v;
    while ( cin >> type ){
        if ( type == "DONE" ) break;

        cin >> u >> v;

        if ( type == "CHANGE" ){
//            cerr << "change :\n";
            updatePoint(1, 1, n, pos[edg[u].fi], v);
        }

        if ( type == "NEGATE" ){
//            cerr << "negate :\n";
            int puv = lca(u, v);
//            cerr << u << ' ' << v << ' ' << puv << '\n';
            Negate(u, puv);
            Negate(v, puv);
        }

        if ( type == "QUERY" ){
//            cerr << "query :\n";
            if ( u == v ) { cout << 0 << '\n'; continue; }
            int puv = lca(u, v);
//            cerr << u << ' ' << v << ' ' << puv << '\n';
            cout << max(Que(u, puv), Que(v, puv)) << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("qtreex.inp", "r") ){
        freopen("qtreex.inp", "r", stdin);
        freopen("qtreex.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
