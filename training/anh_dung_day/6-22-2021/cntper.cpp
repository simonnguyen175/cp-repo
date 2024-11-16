#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n, k;
ll dp[N][(1 << 12)];

int Bit(int x, int k){
    return (x >> k) & 1;
}

ll gt(){
    ll res = 1;
    for (int i = 1; i <= n; i ++){
        res *= i % MOD;
        res %= MOD;
    }
    return res;
}

int main(){
    cin >> n >> k;

    if ( n <= k ){ cout << gt(); return 0;}
    if ( k == 0 ) {cout << 1; return 0;}

    int mx = ( 1 << (2*k+1) ) - 1;

    dp[0][0] = 1;
    for (int i = 0; i <= n - 1; i ++)
        for (int mask = 0; mask <= mx; mask ++){
            bool c = 1;
            for (int j = 0; j <= 2 * k; j ++)
                if ( ( i - (k - j) + 1 <= 0 && Bit(mask, j) ) || ( Bit(mask, j) && (i + j - k) > n ) )
                    c = 0;
            if ( !c ) continue;

            int nmask = mask >> 1;
            for (int j = 0; j <= 2 * k; j ++){
                if ( !Bit(nmask, j) && i - (k - j) + 1 > 0 && (i + j - k) <= n )
                    dp[i+1][nmask | (1 << j)] = (dp[i+1][nmask | (1 << j)] % MOD + dp[i][mask] % MOD) % MOD;

            }
        }

    int l = (1 << (k + 1)) - 1;
    cout << dp[n][l];

    return 0;
}
