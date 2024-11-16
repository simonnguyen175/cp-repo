#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;	
int n;
vector<int> adj[N];
namespace sub3 {
	// const int N = 5e3 + 5;
	bool vis[N]; int f[N], res[N];
	set<int> ver;
	void dfs_b(int u, int p = 0) {
		f[u] = u; 
		for (int &v : adj[u]) if (v != p && !vis[v])
			dfs_b(v, u), f[u] = min(f[u], f[v]);
	}
	int cur;
	void dfs_g(int u, int p = 0) {	
		vis[u] = 1; res[u] = cur; ver.erase(u); 
		int nxt = 0;
		for (int &v : adj[u]) if (v != p && !vis[v])
			if (f[nxt] > f[v]) nxt = v;
		if (nxt) dfs_g(nxt, u);
	}
	void get(int u) {
		dfs_b(u);
		int mi1, mi2; mi1 = mi2 = 0; f[0] = n + 1;
		for (int &v : adj[u]) if (!vis[v])
			if (f[mi1] > f[v]) mi2 = mi1, mi1 = v;
			else if (f[mi2] > f[v]) mi2 = v;
		vis[u] = 1; res[u] = cur; ver.erase(u);
		if (mi1) dfs_g(mi1); 
		if (mi2) dfs_g(mi2); 
	} 
	void sol() {
		for (int i = 1; i <= n; ++i) ver.insert(i);
		cur = 1;
		while (ver.size()) {
			get(*ver.begin()), ++cur;
		}
		for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	cin >> n;
	for (int i = 1, u, v; i < n; ++i)
		cin >> u >> v,
		adj[u].emplace_back(v),
		adj[v].emplace_back(u);
	sub3::sol();
	return 0;
}
