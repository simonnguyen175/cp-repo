#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int n, k, a[55];

struct matrix{
    ll v[55][55];
};


matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1; i <= k; i ++)
        for (int j = 1; j <= k; j ++){
            c.v[i][j] = 0;
            for (int l = 0; l <= k; l ++)
                c.v[i][j] = (c.v[i][j] + (a.v[i][l] * b.v[l][j])%(MOD-1))%(MOD-1);
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

ll Pow(ll x, ll y){
    if ( y == 1 ) return x;
    ll tmp = Pow(x, y/2);
    if ( y % 2 == 1 ) return (((tmp*tmp)%MOD)*x)%MOD;
    else return (tmp*tmp)%MOD;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= k; i ++)
        cin >> a[i];

    matrix A;

    memset(A.v, 0, sizeof A.v);
    for (int i = 1; i <= k; i ++) A.v[i][k] = 1;
    for (int i = k-1; i >= 1; i --) A.v[i+1][i] = 1;

    A = mu(A, n-k);

    ll ans = 1;
    for (int i = 1; i <= k; i ++){
        ll cnt = A.v[i][k];
        ans = (ans * Pow(a[i], cnt)) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
