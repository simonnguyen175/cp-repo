#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
int dp[N];

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

    cin >> n;
    dp[1] = 26;
    for (int i = 2; i <= n; i ++){
        dp[i] = mul(dp[i-1], 26);
        dp[i] = add(dp[i], -dp[(i+1)/2]);
    }

    cout << dp[n];

    return 0;
}
