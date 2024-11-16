#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int MOD = 1e9;

int dp[N], c[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

string trans(int x){
    string res = "";
    while ( x )
        res += (char) (x % 10 + '0'), x /= 10;
    while ( res.size() < 9 ) res += '0';
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int n = N - 5;
    c[0][0] = 1;
    for (int i = 1; i <= n; i ++){
        c[i][0] = 1;
        for (int j = 1; j <= i; j ++)
            c[i][j] = add(c[i-1][j], c[i-1][j-1]);
    }

    dp[1] = dp[0] = 1;
    for (int i = 2; i <= n; i ++)
    for (int j = 1; j < i; j ++) if ( j % 2 )
        dp[i] = add(dp[i], mul(c[i-1][j], mul(dp[j], dp[i-j-1])));

    int q;
    cin >> q;
    while ( q -- ){
        cin >> n;
        cout << trans(dp[n]) << '\n';
    }

    return 0;
}
