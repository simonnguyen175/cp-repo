#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define eb emplace_back

struct DSU {
	int n;
	vector<int> ln, sz;
	DSU() {}
	DSU(int n) : n(n), ln(vector<int>(n)), sz(vector<int>(n, 1)) {
		iota(ln.begin(), ln.end(), 0);
	}
	int find(int u) {
		return u == ln[u] ? u : find(ln[u]);
	}
	bool unite(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return 0;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v], ln[v] = u;
		return 1;
	}
};

struct E {
	int t, u, v, w;
	E() {}
	E(int t, int u, int v, int w) : t(t), u(u), v(v), w(w) {}
	bool operator < (const E &c) const {
		return w < c.w;
	}
};

int n[2], m[2];

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<E> edge;
	for (int t = 0; t < 2; ++t) {
		cin >> n[t] >> m[t];
		for (int i = 0, u, v, w; i < m[t]; ++i)
			cin >> u >> v >> w, u--, v--,
			edge.eb(t, u, v, w);
	}

	sort(edge.begin(), edge.end());
	DSU cpt[2]; cpt[0] = DSU(n[0]), cpt[1] = DSU(n[1]);
	ll res = 0;
	for (auto &c : edge)
		if (cpt[c.t].unite(c.u, c.v))
			res += (ll)n[!c.t]*c.w, n[c.t]--;
	cout << res;
	return 0;
}
