#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n, m;
struct edges{
    int u, v, l, r, id;
} edg[N];
vector<pi> adj[N];
int h[N], p[N][22], mxl[N][22];
pi par[N];
int root[N], ans[N];

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        p[v][0] = u;
        mxl[v][0] = edg[it.se].l;
        par[v] = {u, it.se};
        h[v] = h[u] + 1;
        dfs(v, u);
    }
}

int getmxl(int u, int v){
    int res = 0;

    if ( h[u] < h[v] ) swap(u, v);
    for (int i = 18; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] ){
            res = max(res, mxl[u][i]);
            u = p[u][i];
        }

    if ( u == v ) return res;

    for (int i = 18; i >= 0; i --)
        if ( p[u][i] != p[v][i] ){
            res = max({res, mxl[u][i], mxl[v][i]});
            u = p[u][i], v = p[v][i];
        }

    return max({res, mxl[u][0], mxl[v][0]});
}

int getroot(int u){
    if ( u == root[u] ) return u;
    else return root[u] = getroot(root[u]);
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        edg[i] = {u, v, l, r, i};
    }

    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1; i <= n; i ++){
        h[i] = 0, par[i] = {0, 0};
        for (int j = 0; j <= __lg(n); j ++)
            p[i][j] = mxl[i][j] = 0;
    }

    for (int i = 1; i < n; i ++){
        int u = edg[i].u, v = edg[i].v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    h[1] = 1;
    dfs(1, 0);

    for (int j = 1; j <= 18; j ++)
    for (int i = 1; i <= n; i ++){
        p[i][j] = p[p[i][j-1]][j-1];
        mxl[i][j] = max(mxl[i][j-1], mxl[p[i][j-1]][j-1]);
    }

    /// chinh L
    for (int i = n; i <= m; i ++){
        int u = edg[i].u, v = edg[i].v;
        int nl = getmxl(u, v);
        edg[i].l = max(edg[i].l, nl + 1);
    }

    /// chinh R
    sort(edg + n, edg + m + 1, [&](edges a, edges b){
        return a.r < b.r;
    });
    for (int i = 1; i <= n; i ++) root[i] = i;
    for (int i = n; i <= m; i ++){
        int u = edg[i].u, v = edg[i].v, r = edg[i].r;

        u = getroot(u), v = getroot(v);

        vector<int> cont;
        while ( u != v ){
            if ( h[u] < h[v] ) swap(u, v);
            cont.pb(par[u].se);
            root[u] = getroot(par[u].fi);
            u = root[u];
        }

        for (auto it : cont) edg[it].r = min(edg[it].r, r - 1);
    }

    sort(edg + 1, edg + 1 + m, [&](edges a, edges b){
        return a.id < b.id;
    });

    bool ck = 1;
    for (int i = 1; i <= m; i ++)
        if ( edg[i].l > edg[i].r ) { ck = 0; break; }

    if ( !ck ){
        cout << "NO\n"; return;
    }

    sort(edg + 1, edg + 1 + m, [&](edges a, edges b){
        if ( a.l == b.l ) return a.r < b.r;
        else return a.l < b.l;
    });

    set<pi> mset;
    int ptr = 1;
    for (int i = 1; i <= m; i ++){
        while ( ptr <= m && edg[ptr].l <= i )
            mset.insert({edg[ptr].r, edg[ptr].id}), ptr ++;

        if ( !mset.size() ) { cout << "NO\n"; return; }

        pi tmp = *mset.begin();
        if ( tmp.fi < i ) return cout << "NO\n", void();

        ans[tmp.se] = i;
        mset.erase(mset.find(tmp));
    }

    cout << "YES\n";
    for (int i = 1; i <= m; i ++) cout << ans[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
