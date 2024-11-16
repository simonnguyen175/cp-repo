#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int MOD = 998244353;

int n, m, fact[N], inv[N], f[20][N];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

//    cerr << fact[3] << ' ' << inv[0] << ' ' << C(4, 2) << '\n';

    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        f[0][i] = 1;

    for (int i = 0; i < __lg(m); i ++)
    for (int j = 1; j <= m; j ++) if ( f[i][j] )
        for (int k = 2*j; k <= m; k += j)
            f[i+1][k] = add(f[i+1][k], f[i][j]);

    int ans = 0;
    for (int i = 0; i <= __lg(m); i ++)
    for (int j = 1; j <= m; j ++)
        ans = add(ans, mul(C(n-1, n-i-1), f[i][j]));

    cout << ans;

    return 0;
}
