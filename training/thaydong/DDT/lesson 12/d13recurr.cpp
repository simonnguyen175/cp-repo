#include<bits/stdc++.h>
using namespace std;

int k, n, d;
int b[55], c[55];
struct matrix{
    int v[55][55];
};

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 1; i <= d; i ++)
        for (int j = 1; j <= d; j ++){
            c.v[i][j] = 0;
            for (int l = 1; l <= d; l ++)
                c.v[i][j] = (c.v[i][j] + (a.v[i][l] * b.v[l][j]) + 3*3*3*3) % 3;
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

void solve(){
    cin >> n >> d;
    for (int i = 1; i <= d; i ++){
        cin >> b[i];
        if ( b[i] == -1 ) b[i] = 0;
    }

    matrix A;
    memset(A.v, 0, sizeof A.v);
    for (int i = 1; i < d; i ++) A.v[i][1] = -1; A.v[d][1] = 1;
    for (int i = 2; i <= d; i ++) A.v[i-1][i] = 1;

    A = mu(A, n - 1);

    for (int i = 1; i <= d; i ++){
        int x = 0;
        for (int j = 1; j <= d; j ++)
            (x += b[j] * A.v[j][i]) %= 3;
        cout << x << ' ';
    }

    cout << '\n';
}

int main(){
    cin >> k;
    while ( k -- ) solve();
    return 0;
}
