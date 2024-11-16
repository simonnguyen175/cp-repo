#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define NguyenLuong ""
const int N = 100 + 5;
int n, a[2][N];
pair<int, pair<int, int>> b[2 * N];
bool big[2][N];
vector<int> ans;
struct Hex {
	int p1, p2, p3, p4, p5, p6;
};

void solve() {
	cin >> n;
	for (int i = 0; i <= 1; ++i)
		for (int j = 1; j <= n; ++j) cin >> a[i][j];

	if (n == 2) {
		int res = max({a[0][1] + a[0][2], a[0][2] + a[1][2], a[1][2] + a[1][1], a[1][1] + a[0][1]});
		if (a[0][1] + a[0][2] == res) cout << "0";
		else if (a[0][2] + a[1][2] == res) cout << "1\n1";
		else if (a[1][2] + a[1][1] == res) cout << "2\n1 1";
		else cout << "3\n1 1 1";
		return;
	}

	for (int i = 0, c = 1; i <= 1; ++i)
		for (int j = 1; j <= n; ++j, ++c)
			b[c] = {a[i][j], {i, j}};

	sort(b + 1, b + 2 * n + 1, greater<pair<int, pair<int, int>>>());
	for (int i = 1; i <= n; ++i) big[b[i].second.first][b[i].second.second] = 1;

	while (1) {
		int p1 = 0, p2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (!big[0][i]) p1 = i;
			if (big[1][i]) p2 = i;
		}
		if (!p1) break;
		if (p1 == p2) {
			if (p1 == 1) {
				ans.push_back(p1 + 1);
				ans.push_back(p1 + 1);
				ans.push_back(p1 + 1);
				ans.push_back(p1);
				ans.push_back(p1 + 1);
				ans.push_back(p1);
				ans.push_back(p1 + 1);
				bool tmp = big[0][p1];
				big[0][p1] = big[0][p1 + 1];
				big[0][p1 + 1] = big[0][p1 + 2];
				big[0][p1 + 1] = big[1][p1];
				big[1][p1] = big[1][p1 + 1];
				big[1][p1 + 1] = big[1][p1 + 2];
				big[1][p1 + 1] = tmp;
			} else if (p1 == 2) {
				ans.push_back(p1 - 1);
				ans.push_back(p1);
				ans.push_back(p1 - 1);
				ans.push_back(p1);
				ans.push_back(p1);
				ans.push_back(p1);
				bool tmp = big[0][p1];
				big[0][p1] = big[0][p1 - 1];
				big[0][p1 - 1] = big[0][p1 + 1];
				big[0][p1 + 1] = big[1][p1];
				big[1][p1] = big[1][p1 - 1];
				big[1][p1 - 1] = tmp;
			} else {
				ans.push_back(p1 - 2);
				ans.push_back(p1 - 1);
				ans.push_back(p1 - 2);
				ans.push_back(p1 - 2);
				ans.push_back(p1 - 2);
				bool tmp = big[0][p1];
				big[0][p1] = big[1][p1];
				big[1][p1] = big[1][p1 - 2];
				big[1][p1 - 2] = big[1][p1 - 1];
				big[1][p1 - 1] = tmp;
			}
		} else {
			if (p1 < p2) {
				for (int j = p2 - 1; j >= p1; --j) {
					ans.push_back(j);
					bool tmp = big[1][j];
					big[1][j] = big[0][j];
					big[0][j] = big[0][j + 1];
					big[0][j + 1] = big[1][j + 1];
					big[1][j + 1] = tmp;
				}
			} else {
				for (int j = p2; j <= p1 - 1; ++j) {
					ans.push_back(j);
					ans.push_back(j);
					ans.push_back(j);
					bool tmp = big[1][j];
					big[1][j] = big[1][j + 1];
					big[1][j + 1] = big[0][j + 1];
					big[0][j + 1] = big[0][j];
					big[0][j] = tmp;
				}
			}
		}
	}

	cout << ans.size() << '\n';
	for (int p : ans) cout << p << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	if (fopen(NguyenLuong".inp", "r")) {
		freopen(NguyenLuong".inp", "r", stdin);
		freopen(NguyenLuong".out", "w", stdout);
	}
	solve();
	return 0;
}
