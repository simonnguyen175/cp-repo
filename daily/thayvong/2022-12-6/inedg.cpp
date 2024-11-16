#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define fi first
#define se second
#define eb emplace_back
const int N = 4e5 + 5;
int n, np, res[N];
pii p[N], p1[N], p2[N];
map<pii, int> exst;
vector<int> pt[N];
vector<pair<int, pii> > seg[N];
struct stree {
	int n; vector<int> st;
	stree() {}
	stree(int n) : n(n) {
		st.resize(4 * n + 4);
	}
	void up(int id, int l, int r, int x, int v) {
		if (l > x || r < x) return;
		if (l == r) return st[id] += v, void();
		int mi = (l + r) / 2;
		up(2 * id, l, mi, x, v); up(2 * id + 1, mi + 1, r, x, v);
		st[id] = st[2 * id] + st[2 * id + 1];
	}
	int ge(int id, int l, int r, int u, int v) {
		if (l > v || r < u) return 0;
		if (u <= l && r <= v) return st[id];
		int mi = (l + r) / 2;
		return ge(2 * id, l, mi, u, v) + ge(2 * id + 1, mi + 1, r, u, v);
	}
	void upd(int p, int v) {
		up(1, 0, n-1, p, v);
	}
	int get(int l, int r) {
		 return ge(1, 0, n-1, l, r);
	}
};
vector<int> comp;
int cval(int x) {
	return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
}
int main() {
	cin.tie(0)->sync_with_stdio(0); cout.tie(0);
	if (fopen("InEdg.inp", "r"))
		freopen("InEdg.inp", "r", stdin),
		freopen("InEdg.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i].fi >> p[i].se;
	cin >> np;
	for (int i = 0; i < np; ++i)
		cin >> p1[i].fi >> p1[i].se >> p2[i].fi >> p2[i].se;
	int msz = 0;
	// cp x
	for (int i = 0; i < n; ++i)
		comp.eb(p[i].fi);
	for (int i = 0; i < np; ++i)
		comp.eb(p1[i].fi), comp.eb(p2[i].fi);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	msz = max(msz, (int)comp.size());
	for (int i = 0; i < n; ++i)
		p[i].fi = cval(p[i].fi);
	for (int i = 0; i < np; ++i)
		p1[i].fi = cval(p1[i].fi), p2[i].fi = cval(p2[i].fi);
	comp.clear();
	// cp y
	for (int i = 0; i < n; ++i)
		comp.eb(p[i].se);
	for (int i = 0; i < np; ++i)
		comp.eb(p1[i].se), comp.eb(p2[i].se);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	msz = max(msz, (int)comp.size());
	for (int i = 0; i < n; ++i)
		p[i].se = cval(p[i].se);
	for (int i = 0; i < np; ++i)
		p1[i].se = cval(p1[i].se), p2[i].se = cval(p2[i].se);

	for (int i = 0; i < n; ++i) exst[p[i]]++;
	for (int t = 2; t--;) {
		stree cnt(msz);
		for (int i = 0; i < n; ++i)
			pt[p[i].fi].eb(p[i].se);
		for (int i = 0; i < np; ++i)
			seg[p1[i].fi].push_back({i, {p1[i].se, p2[i].se}}),
			seg[p2[i].fi].push_back({i, {p1[i].se, p2[i].se}});
		for (int i = 0; i < msz; ++i) {
			for (int &v : pt[i]) cnt.upd(v, 1);
			for (auto &v : seg[i])
				res[v.fi] += cnt.get(v.se.fi, v.se.se);
			for (int &v : pt[i]) cnt.upd(v, -1);
		}
		for (int i = 0; i < msz; ++i)
			pt[i].clear(), seg[i].clear();
		for (int i = 0; i < n; ++i)
			swap(p[i].fi, p[i].se);
		for (int i = 0; i < np; ++i)
			swap(p1[i].fi, p1[i].se),
			swap(p2[i].fi, p2[i].se);
	}
	for (int i = 0; i < np; ++i) {
		vector<int> x = {p1[i].fi, p2[i].fi}, y = {p1[i].se, p2[i].se};
		for (int &v1 : x) for (int &v2 : y)
			if (exst.count({v1, v2})) res[i]--;
		cout << res[i] << '\n';
	}
	return 0;
}
