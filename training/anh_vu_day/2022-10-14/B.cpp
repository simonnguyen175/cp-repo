#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int m, n, k, s;
pi a[N];
int fact[N], inv[N], f[N][25];

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
    return mul(fact[n], mul(inv[k], inv[n-k]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    fact[0] = 1;
    for (int i = 1; i < N; i ++) fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --) inv[i] = mul(inv[i+1], i+1);

//    cout << fact[3] << ' ' << inv[1] << ' ' << C(3, 2) << ' '  << C(4, 2) << '\n';

    cin >> m >> n >> k >> s;
    for (int i = 1; i <= k; i ++){
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    a[++k] = {1, 1};
    a[++k] = {m, n};
    sort(a + 1, a + 1 + k);

    f[1][0] = 1;
    for (int i = 2; i <= k; i ++){
        f[i][1] = C(a[i].fi+a[i].se-2, a[i].fi-1);
        for (int j = 2; j <= 21; j ++)
        for (int l = 1; l < i; l ++) if ( a[l].se <= a[i].se )
            f[i][j] = add(f[i][j], mul(add(f[l][j-1], -f[l][j]),
                          C(a[i].fi-a[l].fi+a[i].se-a[l].se, a[i].fi-a[l].fi)));
    }

//    cout << f[2][1] << '\n';

    int ans = 0;
    for (int i = 1; i <= 21; i ++){
        ans = add(ans, mul(s, add(f[k][i], -f[k][i+1])));
        s -= s/2;
    }

    ans = mul(ans, Pow(C(m+n-2, m-1), MOD-2));

    cout << ans;

    return 0;
}
