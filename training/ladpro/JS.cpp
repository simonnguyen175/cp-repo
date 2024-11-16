#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t;
ll n, m;

ll cnt(ll n, ll Range){
	ll res = 0;
	ll l = 1, r = 2;

	for (int i = 1; i <= 38; i ++){
		if(r > Range) break;
		res += min(l, n);
		res += max(0LL, min(r - 1, n) - l * 2 + 1);
		l = r;
		r = r * 3 - 1;
	}

	ll val = Range - l + 1;
	res += max(0LL, min(n, l) - (l - val / 2 + (val % 2 == 0)) + 1);
	res += max(0LL, min(n, l * 2 + val / 2 - 1) - l * 2 + 1);

	return res;
}


void solve(){
    cin >> n >> m;
    ll lo = 1, hi = 2e18;
    ll res = 1;

    while(lo <= hi){
        ll mid = (lo + hi) >> 1ll;
        if ( cnt(mid, n) >= m ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << res << '\n';
}


int main(){
	ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

	cin >> t;

	while ( t -- )
        solve();

	return 0;
}
