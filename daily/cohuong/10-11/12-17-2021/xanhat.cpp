#include<bits/stdc++.h>
#define simon "xanhat"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n , g[N];
pair<int, int> f[N];
vector<int> adj[N];

void dfs1(int u, int pu){
	for(int v : adj[u]){
		if ( v == pu ) continue;
	    dfs1(v, u);
	    int tmp = f[v].fi + 1;
        if ( tmp > f[u].fi ) f[u] = {tmp, f[u].fi};
        else if ( tmp > f[u].se ) f[u] = {f[u].fi, tmp};
	}
}

void dfs2(int u, int pu){
	for(int v : adj[u]){
		if ( v == pu ) continue;
		int tmp = ( f[u].fi != f[v].fi + 1 ? f[u].fi : f[u].se );
		g[v] = max(g[u], tmp) + 1;
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
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs1(1, 0);

    dfs2(1, 0);

    for(int i = 1; i <= n; i ++)
        cout << max(g[i], f[i].fi) << '\n';

    return 0;
}

