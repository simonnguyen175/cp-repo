#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;

int t;
struct matrix{
    ll v[2][2];
} A;

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 0; i <= 1; i ++)
        for (int j = 0; j <= 1; j ++){
            c.v[i][j] = 0;
            for (int l = 0; l <= 1; l ++)
                c.v[i][j] = (c.v[i][j] + (a.v[i][l] * b.v[l][j])%(MOD))%(MOD);
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

ll Fib(int n){
    if ( n <= 1 ) return 1;
    A.v[0][0] = 0; A.v[0][1] = A.v[1][0] = A.v[1][1] = 1;
    A = mu(A, n-1);
    return (A.v[0][1] + A.v[1][1])%MOD;
}

int main(){
    cin >> t;
    while ( t -- ){
        int l, r;
        cin >> l >> r;
        cout << Fib(r+1) << ' ' << Fib(l) << '\n';
        cout << (Fib(r+1) - Fib(l) + MOD*MOD*1LL) % MOD << '\n';
    }
    return 0;
}
