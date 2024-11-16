#include<bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
const int MOD = 1e9 + 7;

int W, B, R, K, M;
int dp[N][N][N][2], f[N][N], g[N][N], c[N][N];

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

    cin >> W >> B >> R >> K >> M;

    // dp(i, j, k, 0/1)
    // i b, j r, k vtri khac nhau, b/r;
    dp[1][0][0][0] = dp[0][1][0][1] = 1;
    for (int i = 0; i <= B; i ++)
    for (int j = 0; j <= R; j ++)
    for (int k = 0; k < B+R; k ++)
    for (int t = 0; t <= 1; t ++) if ( dp[i][j][k][t] ){
        if ( !t ){
            dp[i+1][j][k][0] = add(dp[i+1][j][k][0], dp[i][j][k][0]);
            dp[i][j+1][k+1][1] = add(dp[i][j+1][k+1][1], dp[i][j][k][0]);
        }
        else{
            dp[i+1][j][k+1][0] = add(dp[i+1][j][k+1][0], dp[i][j][k][1]);
            dp[i][j+1][k][1] = add(dp[i][j+1][k][1], dp[i][j][k][1]);
        }
    }

//    cout << dp[1][2][2][1] << ' ' << dp[1][2][1][0] << ' ' << dp[1][2][1][1] << '\n';

    // f(i, j) i thang vao j vtri moi vtri >= 0 < k
    f[0][0] = 1;
    for (int i = 0; i <= W; i ++)
    for (int j = 0; j <= B+R+1; j ++) if ( f[i][j] )
    for (int k = 0; k <= min(W-i, K-1); k ++)
        f[i+k][j+1] = add(f[i+k][j+1], f[i][j]);

    // g(i, j) i thang vao j vtri moi vtri > 0 < k
    g[0][0] = 1;
    for (int i = 0; i <= W; i ++)
    for (int j = 0; j <= B+R+1; j ++) if ( g[i][j] )
    for (int k = 1; k <= min(W-i, K-1); k ++)
        g[i+k][j+1] = add(g[i+k][j+1], g[i][j]);

    // C(n, k)
    c[0][0] = 1;
    for (int i = 1; i <= B+R; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = add(c[i-1][j], c[i-1][j-1]);
    }

    int ans = 0;
    for (int i = M; i <= B+R-1; i ++){
        int tmp = add(dp[B][R][i][0], dp[B][R][i][1]);
        if ( !tmp ) continue;
//        cout << i << ' ' << tmp << " : \n";
        for (int j = i-M; j <= W; j ++){
//            cerr << j << " : " << g[j][i-M] << ' ' << f[W-j][B+R+1-i] << ' ' << c[i][M] << '\n';
            ans = add(ans, mul(tmp, mul(mul(g[j][i-M], f[W-j][B+R+1-i]), c[i][M])));
        }
    }

    cout << ans;

    return 0;
}
