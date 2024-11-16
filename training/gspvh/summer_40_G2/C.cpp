#include <bits/stdc++.h>
#define simon "llcm"
#define ll long long
#define fi first
#define se second
#define pi pair<int, int>
#define pb push_back
using namespace std;
const int N = 1e7 + 1;

int n;
pi pos[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	if (fopen(simon".inp", "r")) {
		freopen(simon".inp", "r", stdin);
		freopen(simon".out", "w", stdout);
	}

	cin >> n;
	int mx = 0;
	for (int i = 1, x; i <= n; i ++){
		cin >> x;
        if ( !pos[x].fi ) pos[x].fi = i;
        else if ( !pos[x].se ) pos[x].se = i;
        mx = max(mx, x);
	}

	long long ans = 1e14;
	pi res;
	for (int i = 1; i <= mx; ++i){
		vector<pi> tmp;
		for (int j = i; j <= mx; j += i){
			if ( pos[j].first && tmp.size() < 2 ) tmp.pb({j, pos[j].fi});
			if ( tmp.size() == 2 ) break;
			if ( pos[j].second && tmp.size() < 2 ) tmp.pb({j, pos[j].se});
			if ( tmp.size() == 2 ) break;
		}

		if ( tmp.size() == 2 ){
			ll v = 1LL * tmp[0].fi * tmp[1].fi / i;
			if ( ans > v ) ans = v, res.fi = tmp[0].se, res.se = tmp[1].se;
		}
	}

	if ( res.fi > res.se ) swap(res.fi, res.se);
	cout << res.fi << ' ' << res.se;

	return 0;
}
