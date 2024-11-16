#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 1;

int n, m;
long long a[N], b[N];

bool check(ll t){
    int id = 1;
    for (int i = 1; i <= n; i ++){
        int x = id;
        while ( x <= m && b[x]-b[id] + min(abs(a[i]-b[x]), abs(a[i]-b[id])) <= t )
            x ++;
        if ( x > m ) return true;
        id = x;
    }

    return false;
}

void solve(){
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    sort(a+1, a+1+n);
    sort(b+1, b+1+m);

    ll lo = 0, hi = 1e12, res;

    while ( lo <= hi ){
        ll mid = ( lo + hi ) / 2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    cout << res << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	if ( fopen("harvest.inp", "r") ){
		freopen("harvest.inp", "r", stdin);
		freopen("harvest.out", "w", stdout);
	}

	while ( cin >> n >> m )
		if ( !n && !m ) break;
		else solve();

	return 0;
}



