#include<bits/stdc++.h>
#define ll long long
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1e6 + 5;
const int MXA = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k, L, R;
int a[N], cnt[N];
ll f[N], fact[N], inv[N];

ll Pow(ll a, ll b){
    if ( b == 1 ) return a;
    ll tmp = Pow(a, b/2);
    if ( b % 2 ) return tmp * tmp % MOD * a % MOD;
    else return tmp * tmp % MOD;
}

ll C(int n, int k){
    if ( k == 0 ) return 1;
    else if ( n < k ) return 0;
    else if ( n == 0 ) return 0;
    else return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi21_or.inp", "r") ){
        freopen("voi21_or.inp", "r", stdin);
        freopen("voi21_or.out", "w", stdout);
    }

    cin >> n >> k >> L >> R;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cnt[a[i]] ++;
    }

    for (int i = 0; i <= 19; i ++)
    for (int msk = 0; msk <= MXA - 5; msk ++)
        if ( BIT(msk, i) )
            cnt[msk] += cnt[msk^(1<<i)];

    fact[0] = 1;
    for (int i = 1; i <= N - 5; i ++)
        fact[i] = fact[i-1] * i % MOD;

    inv[0] = 1;
    inv[N-5] = Pow(fact[N-5], MOD-2);
    for (int i = N-6; i >= 1; i --)
        inv[i] = inv[i+1] * (i+1) % MOD;

    for (int i = 0; i <= MXA - 5; i ++)
        if ( __builtin_popcount(i) % 2 )
            f[i] = C(cnt[i], k);
        else
            f[i] = ( -C(cnt[i], k) + MOD ) % MOD;

    for (int i = 0; i <= 19; i ++)
    for (int msk = 0; msk <= MXA - 5; msk ++)
        if ( BIT(msk, i) )
            ( f[msk] += f[msk^(1<<i)] + MOD) %= MOD;

    ll ans = 0;
    for (int i = L; i <= R; i ++)
        if ( i % 3 == 0 )
            if ( __builtin_popcount(i) % 2 ) ( ans += f[i] ) %= MOD;
            else ( ans -= f[i] ) %= MOD;

    cout << ( ans + MOD ) % MOD;

    return 0;
}
