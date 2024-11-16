#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9 + 7;

int n, k;
int c[N][N], dp[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("trash.inp", "r") ){
//        freopen("trash.inp", "r", stdin);
//        freopen("trash.out", "w", stdout);
//    }

    cin >> n >> k;

    c[0][0] = 1;
    for (int i = 1; i <= n; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = add(c[i-1][j], c[i-1][j-1]);
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j < i; j ++) if ( j * (n-j) <= k )
            dp[i] = add(dp[i], mul(mul(c[i-2][j-1], dp[j]), mul(j, dp[i-j])));

    cout << dp[n];

    return 0;
}
