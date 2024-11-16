#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int c, n, m, k;
int f[N], g[N];

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

    /// f[len] = tich cac chieu mo doc cach nhau len
    for (int len = 1; len <= n; len ++){
        f[len] = 0;
        for (int i = 1; i <= n-len+1; i ++)
            f[len] = add(f[len], mul(i, n - (i+len-1) + 1));
    }

    /// g[len] = tich cac chieu mo ngang cach nhau len
    for (int len = 1; len <= m; len ++){
        g[len] = 0;
        for (int i = 1; i <= m-len+1; i ++)
            g[len] = add(g[len], mul(i, m - (i+len-1) + 1));
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++) if ( i * j == k ){
        ans = add(ans, Pow(mul(f[i], g[j])))
        ans = add(ans, Pow(mul(f[i], g[j]), c));
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
