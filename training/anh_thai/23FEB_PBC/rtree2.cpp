#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m, nchain = 1, nbase;
vector<pi> adj[N];
int nchild[N], h[N], p[N][18], edg[N];
int chainHead[N], chainId[N], pos[N], st[4*N];

void dfs(int u, int pu){
    nchild[u] = 1;
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;

        h[v] = h[u] + 1;
        edg[it.se] = v;
        dfs(v, u);

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
        int v = it.fi;
        if ( v == p[u][0] ) continue;

        if ( mxv == -1 || nchild[v] > nchild[mxv] )
            mxv = v;
    }

    if ( mxv != -1 ) hld(mxv);

    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == p[u][0] || v == mxv ) continue;
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

void update(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ) { st[id] ++; return; }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
}

int get(int id, int l, int r, int u){
    if ( l > u || r < u ) return 0;
    if ( l == r ) return st[id];
    int mid = l + r >> 1;
    return st[id] + get(id*2, l, mid, u) + get(id*2+1, mid+1, r, u);
}

void upd(int u, int a){
//    cout << "update " << u << ' ' << a << " : \n";

    int uchain = chainId[u], achain = chainId[a];

    while ( true ){
        if ( uchain == achain ){
            update(1, 1, n, pos[a]+1, pos[u]);
            break;
        }

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

    cin >> n >> m;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    h[1] = 1;

    dfs(1, 0);

    hld(1);

//    for (int i = 1; i <= n; i ++)
//        cout << chainId[i] << ' ';
//    cout << '\n';
//    for (int i = 1; i <= nchain; i ++)
//        cout << chainHead[i] << ' ';
//    cout << '\n';

    for (int j = 1; j <= 17; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    int type, u, v;
    while ( m -- ){
        cin >> type;
        if ( type == 1 ){
            cin >> u >> v;
            int puv = lca(u, v);
            upd(u, puv);
            upd(v, puv);
        }
        else{
            cin >> u;
            cout << get(1, 1, n, pos[edg[u]]) << '\n';
        }
    }

    return 0;
}
