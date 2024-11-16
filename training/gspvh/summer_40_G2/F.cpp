#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1019972207;

ll n, k;

ll Pow(ll x, ll y){
    if ( y == 1 ) return x % MOD;
    ll tmp = Pow(x, y/2);
    if ( y % 2 ) return tmp * tmp % MOD * x % MOD;
    else return tmp * tmp % MOD;
}

ll C(ll n, ll k){
    ll res = 1, tmp = 1;
    for (ll i = k + 1; i <= n; i ++) res = res * ( i % MOD ) % MOD;
    for (ll i = 1; i <= n - k; i ++) tmp = tmp * ( i % MOD ) % MOD;
    res = ( res % MOD ) * Pow(tmp, MOD-2) % MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("divseq.inp", "r") ){
        freopen("divseq.inp", "r", stdin);
        freopen("divseq.out", "w", stdout);
    }

    cin >> n >> k;

    ll ans = 1;
    for (ll i = 2; i * i <= n; i ++) if ( n % i == 0 ){
        ll cnt = 0;
        while ( n % i == 0 )
            cnt ++, n /= i;
        ans = ans * C(cnt + k - 1, k - 1) % MOD;
    }

    if ( n != 1 )
        ans = ans * C(k, k - 1) % MOD;

    cout << ans;

    return 0;
}
