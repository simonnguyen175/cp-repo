#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const ll oo = 1e18;

int n, m, s, t;
vector<pi> adj[N];
pi ds[N], dt[N];
struct edges{
    int u, v, w;
} edg[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int sqr(int x){
    return 1LL * x * x % MOD;
}

void dijkstra(int x, pi d[]){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++) d[i] = {oo, 0};
    d[x] = {0, 1};
    heap.push({0, x});
    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u].fi ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v].fi > du + w ){
                d[v].fi = du + w;
                d[v].se = d[u].se;
                heap.push({d[v].fi, v});
            }
            else if ( d[v].fi == du + w )
                d[v].se = add(d[v].se, d[u].se);
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edg[i] = {u, v, w};
    }

    dijkstra(s, ds);
    dijkstra(t, dt);

    int ans = sqr(ds[t].se);
    for (int i = 1; i <= m; i ++){
        int u = edg[i].u, v = edg[i].v, w = edg[i].w;
        if ( ds[u].fi + w + dt[v].fi == ds[t].fi && abs(ds[u].fi-dt[v].fi) < w )
            ans = add(ans, -sqr(mul(ds[u].se, dt[v].se)));

        swap(u, v);
        if ( ds[u].fi + w + dt[v].fi == ds[t].fi && abs(ds[u].fi-dt[v].fi) < w )
            ans = add(ans, -sqr(mul(ds[u].se, dt[v].se)));
    }
    for (int i = 1; i <= n; i ++)
        if ( ds[i].fi + dt[i].fi == ds[t].fi && ds[i].fi == dt[i].fi )
            ans = add(ans, -sqr(mul(ds[i].se, dt[i].se)));

    cout << ans;

    return 0;
}
