#include<bits/stdc++.h>
#define ll long long
using namespace std;d
const int MOD = 1e9 + 7;
const int N = 205;

int t, n, m, c;
ll f[N][N][N][2];

void solve(){
    memset(f, 0, sizeof f);
    f[1][0][1][1] = f[1][1][0][0] = 1;
    for (int i = 2; i <= 200; i ++)
        for (int j = 0; j <= i; j ++)
            for (int k = 0; k <= i; k ++){
                if ( j == 0 )
                    f[i][j][k][1] = (f[i-1][j][k][1] + f[i-1][j][k-1][0]) % MOD;
                else{
                    f[i][j][k][0] = (f[i-1][j-1][k][1] + f[i-1][j-1][k][0]) % MOD;
                    f[i][j][k][1] = (f[i-1][j][k][1] + f[i-1][j][k-1][0]) % MOD;
                }
            }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    solve();
    cin >> t;
    while ( t -- ){
        cin >> n >> m >> c;
        cout << (f[n][m][c][1] + f[n][m][c][0]) % MOD << '\n';
    }
    return 0;
}
