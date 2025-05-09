#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

ll n, a[5], c;

struct matrix{
    ll v[5][5];
};

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1; i <= 3; i ++)
        for (int j = 1; j <= 3; j ++){
            c.v[i][j] = 0;
            for (int l = 1; l <= 3; l ++)
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
    cin >> n;
    for (int i = 1; i <= 3; i ++)
        cin >> a[i];
    cin >> c;
    for (int i = 1; i <= 3; i ++)
        (a[i] *= Pow(c%MOD, i)) %= MOD;
    matrix A;

    memset(A.v, 0, sizeof A.v);
    for (int i = 1; i <= 3; i ++) A.v[i][3] = 1;
    for (int i = 2; i >= 1; i --) A.v[i+1][i] = 1;

    A = mu(A, n-3);

    ll ans = 1;
    for (int i = 1; i <= 3; i ++){
        ll cnt = A.v[i][3];
        ans = (ans * Pow(a[i], cnt)) % MOD;
    }

    ans = (ans*Pow(Pow(c, n), MOD-2))%MOD;

    cout << ans << '\n';
    return 0;
}
