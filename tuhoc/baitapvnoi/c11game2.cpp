#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
const int oo = 1e9;

int n, n0, n1, c00, c01;
int a[2][N], dp[N][N][N];

void ckmx(int &a, int b){
    a = max(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 0; i <= 1; i ++)
    for (int j = 1; j <= n; j ++){
        int x;
        cin >> x;
        if ( !i ){
            if ( !x ) c00 ++;
            else a[i][++n0] = x;
        }
        else{
            if ( !x ) c01 ++;
            else a[i][++n1] = x;
        }
    }

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= c00; j ++)
    for (int k = 0; k <= c01; k ++)
        dp[i][j][k] = dp[i][j][k] = -oo;

    dp[0][0][0] = 0;
    int ans = -oo;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= min(i, c00); j ++)
    for (int k = 0; k <= min(i, c01); k ++) if ( dp[i][j][k] != -oo ){
        ckmx(dp[i+1][j][k], dp[i][j][k] + a[0][i+1-j] * a[1][i+1-k]);
        if ( j + 1 <= c00 ) ckmx(dp[i+1][j+1][k], dp[i][j][k]);
        if ( k + 1 <= c01 ) ckmx(dp[i+1][j][k+1], dp[i][j][k]);
        if ( j + 1 <= c00 && k + 1 <= c01 )
            ckmx(dp[i+1][j+1][k+1], dp[i][j][k]);
    }

    cout << dp[n][c00][c01];

    return 0;
}
