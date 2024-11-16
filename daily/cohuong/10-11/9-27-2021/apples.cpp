#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, a[100], Pow[100];

ll cnt2(ll x){
    ll res = 0;
    while ( x % 2 == 0 ){
        x /= 2; res ++;
    }
    return res;
}

void solve() {
	cin >> n >> a[1];
	bool flag = 0;
	if ( ( 2 * a[1] ) % ( ( n * Pow[n-1] ) + 1 ) ) { cout << -1 << '\n'; return; }

	ll s = 2 * a[1] - 2 * a[1] / ( n * Pow[n-1] + 1 );

    if ( s <= 0 || s % n ) { cout << -1 << '\n'; return; }

    ll base = s / n;
    ll t = min(cnt2(base), n);
    ll tu = base / Pow[t];
    ll mau = Pow[n-t];

    for (int i = 2; i <= n; i ++){
        a[i] = tu * ( n * Pow[n-i] + 1 ) / mau;
    }

    for (int i = 1; i <= n; i ++) cout << a[i] << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("apples.in", "r") ){
        freopen("apples.in", "r", stdin);
        freopen("apples.out", "w", stdout);
    }

    Pow[0] = 1;
    for (int i = 1; i <= 51; i ++)
        Pow[i] = Pow[i-1] * 2;

    cin >> t;

    while ( t -- )
        solve();

    return 0;
}

