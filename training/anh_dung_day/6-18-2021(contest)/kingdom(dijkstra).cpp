#include <bits/stdc++.h>
using namespace std;

#define tpii tuple<int, int, int>
const int N = 1e3 + 5;

int n, adj[N][N], dp[N][N], ans = INT_MAX;
bool vis[N][N];
priority_queue<tpii, vector<tpii>, greater<tpii> > Q;

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> adj[i][j];

	for(int i = 1; i <= n; ++i) {
		adj[i][n + 1] = 0;
		adj[n + 1][i] = 0;
	}
	memset(vis, false, sizeof vis);
	for(int i = 1; i <= n + 1; ++i)
		for(int j = 1; j <= n + 1; ++j)
			dp[i][j] = INT_MAX;

	dp[n][n + 1] = 0;
	Q.push(make_tuple(0, n, n + 1));

	while(Q.size()) {
		auto tmp = Q.top(); Q.pop();
		int val = get<0>(tmp), u = get<1>(tmp), v = get<2>(tmp);

		if(vis[u][v]) continue;
		vis[u][v] = true;

		int k = min(u, v) - 1;
		if(k < 1) continue;
		if(dp[k][u] > dp[u][v] + adj[v][k]) {
			dp[k][u] = dp[u][v] + adj[v][k];
			Q.push(make_tuple(dp[k][u], k, u));
		}
		if(dp[k][v] > dp[u][v] + adj[u][k]) {
			dp[k][v] = dp[u][v] + adj[u][k];
			Q.push(make_tuple(dp[k][v], k, v));
		}
	}
	for(int i = 2; i <= n + 1; ++i)
		ans = min(ans, dp[1][i] + adj[1][i]);
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
