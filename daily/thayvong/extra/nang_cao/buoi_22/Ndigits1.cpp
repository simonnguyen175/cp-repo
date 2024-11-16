#include<bits/stdc++.h>
#define ll long long
#define simon "Ndigits1"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e4+5;
const int K=1e2+5;
const int MOD=1e9+7;

ll n, k;
ll dp[N][K];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> k;

    memset(dp, 0, sizeof dp);
    for (int i=1; i<=9; i++)
        dp[1][i%k]++;

    for (int i=2; i<=n; i++)
        for (int j=0; j<k; j++)
            for (int t=0; t<=9; t++){
                dp[i][j] += dp[i-1][(j-t+5*k)%k];
                dp[i][j] %= MOD;
            }
    cout << dp[n][0]%MOD;
    return 0;
}
