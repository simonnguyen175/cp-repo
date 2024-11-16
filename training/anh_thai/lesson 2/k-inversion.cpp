#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const int lim = 450;
const int MOD = 1e9 + 7;

int n, k;
int fact[N], inv[N], dp[lim][100005];

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int Pow(int a, int b){
    if ( b == 1 ) return a;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;

    fact[0] = 1; inv[0] = 1;
    for (int i = 1; i <= N - 5; i ++)
        fact[i] = mul(fact[i-1], i);

    inv[N-5] = Pow(fact[N-5], MOD - 2);

    for (int i = N - 6; i >= 1; i --)
        inv[i] = mul(inv[i+1], i+1);

    dp[0][0] = 1;
    for (int i = 0; i < lim; i ++)
    for (int j = 0; j <= k; j ++){
        if ( i && j > n )
            dp[i][j] = add(dp[i][j], -dp[i-1][j-n-1]);
        if ( i && j + i <= k )
            dp[i][j+i] = add(dp[i][j+i], dp[i][j]);
        if ( i + 1 < lim && j + i + 1 <= k )
            dp[i+1][j+i+1] = add(dp[i+1][j+i+1], dp[i][j]);
    }

    int ans = 0;
    for (int x = 1; x <= k; x ++){
        for (int i = 1; i < lim; i ++)
        ans = add(ans, ( (i%2) ? 1 : -1 ) * mul(C(k-x+n-1, n-1), dp[i][x]));
    }

    ans = add(C(k+n-1, n-1), -ans);

    cout << ans;

    return 0;
}
