#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, m;
int dp[N][N], f[N][N], g[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    // dp[i][j] dung i block, khoang cach hang tren la j
    dp[0][n] = f[0][n] = g[0][n] = 1;
    for (int i = n-1; i >= 1; i --){
        f[0][i] += f[0][i+1];
        g[0][i] = g[0][i+1] + f[0][i];
    }

    for (int i = 1; i <= m; i ++){
        for (int j = n-1; j >= 1; j --){
            if ( i >= (n-j) ) dp[i][j] = add(dp[i][j], g[i-(n-j)][j]);
            f[i][j] = add(f[i][j+1], dp[i][j]);
            g[i][j] = add(g[i][j+1], f[i][j]);
        }
    }

    int ans = 0;
    for (int i = n; i <= m; i += n)
        ans = add(ans, f[m-i][1]);

    cout << ans;

    return 0;
}
