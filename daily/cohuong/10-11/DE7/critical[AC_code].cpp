#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 2e4 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("critical.in" , "r" , stdin);
	freopen("critical.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , vis[N] , Time = 0 , low[N] , num[N] , S , sz[N];
ll ans = 0;
vector<int> adj[N];

void Go(int u) {
	S++ ,vis[u] = 1;
	for(auto v : adj[u])
		if(!vis[v]) Go(v);
}

void Dfs(int u , int pa) {
	int sum = 0;
	ll res = 1LL * (S - 1) * (S - 1);
	num[u] = low[u] = ++Time;
	sz[u] = 1;
	for(auto v : adj[u]) {
		if(v == pa) continue;
		if(!num[v]) {
			Dfs(v , u);
			sz[u] += sz[v];
			low[u] = min(low[v] , low[u]);
			if(low[v] >= num[u] || !pa)
				sum += sz[v] , res -= 1LL * sz[v] * sz[v];
		} else low[u] = min(num[v] , low[u]);
	}
	cout << u << ' ' << sum << ' ' << res << '\n';
	res -= 1LL * (S - 1 - sum) * (S - 1 - sum);
	cout << u << ' ' << res << '\n';
	ans += res / 2;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i++) {
		int u , v ; cin >> u >> v;
		adj[u].pb(v) ; adj[v].pb(u);
	}
	int tmp = 0;
	for(int i = 1 ; i <= n ; i++) if(!num[i]) {
		tmp++;
		S = 0 , Go(i);
		Dfs(i , 0);
	}
	cout << ans << '\n';
	cout << fixed << setprecision(2) << 1.0 * ans / n;
	return 0;
}


