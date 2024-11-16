#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int K = 3e2 + 5;
const int MOD = 998244353;

int sub, n, k;
int d[N], a[N], fact[N], inv[N], dp[2][K];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    if ( n < k ) return 0;
    if ( k == 0 ) return 1;
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("line.inp", "r", stdin);
    freopen("line.out", "w", stdout);

    fact[0] = 1;
    for (int i = 1; i < N; i ++)
        fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --)
        inv[i] = mul(inv[i+1], i+1);

    cin >> sub >> n >> k;
    for (int i = 1, h; i <= n; i ++){
        cin >> h;
        d[h] ++;
    }

    int nn = 0;
    for (int i = n; i >= 1; i --)
        if ( d[i] ) a[++nn] = d[i];
    n = nn;

    dp[1][0] = 1;
    int cur = a[1];
    for (int i = 1; i < n; i ++){
        int ii = i%2, jj = (i+1)%2;
        for (int j = 0; j <= k; j ++) if ( dp[ii][j] )
        for (int t = a[i+1]; t >= 0; t --){
            // t thang dung truoc, a[i+1]-t thang dung sau
            // cach xep a[i+1]-t thang dung sau
            if ( j + a[i+1] - t > k ) break;
            dp[jj][j+a[i+1]-t] = add(dp[jj][j+a[i+1]-t], mul(dp[ii][j], C(a[i+1]-t + cur - 1, cur-1)));
        }
        for (int j = 0; j <= k; j ++) dp[ii][j] = 0;
        cur += a[i+1];
    }

    int ans = 0;
    for (int i = 0; i <= k; i ++)
        ans = add(ans, dp[n%2][i]);
    for (int i = 1; i <= n; i ++)
        ans = mul(ans, fact[a[i]]);
    cout << ans;

    return 0;
}
