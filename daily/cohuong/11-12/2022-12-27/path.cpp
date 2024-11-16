#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, m, W, na, nb;
struct edge{
    int u, v, w;
};
vector<edge> edg;
int par[N], sz[N], sz_a[N], sz_b[N];
ll ans = 0;

int Find(int u){
    if ( u == par[u] ) return u;
    else return par[u] = Find(par[u]);
}

void Join(int u, int v, int w){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( sz[u] < sz[v] ) swap(u, v);
        if ( w == W ) ans += 1ll * sz_a[u] * sz_b[v] + 1ll * sz_b[u] * sz_a[v];
        par[v] = u;
        sz[u] += sz[v];
        sz_a[u] += sz_a[v];
        sz_b[u] += sz_b[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("path.inp", "r", stdin);
    freopen("path.out", "w", stdout);

    cin >> n >> m >> W >> na >> nb;
    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        edg.pb({u, v, w});
    }

    sort(edg.begin(), edg.end(), [&](edge a, edge b){
        return a.w < b.w;
    });

    for (int i = 1, u; i <= na; i ++){
        cin >> u;
        sz_a[u] = 1;
    }

    for (int i = 1, u; i <= nb; i ++){
        cin >> u;
        sz_b[u] = 1;
    }

    for (int i = 1; i <= n; i ++) par[i] = i, sz[i] = 1;
    for (auto it : edg)
        Join(it.u, it.v, it.w);

    cout << ans;

    return 0;
}
