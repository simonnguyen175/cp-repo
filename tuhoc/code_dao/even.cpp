#include<bits/stdc++.h>
#define ll long long
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
const int N = 1e5 + 5;
const ll oo = 1e15;

int n;
ll a[N], b[N];
map<ll, int> d;
ll g = 0;
ll base = 0;

ll range(ll l, ll r){
	return l + rng() % ( r - l + 1 );
}

ll conv(ll x, int t){
    return x + base;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];

    ll ans = oo;
    for (int t = 0; t <= 25; t ++){
        base = range(1e18, 1e18+1e17);
        d.clear();
        d[0] ++;
        g = 0;
        ll res = 0;
        for (int i = 1; i <= n; i ++){
            g ^= conv(a[i], t) ^ conv(b[i]+1, t);
            res += d[g];
            d[g] ++;
        }
        ans = min(ans, res);
    }

    cout << ans;

    return 0;
}
