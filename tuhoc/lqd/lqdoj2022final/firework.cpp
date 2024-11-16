#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
vector<int> adj[N];
struct ocas{
    int t, u, c, s;
} oca[N];
struct query{
    int d, u, id;
} que[N];
int sz[N], par[N], used[N], mxh[N];
map<int, int> h[N];
vector<ll> bit[N];
ll ans[N], del[N];

int dfs_size(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( v != pu && !used[v] )
        sz[u] += dfs_size(v, u);
    return sz[u];
}

int centroid(int u, int pu, int nn){
    for (int v : adj[u]) if ( v != pu && !used[v] )
        if ( sz[v] > nn / 2 ) return centroid(v, u, nn);
    return u;
}

void dfs(int u, int pu, int c){
    cout << u << ' ' << h[c][u] << '\n';
    mxh[c] = max(mxh[c], h[c][u]);
    for (int v : adj[u]) if ( v != pu && !used[v] ){
        h[c][v] = h[c][u] + 1;
        dfs(v, u, c);
    }
}

void build(int u, int pu){
    int nn = dfs_size(u, pu);
    int c = centroid(u, pu, nn);
    used[c] = 1;
    par[c] = pu;

    h[c][c] = 0;
    mxh[c] = 0;
    cout << "centroid " << c << " : \n";
    dfs(c, pu, c);
    bit[c].resize(mxh[c] + 2);

    for (int v : adj[c]) if ( v != pu && !used[v] )
        build(v, c);
}

void updB(int id, int u, int v){
    for (; u >= 1; u -= u&-u)
        bit[id][u] += v;
}

ll getB(int id, int u){
    ll res = 0;
    for (; u <= mxh[id] + 1; u += u&-u)
        res += bit[id][u];
    return res;
}

void update(int u, int c, int s){
    for (int v = u; v != 0; v = par[v]) if ( s >= h[v][u] ){
        cout << "update " << v << ' ' << min(mxh[v], s - h[v][u]) << ' ' << c << '\n';
        updB(v, min(mxh[v], s - h[v][u]) + 1, c);
    }
}

ll get(int u){
    ll res = 0;
    int pv = 0;
    for (int v = u; v != 0; v = par[v]){
        cout << "get " << v << ' ' << u << " : \n";
        ll tmp = getB(v, h[v][u] + 1);
        cout << h[v][u] << ' ' << tmp << '\n';
        if ( pv && pv != u ) tmp -= getB(v, h[pv][u] + h[v][pv] + 1);
        cout << h[pv][u] + h[v][pv] << ' ' << tmp << '\n';

        res += tmp;
        pv = v;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("firework.inp", "r", stdin);
    freopen("firework.out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    build(1, 0);

    for (int i = 1; i <= m; i ++){
        int t, u, c, s;
        cin >> t >> u >> c >> s;
        oca[i] = {t, u, c, s};
    }
    sort(oca + 1, oca + 1 + m, [&](ocas a, ocas b){
        return a.t < b.t;
    });

    for (int i = 1; i <= q; i ++)
        cin >> que[i].d >> que[i].u, que[i].id = i;
    sort(que + 1, que + 1 + q, [&](query a, query b){
        return a.d < b.d;
    });

    int ptr = 1;
    for (int i = 1; i <= q; i ++){
        while ( ptr <= m && oca[ptr].t <= que[i].d ){
            cout << "update query " << oca[ptr].u << ' ' << oca[ptr].c << ' ' << oca[ptr].s << '\n';
            update(oca[ptr].u, oca[ptr].c, oca[ptr].s);
            ptr ++;
        }
        cout << "get query " << que[i].d << ' ' << que[i].u << ' ' << del[que[i].u] << '\n';
        ans[que[i].id] = get(que[i].u) - del[que[i].u];
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';

    return 0;
}
