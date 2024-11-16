#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 777777777;

int n, k = 0;
ll s;
int num[30], m[30];
ll f[30];

struct matrix{
    ll v[30][30];
};

matrix mul(matrix a, matrix b){
    matrix c;
    for (int i = 0; i <= 26; i ++)
        for (int j = 0; j <= 26; j ++){
            c.v[i][j] = 0;
            for (int l = 0; l <= 26; l ++)
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
    cin >> n >> s;
    memset(num, 0, sizeof num);
    for (int i = 1; i <= n; i ++){
        cin >> m[i];
        num[m[i]] ++;
    }

    f[0] = 1;
    for (int i = 1; i <= 26; i ++)
        for (int j = 1; j <= n; j ++)
            if ( i >= m[j] )
                f[i] += f[i-m[j]];

    if ( s <= 26 ) cout << f[s] << '\n';
    else{
        matrix A;
        memset(A.v, 0, sizeof A.v);

        for (int i = 0; i <= 26; i ++) A.v[i][26] = num[27-i];

        for (int i = 25; i >= 0; i --) A.v[i+1][i] = 1;

        A = mu(A, s - 26);

        ll res = 0;

        for (int i = 0; i <= 26; i ++) res = (res + f[i]*A.v[i][26])%MOD;
        cout << res << '\n';
    }
    return 0;
}
