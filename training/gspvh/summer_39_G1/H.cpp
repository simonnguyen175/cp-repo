#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int mod = 998244353;

int t, MOD, n, k, m;
int lpf[N], cnt[N];
ll fact[N], inv[N];

void sieve(){
    memset(lpf, 0, sizeof lpf);
    for (int i = 2; i * i <= N-5; i ++)
        if ( !lpf[i] )
            for (int j = i * i; j <= N-5; j += i)
                lpf[j] = i;
    for (int i = 2; i <= N-5; i ++)
        if ( !lpf[i] ) lpf[i] = i;
}

ll Pow(ll a, ll b, int p){
    if ( b == 0 ) return 1LL;
    ll tmp = Pow(a, b/2, p);
    if ( b % 2 ) return tmp * tmp % p * a % p;
    else return tmp * tmp % p;
}

ll C(int n, int k){
    return fact[n] * inv[k] % mod * inv[n-k] % mod;
}

void sub2(){
    cin >> n >> m >> k;
    cout << C(n-1, k) * m % MOD * Pow(m-1, k, MOD) % MOD << '\n';
}

void sub3(){
    cin >> n >> m >> k;

    ll ans = 1;
    for (int i = n-k; i <= n-1; i ++)
        ans = ( ans * i ) % MOD;

    cout << ans * Pow(fact[k], MOD-2, MOD) % MOD * m % MOD * Pow(m-1, k, MOD) % MOD << '\n';
}

void sub4(){
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++) cnt[i] = 0;

    for (int i = n-k; i <= n-1; i ++){
        int x = i;
        while ( lpf[x] )
            cnt[lpf[x]] ++, x /= lpf[x];
    }

    for (int i = 1; i <= k; i ++){
        int x = i;
        while ( lpf[x] )
            cnt[lpf[x]] --, x /= lpf[x];
    }

    ll ans = 1;
    for (int i = 1; i <= n; i ++)
        ans = ans * Pow(i, cnt[i], MOD) % MOD;
    ans = ans * m % MOD * Pow(m-1, k, MOD) % MOD;

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("flowers.inp", "r") ){
        freopen("flowers.inp", "r", stdin);
        freopen("flowers.out", "w", stdout);
    }

    sieve();

    fact[0] = 1;
    for (int i = 1; i <= N-5; i ++)
        fact[i] = fact[i-1] * i % mod;

    inv[N-5] = Pow(fact[N-5], mod-2, mod);
    for (int i = N-6; i >= 0; i --)
        inv[i] = inv[i+1] * (i+1) % mod;

    cin >> t >> MOD;
    if ( MOD == 998244353 ){
        if ( t > 50 ) while ( t -- ) sub2();
        else while ( t -- ) sub3();
    }
    else while ( t -- ) sub4();

    return 0;
}
