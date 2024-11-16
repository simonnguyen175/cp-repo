#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair<ll,ll>
#define ll long long
#define int ll
#define pb push_back

const int maxn = 1e5 + 4;

ll dp[maxn][2][2];
int n, a[maxn];
vector<int> adj[maxn];

void update(pii &x, ll val) {
	x.se = max(x.se, val);
	if (x.se > x.fi)
		swap(x.fi, x.se);
}

int get(int id, pii x[3]) {
	if (x[0].se == id) return x[1].fi + x[2].fi;
	if (x[1].se == id) return x[0].fi + x[2].fi;
	return x[0].fi + x[1].fi;
}

void dfs(int u, int p) {
	pii x10 = {0, 0}, x11[2], x01[3];
	memset(x11, 0, sizeof x11);
	memset(x01, 0, sizeof x01);
	dp[u][0][1] = a[u];
	for (int v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0][1] = max(dp[u][0][1], dp[v][0][1] + a[u]);
		dp[u][0][0] = max(dp[u][0][0], dp[v][0][0]);
		dp[u][1][0] = max(dp[u][1][0], dp[v][1][0]);
		update(x10, max(dp[v][0][0], dp[v][0][1]));
		x11[1] = max(x11[1], make_pair(dp[v][1][1], v));
		if (x11[1].fi > x11[0].fi)
			swap(x11[0], x11[1]);
		x01[2] = max(x01[2], make_pair(dp[v][0][1], v));
		sort(x01, x01 + 3, [](pii a, pii b) {
			return a.fi > b.fi;
		});
		dp[u][1][1] = max(dp[u][1][1], dp[v][1][1] + a[u]);
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		dp[u][1][0] = max(dp[u][1][0], dp[v][0][1] + (v != x11[0].se ? x11[0].fi : x11[1].fi) + a[u]);
		dp[u][1][0] = max(dp[u][1][0], get(v, x01) + max(dp[v][0][0], dp[v][0][1]) + a[u]);
		dp[u][1][1] = max(dp[u][1][1], max(dp[v][0][0], dp[v][0][1]) +
						 (v != x01[0].se ? x01[0].fi : x01[1].fi) + a[u]);
	}
	dp[u][0][0] = max(dp[u][0][0], x01[0].fi + x01[1].fi + a[u]);
	dp[u][1][0] = max(dp[u][1][0], x10.fi + x10.se);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//    if ( fopen("trash.inp", "r") ){
//        freopen("trash.inp", "r", stdin);
//        freopen("trash.out", "w", stdout);
//    }
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	cout << max(dp[1][1][0], dp[1][1][1]);
	// clog << dp[9][1][1];
	// clog << dp[8][0][0];
}
