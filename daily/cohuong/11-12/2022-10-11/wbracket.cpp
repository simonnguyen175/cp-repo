#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 130;
int n; ll k;
ll dp[N][2 * N][2];
ll cal(int i, int s, bool wr) {
	if (i == n + 1) {
		if (wr) return 1;
		if (s != 0) return 1;
		return 0;
	}
	if (dp[i][s + N][wr] != -1) return dp[i][s + N][wr];
	ll ans = cal(i + 1, s + 1, wr | (s + 1 < 0)) + cal(i + 1, s - 1, wr | (s - 1 < 0)); 
	return dp[i][s + N][wr] = ans;
}
void get(int i, int s, bool wr, ll rem) {
	if (i == n + 1) return;
	ll l = cal(i + 1, s + 1, wr | (s + 1 < 0)), r = cal(i + 1, s - 1, wr | (s - 1 < 0));
	if (l >= rem)
		cout << '(', get(i + 1, s + 1, wr | (s + 1 < 0), rem);
	else
		cout << ')', get(i + 1, s - 1, wr | (s - 1 < 0), rem - l);
} 
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	freopen("WBRACKET.inp", "r", stdin);
	freopen("WBRACKET.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2 * N; ++j)
			dp[i][j][0] = dp[i][j][1] = -1;
	get(1, 0, 0, k);
	return 0;
}