#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 998244353;
const int N = 2005;

int n, m;
ll s[2][N][N], f[2][N][N];
char a[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if ( fopen("pushingrocks.inp", "r") ){
        freopen("pushingrocks.inp", "r", stdin);
        freopen("pushingrocks.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++){
        cin >> a[i][j];
        if (a[i][j] == 'R')
            s[0][i][j] = s[1][i][j] = 1;
    }

    if ( n == 1 and m == 1 ){
        cout << ( a[n][m] == '.' ? 1 : 0 );
        return 0;
    }

    for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--){
        s[0][i][j] += s[0][i + 1][j];
        s[1][i][j] += s[1][i][j + 1];
    }

    f[0][1][1] = f[1][1][1] = 1;
    f[0][2][1] = f[1][1][2] = -1;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        // di xuong
        f[0][i][j] += f[0][i-1][j] % MOD;
        f[1][i][j+1] += f[0][i][j] %= MOD;
        ( f[1][i][m-s[1][i][j+1]+1] -= f[0][i][j] - MOD ) %= MOD;

        // di sang
        f[1][i][j] += f[1][i][j-1] %= MOD;
        f[0][i+1][j] += f[1][i][j] %= MOD;
        ( f[0][n-s[0][i+1][j]+1][j] -= f[1][i][j] - MOD ) %= MOD;

    }
    cout << ( f[0][n][m] + f[1][n][m] + 2*MOD ) % MOD;

    return 0;
}

