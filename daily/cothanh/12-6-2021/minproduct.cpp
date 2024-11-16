#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
const ll oo = 1e9;

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("minproduct.inp", "r", stdin);
    freopen("minproduct.out", "w", stdout);

    cin >> n;

    pi mx, mn; mx = {-oo, -oo}; mn = {oo, oo};
    for (int i = 1; i <= n; i ++){
        ll x; cin >> x;

        if ( mx.fi <= x ) mx.se = mx.fi, mx.fi = x;
        else if ( mx.se < x ) mx.se = x;

        if ( mn.fi >= x ) mn.se = mn.fi, mn.fi = x;
        else if ( mn.se > x ) mn.se = x;
    }

    cout << min({mn.fi*mn.se, mx.fi*mn.fi, mx.fi*mx.se});

    return 0;
}
