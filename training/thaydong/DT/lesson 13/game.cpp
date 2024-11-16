#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;

int n, k, f, a, b, m;
int c[N], dp[N], dq[2*N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k >> f >> a >> b >> m;
    a %= m, b %= m;
    c[1] = f % m;
    for (int i = 2; i <= n; i ++)
        c[i] = ( c[i-1] * a + b ) % m;

    dp[0] = 0;
    int l = 1, r = 0;
    dq[++r] = 0;
    for (int i = 1; i <= n + 1; i ++){
        while ( dq[l] < i - k ) l ++;
        dp[i] = dp[dq[l]] + c[i];
        while ( dp[dq[r]] > dp[i] ) r --;
        dq[++r] = i;
    }

    cout << dp[n+1];

    return 0;
}
