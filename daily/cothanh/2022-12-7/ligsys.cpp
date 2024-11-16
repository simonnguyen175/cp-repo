#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 5;
const int MOD = 111539786;

int m, n, s, k;
int col[N][N], row[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("ligsys.inp", "r", stdin);
    freopen("ligsys.out", "w", stdout);

    cin >> m >> n >> s >> k;

    /// row(i, j) i thao tac va j hang bat
    row[0][0] = 1;
    for (int i = 0; i < s; i ++)
    for (int j = 0; j <= m; j ++) if ( row[i][j] ){
        if ( j > 0 ) row[i+1][j-1] = add(row[i+1][j-1], mul(row[i][j], j));
        if ( j < m ) row[i+1][j+1] = add(row[i+1][j+1], mul(row[i][j], m-j));
    }

    /// col(i, j) i thao tac va j cot bat
    col[0][0] = 1;
    for (int i = 0; i < s; i ++)
    for (int j = 0; j <= n; j ++) if ( col[i][j] ){
        if ( j > 0 ) col[i+1][j-1] = add(col[i+1][j-1], mul(col[i][j], j));
        if ( j < n ) col[i+1][j+1] = add(col[i+1][j+1], mul(col[i][j], n-j));
    }

    int ans = 0;
    for (int i = 0; i <= m; i ++)
    for (int j = 0; j <= n; j ++) if ( n*i + m*j - 2*i*j == k )
        ans = add(ans, mul(row[s][i], col[s][j]));

    cout << ans;

    return 0;
}
