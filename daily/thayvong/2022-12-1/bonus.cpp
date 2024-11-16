#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e2 + 5;

int n, k, r, p, s[N][N];
pi a[5];

pair<pi, pi> get(pair<pi, pi> x, pair<pi, pi> y){
	pair <pi, pi> ans;
	ans.fi.fi = max(x.fi.fi, y.fi.fi);
	ans.se.fi = min(x.se.fi, y.se.fi);
	ans.fi.se = max(x.fi.se, y.fi.se);
	ans.se.se = min(x.se.se, y.se.se);
	return ans;
}

int getsum(pair<pi, pi> x){
	if ( x.fi.fi > x.se.fi || x.fi.se > x.se.se ) return 0;
	return s[x.se.fi][x.se.se] - s[x.fi.fi-1][x.se.se] - s[x.se.fi][x.fi.se-1] + s[x.fi.fi-1][x.fi.se-1];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	if ( fopen("bonus.inp", "r") ){
		freopen("bonus.inp", "r", stdin);
		freopen("bonus.out", "w", stdout);
	}

	cin >> n >> k >> r >> p;
	for (int i = 1; i <= n; i ++)
	for (int j = 1, x; j <= n; j ++){
		cin >> x;
		s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + x;
	}

	int ans = 0;
	while ( k -- ){
		for (int i = 0; i < p; i++)
			cin >> a[i].fi >> a[i].se;

		ll cur = 0;
		for (int t = 1; t < (1 << p); t ++){
			pair<pi, pi> giao;
			giao = {{1, 1}, {n, n}};

			for (int i = 0; i < p; i++) if ( (t >> i)&1 )
				giao = get(giao, {{a[i].fi, a[i].se}, {a[i].fi+r-1, a[i].se+r-1}});

			if ( __builtin_popcount(t) % 2 ) cur += getsum(giao);
			else cur -= getsum(giao);
		}

		ans = max(ans, cur);
	}

	cout << ans;
}
