#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n;
vector<pi> adj[N];
pi d[N];
ll f[N];

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        ll w = it.se;
        if ( v == pu ) continue;
        dfs(v, u);
        ll tmp = d[v].fi + w;
        if ( d[u].fi < tmp ) d[u] = {tmp, d[u].fi};
        else if ( d[u].se < tmp ) d[u] = {d[u].fi, tmp};
    }
}

void go(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        ll w = it.se;
        if ( v == pu ) continue;
        f[v] = f[u] + w;
        if ( d[u].fi == d[v].fi + w )
            f[v] = max(f[v], d[u].se + w);
        else f[v] = max(f[v], d[u].fi + w);
        go(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("treedist.in", "r", stdin);
    freopen("treedist.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dfs(1, 0);
    go(1, 0);

    for (int i = 1; i <= n; i ++)
        cout << max(d[i].fi, f[i]) << '\n';

    return 0;
}
