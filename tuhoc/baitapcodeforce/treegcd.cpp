#include<bits/stdc++.h>
#define simon "treegcd"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;
const int N = 105;
const int MOD = 1e9 + 7;

int n, m;
ll f[N][N*100];
vector<int> adj[N], ke[N*100];

void dfs(int u, int pu){
	for(auto v : adj[u]){
        if ( v == pu ) continue;
        dfs(v, u);
	}

	for (int i = 1; i <= m; i ++){
        f[u][i] = 1;
	    for(auto v : adj[u]){
	    	if( v == pu ) continue;
	    	ll tmp = 0;
     	    for(auto x : ke[i])
                tmp = (tmp + f[v][x]) % MOD;
     	    f[u][i] = (f[u][i] * tmp) % MOD;
     	}
	}
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= m; i ++)
      for (int j = 1; j <= m; j ++)
            if ( __gcd(i , j) != 1 )
                ke[i].pb(j);

    dfs(1, 0);

    ll ans = 0;
    for(int i = 1; i <= m; i ++)
        ans = (ans + f[1][i]) % MOD;

    cout << ans;

    return 0;
}

