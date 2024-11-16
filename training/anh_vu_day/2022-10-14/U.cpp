#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const int MOD = 998244353;

int n;
vector<int> odd, even;
int fact[N], inv[N];
int f[N][N][11], g[N][N][11];

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    if ( k == 0 ) return 1;
    if ( n < k ) return 0;
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

void solve(){
    cin >> n;
    odd.clear(), even.clear();
    for (int i = 1; i <= n; i ++){
        string x;
        cin >> x;
        int w = 0;
        for (int i = 0; i < x.size(); i ++)
            if ( i % 2 ) w -= x[i] - '0';
            else w += x[i] - '0';
        w %= 11;
        if ( w < 0 ) w += 11;
        if ( x.size() % 2 ) odd.pb(w);
        else even.pb(w);
    }

    int po = ( odd.size() + 1 ) / 2;
    int pe = odd.size() - po;

    for (int i = 0; i <= odd.size(); i ++)
    for (int j = 0; j <= po; j ++)
    for (int k = 0; k < 11; k ++)
        f[i][j][k] = 0;
    f[0][0][0] = 1;
    for (int i = 0; i < odd.size(); i ++)
    for (int j = 0; j <= po; j ++)
    for (int k = 0; k < 11; k ++) if ( f[i][j][k] ){
        // them vao vtri chan
        int nk = ( k - odd[i] + 11 ) % 11;
        add(f[i+1][j][nk], f[i][j][k]);

        // them vao vtri le
        if ( j < po ){
            nk = ( k + odd[i] ) % 11;
            add(f[i+1][j+1][nk], f[i][j][k]);
        }
    }

    if ( !odd.size() ){
        int cur = 0;
        for (int i = 0; i < even.size(); i ++)
            cur = ( cur + even[i] ) % 11;
        if ( !cur ) cout << fact[n] << '\n';
        else cout << 0 << '\n';
        return;
    }

    for (int i = 0; i <= even.size(); i ++)
    for (int j = 0; j <= even.size(); j ++)
    for (int k = 0; k < 11; k ++)
        g[i][j][k] = 0;
    for (int i = 0; i < 11; i ++)
        g[0][0][i] = mul(f[odd.size()][po][i], mul(fact[po], fact[pe]));

    for (int i = 0; i < even.size(); i ++)
    for (int j = 0; j <= i; j ++)
    for (int k = 0; k < 11; k ++) if ( g[i][j][k] ){
        // them vao vtri chan
        int nk = ( k - even[i] + 11 ) % 11;
        add(g[i+1][j][nk], g[i][j][k]);

        // them vao vtri le
        nk = ( k + even[i] ) % 11;
        add(g[i+1][j+1][nk], g[i][j][k]);
    }

    po = odd.size() / 2 + 1;
    pe = odd.size() - po + 1;
    int ans = 0;
    for (int i = 0; i <= even.size(); i ++){
        int j = even.size()-i;
        int tmp = g[even.size()][i][0];
        tmp = mul(tmp, mul(C(i+po-1, po-1), fact[i]));
        tmp = mul(tmp, mul(C(j+pe-1, pe-1), fact[j]));
        add(ans, tmp);
    }

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("U.inp", "r") ){
        freopen("U.inp", "r", stdin);
        freopen("U.out", "w", stdout);
    }

    fact[0] = 1;
    for (int i = 1; i < N; i ++) fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --) inv[i] = mul(inv[i+1], i+1);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
