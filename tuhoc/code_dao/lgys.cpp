#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;

int m, n, s, k;
int f[N][N], g[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n >> s >> k;

    f[0][0] = 1;
    for (int i = 0; i <= s; i ++)
    for (int j = 0; j <= m; j ++) if ( f[i][j] ){
        f[i+1][j+1] = add(f[i+1][j+1], mul(f[i][j], m-j));
        if ( j > 0 ) f[i+1][j-1] = add(f[i+1][j-1], mul(f[i][j], j));
    }

    g[0][0] = 1;
    for (int i = 0; i <= s; i ++)
    for (int j = 0; j <= n; j ++) if ( g[i][j] ){
        g[i+1][j+1] = add(g[i+1][j+1], mul(g[i][j], n-j));
        if ( j > 0 ) g[i+1][j-1] = add(g[i+1][j-1], mul(g[i][j], j));
    }

    cout << f[4][4] << ' ' << g[4][4] << '\n';

//    int ans = 0;
//    for (int x = 0; x <= m; x ++)
//    for (int y = 0; y <= n; y ++)
//    if ( x * n + y * m - 2 * x * y == k ){
//        cout << x << ' ' << y << ' ' << f[s][x] << ' ' << g[s][y] << '\n';
//        ans = add(ans, mul(f[s][x], g[s][y]));
//    }
//
//    cout << ans;

    return 0;
}
