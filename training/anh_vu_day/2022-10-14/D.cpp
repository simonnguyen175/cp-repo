#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define pi pair<int, int>
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e9;

int n, d;
pi h[N];
int hc[N], dis[N][21], sz[N], par[N], used[N], near[N];
vector<int> adj[N];

void dfstree(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        h[v].fi = h[u].fi + 1;
        h[v].se = v;
        dfstree(v, u);
    }
}

int dfs(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( !used[v] && v != pu )
        sz[u] += dfs(v, u);
    return sz[u];
}

int centroid(int u, int pu, int n){
    for (int v : adj[u]) if ( !used[v] && v != pu )
        if ( sz[v] > n/2 ) return centroid(v, u, n);
    return u;
}

void dfs1(int u, int pu, int c, int d){
    dis[u][++hc[u]] = d;
    for (int v : adj[u]) if ( !used[v] && v != pu )
        dfs1(v, u, c, d + 1);
}

void build(int u, int pu){
    int n = dfs(u, pu);
    int c = centroid(u, pu, n);

    par[c] = pu;
    dfs1(c, pu, c, 0);
    used[c] = 1;

    for (int v : adj[c]) if ( !used[v] )
        build(v, c);
}

void add(int u){
    for (int v = u, i = 1; v > 0; v = par[v], i ++)
        near[v] = min(near[v], dis[u][i]);
}

int get(int u){
    int mn = oo;
    for (int v = u, i = 1; v > 0; v = par[v], i ++)
        mn = min(mn, near[v] + dis[u][i]);
    return mn;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> d;
    for (int i = 2, p; i <= n; i ++){
        cin >> p;
        ++p;
        adj[p].pb(i);
        adj[i].pb(p);
    }

    dfstree(1, 0);

    for (int i = 1; i <= n; i ++) near[i] = oo;

    build(1, 0);

    for (int i = 1; i <= n; i ++)
        reverse(dis[i] + 1, dis[i] + 1 + hc[i]);

    h[1].se = 1;
    sort(h + 1, h + 1 + n, greater<pi>());

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int u = h[i].se;
        if ( get(u) >= d )
            ans ++, add(u);
    }

    cout << ans;

    return 0;
}
