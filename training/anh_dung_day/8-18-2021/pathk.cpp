#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100;
const int MOD = 1e9 + 7;

int n;
long long d;
bool adj[N][N];
struct matrix{
    ll v[N][N];
};

void init(){
    cin >> n >> d;
    memset(adj, 0, sizeof adj);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> adj[i][j];
}

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            c.v[i][j] = 0;
            for (int l = 1; l <= n; l ++)
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
    ll ans = 0;
    matrix A;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            A.v[i][j] = adj[i][j];

    A = mu(A, d);

    ll res = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            res = (res + A.v[i][j])%MOD;

    cout << res << '\n';
}

int main(){
    init();
    solve();
    return 0;
}
