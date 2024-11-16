#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e3 + 5;
const int MOD = 1e9 + 7;

int t, n;
ll m, s;
ll r[N], fact[N], inv[N];
map<ll, ll> ct;

ll mu(int x, int y){
    if ( y == 0 ) return 1;
    ll tmp = mu(x, y/2);
    if ( y % 2 == 0 ) return tmp * tmp % MOD;
    else return tmp * tmp % MOD * x % MOD;
}

ll C(int k, int n){
    if ( k == 0 ) return 1;
    if ( k > n ) return 0;
    if ( n == k ) return 1;

    ll res = ct[n-m];

    ( res *= inv[k] ) %= MOD;

    return res;
}

void solve(){
    ll ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        if ( i == j ) continue;
        ( ans += C(n, m + r[i] + r[j]) * fact[n-2] % MOD ) %= MOD;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("umbrella.in", "r") ){
        freopen("umbrella.in", "r", stdin);
        freopen("umbrella.out", "w", stdout);
    }

    cin >> t;

    fact[0] = 1;
    for (int i = 1; i < N; i ++) fact[i] = fact[i-1] * i % MOD;

    inv[N-1] = mu(fact[N-1], MOD-2);
    for (int i = N - 2; i >= 1; i --)
        inv[i] = ( i + 1 ) * inv[i+1] % MOD;

    while ( t -- ){
        cin >> n >> m;
        s = 0; m --;

        for (int i = 1; i <= n; i ++)

            cin >> r[i], s += 2*r[i];

        sort(r + 1, r + 1 + n);

        if ( n == 1 ){
            cout << m + 1 << '\n'; continue;
        }

        m += n + 1 - s - 1;

        for (ll i = m + r[1] + r[2]; i <= m + r[n] + r[n-1]; i ++){
            ct[i-m] = 1;
            for (ll j = i - n + 1; j <= i; j ++)
                ( ct[i-m] *= j % MOD ) %= MOD;
        }

        solve();
    }
}
