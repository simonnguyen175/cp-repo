#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9;

int t, n, k, b[15], c[15];

struct matrix{
    ll v[15][15];
};

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1; i <= k; i ++)
        for (int j = 1; j <= k; j ++){
            c.v[i][j] = 0;
            for (int l = 1; l <= k; l ++)
                c.v[i][j] = (c.v[i][j] + (a.v[i][l] * b.v[l][j])%MOD) % MOD;
        }
    return c;
}

matrix mu(matrix a, int n){
    if ( n == 1 ) return a;
    matrix tmp = mu(a, n/2);
    tmp = mul(tmp, tmp);
    if ( n % 2 ) return mul(tmp, a);
    else return tmp;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    while ( t -- ){
        cin >> k;
        for (int i = 1; i <= k; i ++) cin >> b[i];
        for (int i = 1; i <= k; i ++) cin >> c[i];
        cin >> n;
        matrix A;
        memset(A.v, 0, sizeof A.v);
        for (int i = 1; i <= k; i ++) A.v[i][1] = c[i];
        for (int i = 2; i <= k; i ++) A.v[i-1][i] = 1;

        if ( n <= k ) cout << b[n] << '\n';
        else{
            A = mu(A, n-k);
            ll res = 0;
            for (int i = 1; i <= k; i ++) res = ( res + b[k-i+1]*A.v[i][1] ) % MOD;
            cout << res << '\n';
        }
    }

    return 0;
}

