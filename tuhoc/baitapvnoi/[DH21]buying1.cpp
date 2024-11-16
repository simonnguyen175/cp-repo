#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end
#define pb push_back
#define eb emplace_back
#define ms(d, i) memset(d, i, sizeof d)

using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

const int N = 3e3 + 5;
int n, a[N], b[N], c[N];

namespace sub2 {
	const int Ns = 200 + 5;
	ll dp[Ns][Ns][Ns];
	void sol() {
		ms(dp, 0x3f);
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int x = 0; x <= n; ++x) {
				for (int y = 0; x + y <= i; ++y) {
					if (x) dp[i][x][y] = min(dp[i][x][y], dp[i - 1][x - 1][y] + a[i]);
					if (y) dp[i][x][y] = min(dp[i][x][y], dp[i - 1][x][y - 1] + b[i] - (y - 1));
					if (i - x - y) dp[i][x][y] = min(dp[i][x][y], dp[i - 1][x][y] + c[i] - (i - x - y - 1));
				}
			}
		}
		ll ans = LINF;
		for (int x = 0; x <= n; ++x) {
			for (int y = 0; x + y <= n; ++y)
				ans = min(ans, dp[n][x][y]);
		}
		cout << ans;
	}
}

namespace sub3 {
	struct T {
		int a, b, c;
	} t[N];
	
	ll dp[2][N][N], mn[2][N];
	
	bool operator < (const T &A, const T &B) {
		return A.b - A.c < B.b - B.c;
	}
	
	void sol() {
		for (int i = 1; i <= n; ++i)
			t[i] = {a[i], b[i], c[i]};
		sort(t + 1, t + n + 1);
		ms(dp, 0x3f);
		ms(mn, 0x3f);
		dp[0][0][0] = 0; mn[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int x = 0; x <= i; ++x) {
				if (x) dp[0][i][x] = min(dp[0][i][x], dp[0][i - 1][x - 1] + t[i].a);
				if (i - x) dp[0][i][x] = min(dp[0][i][x], dp[0][i - 1][x] + t[i].b - (i - x - 1));
				mn[0][i] = min(mn[0][i], dp[0][i][x]);
			}
		}
		dp[1][n + 1][0] = 0; mn[1][n + 1] = 0;
		for (int i = n; i >= 1; --i) {
			for (int x = 0; x <= n - i + 1; ++x) {
				if (x) dp[1][i][x] = min(dp[1][i][x], dp[1][i + 1][x - 1] + t[i].a);
				if (n - i + 1 - x) dp[1][i][x] = min(dp[1][i][x], dp[1][i + 1][x] + t[i].c - (n - i - x));
				mn[1][i] = min(mn[1][i], dp[1][i][x]);
			}
		}
		
		ll ans = LINF;
		for (int i = 0; i <= n; ++i) {
			ans = min(ans, mn[0][i] + mn[1][i + 1]);
		}
		cout << ans;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i] >> c[i];
	if (n <= 200) 
		sub2::sol();
	else
		sub3::sol();
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	solve();
	return 0;
}