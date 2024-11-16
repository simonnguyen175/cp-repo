#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second

const int N = 2e5 + 5;
int n, c[2 * N], Real[2 * N], sign[N], Kitty[N], bit[2 * N];
vector<pair<int, int>> a;

void compression() {
	sort(a.begin(), a.end());
	c[a[0].se] = 1;
	for (int i = 1, p = 1; i < a.size(); ++i) {
		if (a[i].fi == a[i - 1].fi) c[a[i].se] = c[a[i - 1].se];
		else c[a[i].se] = ++p;
		Real[c[a[i].se]] = a[i].fi;
	}
}

vector<int> n_list;
void get_v() {
	for (int i = 4e5; i >= 1; i -= i & -i) n_list.pb(i);
	reverse(n_list.begin(), n_list.end());
}

void upd(int i, char sign) {
	for (; i <= 4e5; i += i & -i) bit[i] += (sign == '+' ? 1 : -1);
}

int get(int i) {
	int ans = 0;
	for (; i >= 1; i -= i & -i) ans += bit[i];
	return ans;
}

int getans(int idx, int k) {
	int r = idx;
	int cnt = __builtin_ctz(idx);
	idx -= idx & -idx;
	int x = 0, inside = 0;
	for (int i = cnt - 1; i >= 0; --i) {
		idx += (1 << i);
		if (x + bit[idx] >= k) {inside = idx; break;}
		x += bit[idx];
	}
	if (!inside && x < k) return r;
	return getans(inside, k - x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, k, x, y, m = 0; i <= n; ++i) {
		char c; cin >> c;
		if (c != '?') {
			cin >> x;
			a.pb({x, ++m});
		}
		else {
			cin >> k >> x >> y;
			a.pb({x, ++m});
			a.pb({y, ++m});
			Kitty[i] = k;
		}
		sign[i] = c;
	}
	compression();

	get_v();

	for (int i = 1, j = 0; i <= n; ++i) {
		if (sign[i] != '?') upd(c[++j], sign[i]);
		else {
			int l = c[++j], r = c[++j];
			if (Kitty[i] > get(r) - get(l - 1)) {cout << "0\n"; continue;}

			int k = Kitty[i] + get(l - 1);
			int x = 0, inside;
			for (int node : n_list) {
				if (x + bit[node] >= k) {inside = node; break;}
				x += bit[node];
			}
			cout << inside <<' '<<k-x <<' '<< Real[getans(inside, k - x)] << '\n';
		}
	}
}
