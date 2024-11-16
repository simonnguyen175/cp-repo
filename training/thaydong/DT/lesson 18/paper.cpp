#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int c, n, m, k;
int pwc[N*N], f[N], g[N];

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

void solve(){
    cin >> c >> n >> m >> k;

    int mx = max(n, m);
    for (int i = 1; i <= mx * mx; i ++)
        pwc[i] = Pow(i, c);

    for (int i = 1; i <= mx; i ++)
        f[i] = g[i] = 0;

    /// calc row
    for (int i = 1; i <= n; i ++)
    for (int j = i; j <= n; j ++)
        f[j-i+1] = add(f[j-i+1], add(pwc[i*(n-j+1)], -add(pwc[(i-1)*(n-j+1)], add(pwc[i*(n-j)], -pwc[(i-1)*(n-j)]))));

    /// calc col
    for (int i = 1; i <= m; i ++)
    for (int j = i; j <= m; j ++)
        g[j-i+1] = add(g[j-i+1], add(pwc[i*(m-j+1)], -add(pwc[(i-1)*(m-j+1)], add(pwc[i*(m-j)], -pwc[(i-1)*(m-j)]))));

    /// calc ans
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) if ( i * j >= k )
        ans = add(ans, mul(f[i], g[j]));

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;

    while ( test -- )
        solve();

    return 0;
}
