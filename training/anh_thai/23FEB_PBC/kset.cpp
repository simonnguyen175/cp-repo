#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n, k;
int fact[N], inv[N], inve[N], lpf[N];
int f[N], g[N], cnt[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    if ( n < k ) return 0;
    if ( k == 0 ) return 1;
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

void sieve(){
    for (int i = 2; i * i <= N-5; i ++) if ( !lpf[i] )
    for (int j = i * i; j <= N-5; j += i) if ( !lpf[j] )
        lpf[j] = i;

    for (int i = 2; i <= N-5; i ++) if ( !lpf[i] )
        lpf[i] = i;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    fact[0] = 1;
    for (int i = 1; i <= N-5; i ++)
        fact[i] = mul(fact[i-1], i);
    inv[N-5] = Pow(fact[N-5], MOD-2);
    for (int i = N-6; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

    for (int i = 1; i < N; i ++)
        inve[i] = Pow(i, MOD-2);

//    cout << C(3, 1) << ' ' << inv[1] << ' ' << fact[3] << ' ' << inve[2] << '\n';

    sieve();

//    cout << lpf[12] << ' ' << lpf[9] << '\n';

    /// f[i] so luong uoc nguyen to
    /// g[i] tich cac so mu
    g[0] = 1;
    for (int i = 1; i <= N-5; i ++){
        int x = i;
        f[i] = f[i-1];
        g[i] = g[i-1];
        while ( lpf[x] ){
            int tmp = lpf[x];

            if ( !cnt[tmp] ) f[i] ++;
            else g[i] = mul(g[i], inve[cnt[tmp]]);

            while ( x % tmp == 0 ) cnt[tmp] ++, x /= tmp;

            g[i] = mul(g[i], cnt[tmp]);
        }
    }

    int test;
    cin >> test;
    while ( test -- ){
        cin >> n >> k;

        if ( n == 1 ){
            if ( k == 1 ) { cout << 1 << '\n'; continue; }
            else { cout << 0 << '\n'; continue; }
        }

        /// th co 1 hop = 1
        int tmp1 = 0;
        for (int i = 0; i < k; i ++){
            int tmp = mul(C(k-1, i), Pow(k-1-i, f[n]));
            if ( i % 2 == 0 ) tmp1 = add(tmp1, tmp);
            else tmp1 = add(tmp1, -tmp);
        }
        tmp1 = mul(tmp1, inv[k-1]);

        int ans = 0;
        for (int i = 0; i <= k; i ++){
            int tmp = mul(C(k, i), Pow(k-i, f[n]));
            if ( i % 2 == 0 ) ans = add(ans, tmp);
            else ans = add(ans, -tmp);
        }

        ans = mul(ans, inv[k]);
        ans = add(ans, tmp1);
        ans = mul(ans, g[n]);

        cout << ans << '\n';
    }

    return 0;
}
