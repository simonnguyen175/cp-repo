#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll n, m;
ll pw2[N], fact[N];

ll Pow(ll a, ll b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

ll C(ll n, ll k){
    ll res = fact[n];
    ll tmp = Pow(fact[k] * fact[n-k] % MOD, MOD - 2);
    return res * tmp % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    if ( n < m ) swap(m, n);

    pw2[0] =  1, fact[0] = 1;
    for (int i = 1; i < N; i ++){
        pw2[i] = pw2[i-1] * 2 % MOD;
        fact[i] = fact[i-1] * i % MOD;
    }

    ll ans = Pow((pw2[m] - 1 + MOD) % MOD, n);

    for (int i = 1; i <= m; i ++){
        ll tmp = C(m, i) * Pow((pw2[m-i] - 1 + MOD) % MOD, n) % MOD;
        if ( i % 2 == 1 ) ans = ( ans - tmp + MOD ) % MOD;
        else ans = ( ans + tmp ) % MOD;
    }

    cout << ans;

    return 0;
}
