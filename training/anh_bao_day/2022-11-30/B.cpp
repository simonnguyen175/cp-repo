#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n, q;
map<pi, int> mp[N];
int d[N], ans[N], D[N];
vector<int> adj[N];

void dfs(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

void dfs1(int u, int pu){
    for (int v : adj[u]) if ( v != pu ){
        dfs1(v, u);

        if ( mp[u].size() < mp[v].size() ) swap(mp[u], mp[v]);

        for (auto it : mp[v])
            ans[it.fi.fi] += it.se * mp[u][{it.fi.fi, D[it.fi.fi] + 2*d[u] - it.fi.se}];

        for (auto it : mp[v])
            mp[u][it.fi] += it.se;
    }
}

void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) mp[i].clear(), adj[i].clear();

    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= q; i ++){
        int k;
        cin >> k >> D[i];
        for (int j = 1, u; j <= k; j ++)
            cin >> u, mp[u][{i, d[u]}] ++;
        ans[i] = 0;
    }

    dfs1(1, 0);

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("B.inp", "r") ){
        freopen("B.inp", "r", stdin);
        freopen("B.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
