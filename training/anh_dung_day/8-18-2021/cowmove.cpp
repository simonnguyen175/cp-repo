#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 9;

int t, n, m, k;
pi pot[1000];
long long fact[N], inv[N], f[1000];

long long Pow(long long x, long long y){
    if ( y == 0 ) return 1;
    long long tmp = Pow(x, y/2);
    if ( y % 2 ) return  tmp * tmp % MOD * x % MOD;
    else return tmp * tmp % MOD;
}

long long C(long long a, long long b){
    if ( b == 0 ) return 1;
    if ( b > a ) return 0;
    if ( a == b ) return 1;
    return fact[a] * inv[a-b] % MOD * inv[b] % MOD;
}

void solve(){
    sort(pot + 1, pot + 1 + k);
    memset(f, 0, sizeof f);

    for (int i = 1; i <= k; i ++){
        long long x = pot[i].fi, y = pot[i].se;
        //cout << "cell " << x << ' ' << y << " : " << '\n';
        f[i] = C(x + y - 2, x - 1);
        //cout << f[i] << '\n';
        for (int j = 1; j <= k; j ++)
            if ( j != i && pot[j].fi <= x && pot[j].se <= y ){
                long long a = (x - pot[j].fi + 1 + MOD) % MOD, b = (y - pot[j].se + 1 + MOD) % MOD;
                //cout << a << ' ' << b << ' ' << f[j] << ' '  << C(a + b - 2, a - 1) << '\n';
                f[i] = ( f[i] - f[j] * C(a + b - 2, a - 1) % MOD + 1LL * MOD * MOD ) % MOD;
            }

        //cout << f[i] << '\n';
    }

    long long ans = C(n + m - 2, n - 1);
    for (int i = 1; i <= k; i ++){
        long long a = ( n - pot[i].fi + 1 + MOD ) % MOD, b = ( m - pot[i].se + 1 + MOD) % MOD;
        ans = ( ans - f[i] * C(a + b - 2, a - 1) % MOD + 1LL * MOD * MOD ) % MOD;
    }

    cout << ans << '\n';
}

int main(){
    if ( fopen("cowmove.inp", "r") ){
        freopen("cowmove.inp", "r", stdin);
        freopen("cowmove.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = (fact[i-1] * i) % MOD;

    inv[N-1] = Pow(fact[N-1], MOD - 2);
    for (int i = N - 2; i >= 1; i --)
        inv[i] = (i+1) * inv[i+1] % MOD;

    cin >> t;

    while ( t -- ){
        cin >> n >> m >> k;
        for (int i = 1; i <= k; i ++)
            cin >> pot[i].fi >> pot[i].se;
        solve();
    }

    return 0;
}
