#include<bits/stdc++.h>
#define simon "equake"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e12;

int n, s;
ll par[N][21], h[N], p[N], c[21], w[21];
ll d[N], dist[N][21], need[1<<20], st[1<<20];
pair<ll, ll> f[1<<20];
vector<pi> adj[N];

void dfs(int u, int pu){
     for (int i = 1; i <= 20; i ++)
        par[u][i] = par[par[u][i-1]][i-1];

     for (auto it : adj[u]){
        int v = it.fi, we = it.se;
        if ( v == pu ) continue;
        h[v] = h[u] + 1;
        d[v] = d[u] + we;
        par[v][0] = u;
        dfs(v, u);
     }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    int diff = h[u] - h[v];

    for (int i = 20; i >= 0; i --)
        if ( BIT(diff, i) )
            u = par[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( par[u][i] != par[v][i] ){
            u = par[u][i];
            v = par[v][i];
        }

    return par[u][0];
}

void init(){
    cin >> n >> s;

    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= s; i ++) cin >> c[i];
    for (int i = 1; i <= s; i ++) cin >> w[i];
    for (int i = 1; i <= n - 1; i ++){
        int u, v, we;
        cin >> u >> v >> we;
        adj[u].pb({v, we});
        adj[v].pb({u, we});
    }

    h[1] = d[1] = 0;
    dfs(1, 0);

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= s; j ++)
        dist[i][j] = d[i] + d[c[j]] - 2 * d[lca(i, c[j])];

    for (int t = 1; t < (1<<s); t ++)
        for (int i = 1; i <= s; i ++)
            if ( BIT(t, i-1) )
                need[t] += w[i];
}

bool check(ll mid){
    for (int t = 0; t < (1<<s); t ++)
        f[t].fi = f[t].se = st[t] = 0;

    for (int i = 1; i <= n; i ++){
        int mask = 0;
        for (int j = 1; j <= s; j ++)
            if ( dist[i][j] <= mid ){

                mask |= (1<<(j-1));
            }
        f[mask].fi += p[i];
        f[mask].se += p[i];
        st[mask] += p[i];
    }

    for (int i = 1; i <= s; i ++)
        for (int t = (1<<s) - 1; t >= 1; t --)
            if ( BIT(t, i-1) )
                f[t^(1<<(i-1))].se += f[t].se;

    for (int i = 1; i <= s; i ++)
        for (int t = 1; t < (1<<s); t ++)
            if ( !BIT(t, i-1) )
                f[t^(1<<(i-1))].fi += f[t].fi;

    for (int t = 1; t < (1<<s); t ++)
        if ( f[t].fi + f[t].se - st[t] < need[t] )
            return false;

    return true;
}

void solve(){
    ll lo = 0, hi = oo, res;
    while ( lo <= hi ){
        ll mid = ( lo + hi ) / 2;
        if ( check(mid) ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    init();

    solve();

    return 0;
}
