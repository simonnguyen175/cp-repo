#include<bits/stdc++.h>
#define simon "coci1920_r5_putovanje"
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n;
vector<pi> adj[N];
int h[N], p[N][22], d[N], cnt[N];
ll c1[N], c2[N];

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        if ( v == pu ) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if ( h[u] < h[v] ) swap(u, v);

    for (int i = 20; i >= 0; i --)
        if ( h[p[u][i]] >= h[v] )
            u = p[u][i];

    if ( u == v ) return u;

    for (int i = 20; i >= 0; i --)
        if ( p[u][i] != p[v][i] )
            u = p[u][i], v = p[v][i];

    return p[u][0];
}

void go(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi, id = it.se;
        if ( v == pu ) continue;
        go(v, u);
        cnt[id] = d[v];
        d[u] += d[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v >> c1[i] >> c2[i];
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    h[1] = 1;
    dfs(1, 0);

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++)
        p[i][j] = p[p[i][j-1]][j-1];

    for (int i = 1; i < n; i ++){
        int u = i, v = i + 1, puv = lca(u, v);
//        cout << u << ' ' << v << ' ' << puv << '\n';
        d[u] ++, d[puv] --;
        d[v] ++, d[puv] --;
    }

//    for (int i = 1; i <= n; i ++) cout << d[i] << ' '; cout << '\n';

    go(1, 0);

//    for (int i = 1; i <= n; i ++) cout << d[i] << ' '; cout << '\n';

    ll ans = 0;
    for (int i = 1; i < n; i ++)
        ans += min(1LL * c1[i] * cnt[i], c2[i]);

    cout << ans;

    return 0;
}
