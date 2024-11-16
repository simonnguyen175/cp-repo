#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 5;
const int MOD = 1e9 + 7;

int n;
int a[N], f[N][N][2];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];


    // f(l,r,0) la so cach noi trong doan (l,r) lien thong voi nhau ( l noi r )
    // f(l,r,1) la so cach noi trong doan (l,r) lien thong voi nhau

    for (int i = 1; i <= n; i ++) f[i][i][1] = 1;


    for (int len = 2; len <= n; len ++)
    for (int i = 1, j; i <= n - len + 1; i ++){
        j = i + len - 1;
        for (int k = i; k <= j; k ++){
            if ( __gcd(a[i], a[j]) != 1 )
            f[i][j][0] = add(f[i][j][0], mul(f[i][k][1], f[k+1][j][1]));
            if ( __gcd(a[i], a[k]) != 1 )
            f[i][j][1] = add(f[i][j][1], mul(f[i][k][0], f[k][j][1]));
        }
    }

    cout << f[1][n][1];

    return 0;
}
