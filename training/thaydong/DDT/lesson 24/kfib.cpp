#include<bits/stdc++.h>
using namespace std;

int M, A, B;
map<pair<int, int>, int> d;

int add(int a, int b){
    a += b;
    if ( a >= M ) a -= M;
    if ( a < 0 ) a += M;
    return a;
}

struct matrix{
    int v[3][3];
};
matrix mul(matrix a, matrix b){
    matrix c;
    memset(c.v, 0, sizeof c.v);
    for (int i = 1; i <= 2; i ++)
    for (int j = 1; j <= 2; j ++)
    for (int k = 1; k <= 2; k ++)
        c.v[i][j] = add(c.v[i][j], 1LL*a.v[i][k]*b.v[k][j]%M);
    return c;
}
matrix Pow(matrix a, int n){
    if ( n == 1 ) return a;
    matrix tmp = Pow(a, n/2);
    if ( n % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int fibo(int x){
    if ( x == 0 ) return 0;
    if ( x == 1 ) return 1;

    matrix a;
    a.v[1][1] = 0;
    a.v[1][2] = a.v[2][1] = a.v[2][2] = 1;

    a = Pow(a, x-1);
    return a.v[2][2];
}

void solve(){
    cin >> M >> A >> B;
    int K = sqrt(6*M);

    // duyet b
    d.clear();
    d[{A, B}] = 0;
    for (int i = 1; i <= K; i ++){
        int cur = add(B, -A);
        B = A;
        A = cur;
        d[{A, B}] = i;
    }

    // duyet a
    for (int i = 0; i <= K; i ++){
        int a = fibo(i*K);
        int b = fibo(i*K+1);
        if ( d.find({a, b}) != d.end() ){
            cout << i * K + d[{a, b}] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("kfib.inp", "r") ){
        freopen("kfib.inp", "r", stdin);
        freopen("kfib.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test-- )
        solve();

    return 0;
}
