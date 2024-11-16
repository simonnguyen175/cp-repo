#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
const int D = 1e3 + 5;
const int MOD = 1e9 + 7;

int n, d;
int a[N], f[N][N][D];

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
}

int mul(int a, int b){
    return 1LL*a*b%MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> d;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a+1, a+1+n);

    f[0][0][0] = 1;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
    for (int k = 0; k <= d; k ++) if ( f[i][j][k] ){
        int nk = k + (a[i+1]-a[i]) * j;
        if ( nk > d ) continue;

        if ( j >= 1 ){
        /// them vao 1 trong j nhom hien tai
        // tiep tuc them
        add(f[i+1][j][nk], mul(f[i][j][k], j));
        // chot
        add(f[i+1][j-1][nk], mul(f[i][j][k], j));
        }

        /// them vao nhom moi
        // tiep tuc them
        add(f[i+1][j+1][nk], f[i][j][k]);
        // chot
        add(f[i+1][j][nk], f[i][j][k]);
    }

    cout << f[1][1][0] << ' ' << f[1][0][0] << '\n';

    int ans = 0;
    for (int i = 0; i <= d; i ++)
        add(ans, f[n][0][i]);
    cout << ans;

    return 0;
}
