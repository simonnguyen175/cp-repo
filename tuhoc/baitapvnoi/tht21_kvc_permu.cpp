#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll n, t, cnt = 0;
ll d[N], fact[N], inv[N];

ll C(ll n, ll k){
    if ( n == k ) return 1;
    if ( k > n ) return 0;
    if ( k == 0 ) return 1;
    return ( fact[n] * inv[k] % MOD * inv[n-k] % MOD );
}

ll mu(ll a, ll b){
    if ( b == 1 ) return a;
    ll tmp = mu(a, b/2);
    if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

void init(){
    cin >> n >> t;
    for (int i = 1; i <= t; i ++){
        int l, r; cin >> l >> r;
        d[l] ++, d[r+1] --;
    }
    for (int i = 1; i <= n; i ++){
        d[i] += d[i-1];
        if ( d[i] ) cnt ++;
    }

    fact[0] = 1;
    for (ll i = 1; i <= n; i ++)
        fact[i] = fact[i-1] * i % MOD;

    inv[n] = mu(fact[n], MOD-2);
    for (ll i = n-1; i >= 1; i --)
        inv[i] = inv[i+1] * (i+1) % MOD;
}

void solve(){
    ll ans = fact[n];

    for (ll i = 1; i <= cnt; i ++)
        if ( i % 2 ) ans = ( ans - C(cnt, i) * fact[n-i] % MOD + MOD * MOD ) % MOD;
        else ans = ( ans + C(cnt, i) * fact[n-i] % MOD + MOD * MOD ) % MOD;

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    init();
    solve();

    return 0;
}

