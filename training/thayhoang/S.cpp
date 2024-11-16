#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, m, q;
vector<int> adj[N];
struct rng{
    int l, r, u;
    ll t;

    bool operator < (const rng a) const{
        return l < a.l;
    }
};
set<rng> cont;
int a[N], h[N], p[N][20];
ll sum[N], st[4*N];

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

void update(int id, int l, int r, int u, int v, ll val){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id] += val;
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
}

ll get(int id, int l, int r, int u){
    if ( l > u || r < u ) return 0;
    if ( l == r ) return st[id];
    int mid = l + r >> 1;
    return st[id] + get(id*2, l, mid, u) + get(id*2+1, mid+1, r, u);
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 18; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 18; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> q;

    for (int i = 1; i <= m; i ++)
        cin >> a[i];

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int j = 1; j <= 18; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1; i <= m; i ++){
        int j = i;
        while ( j < m && a[j+1] == a[i] )
            j ++;
        cont.insert({i, j, a[i], 0});
        i = j;
    }

    while ( q -- ){
        char type;
        cin >> type;

        if ( type == 't' ){
            int l, r, u;
            cin >> l >> r >> u;

            if ( l > r ) continue;

            vector<rng> nseg;

            auto lef = cont.upper_bound({l, 0, 0, 0});
            lef --;
            if ( (*lef).l <= l-1 ) nseg.pb({(*lef).l, l-1, (*lef).u, (*lef).t});

            auto rig = cont.upper_bound({r, 0, 0, 0});
            rig --;
            if ( (*rig).r >= r+1 ) nseg.pb({r+1, (*rig).r, (*rig).u, (*rig).t});

            nseg.pb({l, r, u, sum[u]});

            /// del seg
            vector<rng> dseg;
            auto it = lef;
            rig ++;
            while ( it != rig ){
                update(1, 1, m, max(l, (*it).l), min(r, (*it).r), sum[(*it).u] - (*it).t);
                update(1, 1, m, max(l, (*it).l), min(r, (*it).r), -(h[u] + h[(*it).u] - 2 * h[lca(u, (*it).u)]));
                it = cont.erase(it);
            }

            /// add seg
            for (auto x : nseg)
                cont.insert(x);
        }

        if ( type == 'e' ){
            int u;
            ll x;
            cin >> u >> x;
            sum[u] += x;
        }

        if ( type == 'q' ){
            int u;
            cin >> u;
            auto it = cont.upper_bound({u, 0, 0, 0});
            it --;

            cout << get(1, 1, m, u) + sum[(*it).u] - (*it).t << '\n';
        }
    }

    return 0;
}
