#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, MOD;

struct matrix{
    int v[2][2];
};

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

matrix mul(matrix a, matrix b){
    matrix c;
    memset(c.v, 0, sizeof c.v);

    for (int i = 0; i <= 1; i ++)
    for (int j = 0; j <= 1; j ++)
    for (int k = 0; k <= 1; k ++){
       c.v[i][j] = add(c.v[i][j], mul(a.v[i][k], b.v[k][j]));
    }

    return c;
}

matrix Pow(matrix a, int b){
    if ( b == 1 ) return a;
    matrix tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> MOD;

    if ( 2 * (n - 1) - 1 == 1 ) return cout << 1, 0;

    matrix a;
    a.v[0][0] = 0;
    a.v[0][1] = a.v[1][0] = a.v[1][1] = 1;

    a = Pow(a, 2 * (n - 1) - 2);

    cout << a.v[1][1];

    return 0;
}
