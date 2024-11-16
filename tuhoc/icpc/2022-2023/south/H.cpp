#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m;
int d[N], h[N];
vector<int> adj[N], cont[N];

void dfs(int u, int pu){
    pi mx;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
        d[u] = max(d[u], d[v] + 1);
        cont[u].pb(d[v] + 1);
        if ( mx.fi <= d[v] ) mx.se = mx.fi, mx.fi = d[v];
        else
            if ( mx.se < d[v] ) mx.se = d[v];
    }

    if ( adj[u].size() >= 2 )
    for (int v : adj[u]){
        if ( v == pu ) continue;
        if ( mx.fi == d[v] ) h[v] = 2 + mx.se;
        else h[v] = 2 + mx.fi;
    }
}

void dfs1(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        //cout << h[v] << ' ' << h[u] + 1 << '\n';
        h[v] = max(h[v], h[u] + 1);
        dfs1(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("H.inp", "r") ){
        freopen("H.inp", "r", stdin);
        freopen("H.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    memset(h, 0, sizeof h);
    memset(d, 0, sizeof d);
    dfs(1, 0);

    //for (int i = 1; i <= n; i ++) cout << h[i] << ' '; cout << '\n';

    dfs1(1, 0);

    //for (int i = 1; i <= n; i ++) cout << h[i] << ' '; cout << '\n';

    for (int i = 1; i <= n; i ++) cont[i].pb(h[i]);

    for (int i = 1; i <= n; i ++) sort(cont[i].begin(), cont[i].end());

//    for (int i = 1; i <= n; i ++){
//        cout << i << " : ";
//        for (int x : cont[i]) cout << x << ' ';
//        cout << '\n';
//    }

    for (int i = 1; i <= m; i ++){
        int x, t;
        cin >> x >> t;
        auto it = upper_bound(cont[x].begin(), cont[x].end(), t);
        if ( it == cont[x].end() ) cout << 0 << '\n';
        else cout << (cont[x].end() - it) << '\n';
    }

    return 0;
}
