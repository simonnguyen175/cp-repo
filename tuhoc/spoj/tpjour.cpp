#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 25;
const int MOD = 1e9 + 9;

int n, m, k, d;
bool adj[N][N];
struct matrix{
    ll v[N][N];
};

void init(){
    cin >> n >> m >> k >> d;
    memset(adj, 0, sizeof adj);
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
}

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            c.v[i][j] = 0;
            for (int l = 0; l <= n; l ++)
                c.v[i][j] = (c.v[i][j] + (a.v[i][l] * b.v[l][j])%MOD) % MOD;
        }
    return c;
}

matrix mu(matrix a, ll n){
    if ( n == 1 ) return a;
    matrix tmp = mu(a, n/2);
    tmp = mul(tmp, tmp);
    if ( n % 2 ) return mul(tmp, a);
    else return tmp;
}
void solve(){
    if ( d == 1 ){
        if ( k == 1 ) cout << k << '\n';
        else cout << 0 << '\n';
        return;
    }
    ll ans = 0;
    for (int mask = 0; mask <= (1<<k)-1; mask ++){
        matrix A;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                A.v[i][j] = adj[i][j];

        for (int i = 1; i <= k; i ++)
            if ( (mask&(1<<(i-1))) ){
                for (int j = 1; j <= n; j ++)
                    A.v[i][j] = A.v[j][i] = 0;
            }

        A = mu(A, d-1);

        ll res = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( j <= k && (mask&(1<<(j-1))) ) continue;
                else res = (res + A.v[i][j])%MOD;

        if ( __builtin_popcount(mask) % 2 == 1 ) ans = (ans - res + MOD) % MOD;
        else ans = (ans + res) % MOD;
    }

    cout << ans << '\n';
}

int main(){
    init();
    solve();
    return 0;
}
