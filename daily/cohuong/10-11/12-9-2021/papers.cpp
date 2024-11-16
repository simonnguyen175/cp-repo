#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

ll m, n;

ll Pow(ll x, ll y){
    if ( y == 1 ) return x % MOD;
    ll tmp = Pow(x, y/2);
    if ( y % 2 ) return tmp * tmp % MOD * x % MOD;
    else return tmp * tmp % MOD;
}

ll C(ll n, ll k){
    ll res = 1, tmp = 1;
    for (ll i = n - k + 1; i <= n; i ++) res = res * ( i % MOD ) % MOD;
    for (ll i = 1; i <= k; i ++) tmp = tmp * ( i % MOD ) % MOD;
    res = ( res % MOD ) * Pow(tmp, MOD-2) % MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("papers.inp", "r") ){
        freopen("papers.inp", "r", stdin);
        freopen("papers.out", "w", stdout);
    }

    cin >> m >> n;
    for (ll i = 1, x; i <= n; i ++)
        cin >> x, m -= x;
    if ( m == 0 ) { cout << 1; return 0; }
    if ( m < 0 ) { cout << 0; return 0; }
    cout << C(m+n-1, n-1);
    return 0;
}
