#include<bits/stdc++.h>
using namespace std;

struct data {
	long long x, y, z;
};

const int N = 3004;
int n;
data a[N];

long long dp[N][2][N];

void minimize(long long &a, long long b) {
	if (a == -1) a = b;
	else a = min(a, b);
}

void sol() {
	sort(a+1, a+n+1, [] (data u, data v) {
		return u.y - u.x < v.y - v.x;
	});

	memset(dp, -1, sizeof(dp));

	dp[0][0][0] = 0;
	for (int i = 0; i < n; ++i)
	for (int type = 0; type <= 1; ++type) 
	for (int numZ = 0; numZ <= i; ++numZ) {
		if (dp[i][type][numZ] == -1) continue;

		// a[i+1] -> X
		minimize( dp[i+1][1][numZ], dp[i][type][numZ] + a[i+1].x );

		// a[i+1] -> Y
		if (type == 0) {
			int numY = i - numZ;
			minimize( dp[i+1][0][numZ], dp[i][type][numZ] + a[i+1].y - numY );
		}

		// a[i+1] -> Z
		minimize( dp[i+1][type][numZ+1], dp[i][type][numZ] + a[i+1].z - numZ );
	}

	long long res = -1;
	for (int numZ = 0; numZ <= n; ++numZ) {
		if (dp[n][0][numZ] != -1) minimize(res, dp[n][0][numZ]);
		if (dp[n][1][numZ] != -1) minimize(res, dp[n][1][numZ]);
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// freopen("buying.inp", "r", stdin);
	// freopen("buying.out", "w", stdout);


	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].z;

	sol();

	return 0;
}