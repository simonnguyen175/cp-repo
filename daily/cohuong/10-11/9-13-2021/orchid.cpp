#include<bits/stdc++.h>
#define simon "orchid"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n , g[N];
pair<int, int> f[N];
vector<pair<int, int>> adj[N];

void dfs1(int u, int pu){
	for(auto it : adj[u]){
		int v = it.fi, w = it.se;
		if ( v == pu ) continue;
	    dfs1(v, u);
	    int tmp = f[v].fi + w;
        if ( tmp > f[u].fi ) f[u] = {tmp, f[u].fi};
        else if ( tmp > f[u].se ) f[u] = {f[u].fi, tmp};
	}
}

void dfs2(int u, int pu){
	for(auto it : adj[u]){
		int v = it.fi, w = it.se;
		if ( v == pu ) continue;
		int tmp = ( f[u].fi != f[v].fi + w ? f[u].fi : f[u].se );
		g[v] = max(g[u], tmp) + w;
		dfs2(v, u);
	}
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1 ; i < n ; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dfs1(1, 0);

    dfs2(1, 0);

    for(int i = 1; i <= n; i ++)
        cout << max(g[i], f[i].fi) << ' ';

    return 0;
}

