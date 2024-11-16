#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, m, Time;
int Par[N], Rank[N], low[N], num[N], dp[N][3], vis[N];
vector<int> adj[N], g[N];
vector<pi> Bridge;

int Find(int u) {
	if ( u == Par[u] ) return u;
	return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);

    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[v] == Rank[u] ) Rank[u] ++;
    }
}

void Dfs(int u , int pa) {
	num[u] = low[u] = ++Time;
	for(int v : adj[u]){
		if ( v == pa ) continue;
		if ( !num[v] ){
			Dfs(v , u);
			low[u] = min(low[u] , low[v]);
			if ( low[v] != num[v] ) Join(u, v);
			else Bridge.pb({u , v});
		} else low[u] = min(num[v] , low[u]);
	}
}

void Go(int u) {
	int tmp = oo;
	vis[u] = 1;
	dp[u][0] = 1 , dp[u][2] = 0 , dp[u][1] = 0;
	for(int v : g[u]){
		if(vis[v]) continue;
		Go(v);
		dp[u][0] += min({dp[v][0] , dp[v][1] , dp[v][2]});
		dp[u][2] = min(oo, dp[u][2] + dp[v][1]);
		dp[u][1] = min(oo, dp[u][1] + min(dp[v][0] , dp[v][1]));
		tmp = min(tmp , dp[v][0] - min(dp[v][0] , dp[v][1]));
	}
	dp[u][1] += tmp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    if ( fopen("history.in", "r") ){
        freopen("history.in", "r", stdin);
        freopen("history.out", "w", stdout);
    }

    cin >> n >> m;
	for(int i = 1 ; i <= m ; i++){
		int u , v;
		cin >> u >> v;
		adj[u].pb(v) ;
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;

	for (int i = 1; i <= n; i ++)
		if( !num[i] ) Dfs(i, 0);

	for (auto x : Bridge){
		int u = Find(x.fi), v = Find(x.se);
		if ( u != v ) g[u].pb(v), g[v].pb(u);

    }

//    for (int i = 1; i <= n; i ++) cout << Par[i] << '\n';

	int ans = 0;
	for (int i = 1; i <= n; i ++)
		if(  !vis[i] && i == Par[i] ){
            Go(i);
            ans += min(dp[i][0] , dp[i][1]);
		}

	cout << ans;
	return 0;
}


