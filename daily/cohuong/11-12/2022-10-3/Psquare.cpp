#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5, M = 1e9 + 7;
int n, a[N];
bool check() {
	for (int i = 1; i <= n; ++i)
		if (a[i] > 70) return 0;
	return 1;
}
namespace sub1 {
	typedef vector<int> D;
	D p[25];
	D add(D &x, D &y) {
		int i = 0, j = 0;
		vector<int> ans;
		for (; i < x.size(); ++i) {
			while (j < y.size() && y[j] < x[i])
				ans.emplace_back(y[j]), j++;
			if (j < y.size() && x[i] == y[j]) j++;
			else ans.emplace_back(x[i]);
		}
		while (j < y.size()) ans.emplace_back(y[j++]);
		return ans;
	}
	void sol() {
		for (int i = 1; i <= n; ++i) {
			for (int j = 2; j * j <= a[i]; ++j) {
				int c = 0;
				while (a[i] % j == 0) ++c, a[i] /= j;
				if (c % 2) p[i - 1].emplace_back(j);
			}
			if (a[i] > 1) p[i - 1].emplace_back(a[i]);
			sort(p[i - 1].begin(), p[i - 1].end());
		}
		int res = 0;
		for (int mask = 1; mask < (1 << n); ++mask) {
			vector<int> cur;
			for (int i = 0; i < n; ++i) if (mask >> i & 1)
				cur = add(cur, p[i]);
			if (!cur.size()) ++res;
		}
		cout << res;
	}
}
namespace sub2 {
	int pw(int x, int p) {
		if (!p) return 1; ll tmp = pw(x, p / 2);
		return tmp * tmp % M * (p % 2 ? x : 1) % M;
	}
	void add(int &x, int v) {
		x += v; if (x >= M) x -= M;
	}
	int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
	int msk[75], cnt[75], dp[1 << 19][2], sum[75][2];
	int inv[N], fact[N];
	int C(int n, int k) {
		return (ll)fact[n] * inv[k] % M * inv[n - k] % M;
	}
	void sol() {
		fact[0] = 1;
		for (int i = 1; i <= n; ++i)
			fact[i] = (ll)fact[i - 1] * i % M;
		inv[n] = pw(fact[n], M - 2);
		for (int i = n - 1; i >= 0; --i)
			inv[i] = (ll)inv[i + 1] * (i + 1) % M;
		for (int i = 1; i <= n; ++i) ++cnt[a[i]];
		for (int i = 1; i <= 70; ++i) {
			int x = i;
			for (int j = 0; j < 19; ++j) {
				int c = 0;
				while (x % p[j] == 0) ++c, x /= p[j];
				if (c % 2) msk[i] |= (1 << j);
			}
		}
		for (int i = 1; i <= 70; ++i)
			for (int j = 0; j <= cnt[i]; ++j)
				add(sum[i][j % 2], C(cnt[i], j));
		dp[0][0] = 1;
		for (int i = 0; i < 70; ++i) {
			int k = i % 2, j = (i + 1) % 2;
			for (int mask = 0; mask < (1 << 19); ++mask) dp[mask][j] = 0;
			for (int mask = 0; mask < (1 << 19); ++mask)
				add(dp[mask][j], (ll)dp[mask][k] * sum[i + 1][0] % M),
				add(dp[mask ^ msk[i + 1]][j], (ll)dp[mask][k] * sum[i + 1][1] % M);
		}
		cout << (dp[0][0] - 1 + M) % M;
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	if ( fopen("PSquare.inp", "r") ){
	   freopen("PSquare.inp", "r", stdin);
	   freopen("PSquare.out", "w", stdout);
	}

	cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

	if ( check() ) sub2::sol();
	else sub1::sol();

	return 0;
}


