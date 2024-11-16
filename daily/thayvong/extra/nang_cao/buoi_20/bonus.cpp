#include <bits/stdc++.h>
#define simon "bonus"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=3e2+5;
const ll oo=1e18;

int n, k, a[N];
ll dp[N][N][N];

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    memset(dp, 0, sizeof dp);
    for (int i=n; i>=1; i--)
        for (int j=i; j<=n; j++)
            for (int t=1; t<=k; t++){
                if ( i > j ) continue; dp[i][j][t]=max(dp[i+1][j][t], dp[i][j-1][t]);
                if ( i <= j-1 ){
                    dp[i][j][t]=max({dp[i][j][t], dp[i][j-2][t-1]+abs(a[j]-a[j-1]),
                    dp[i+2][j][t-1]+abs(a[i]-a[i+1]),
                    dp[i+1][j-1][t-1]+abs(a[i]-a[j])});
                }
            }
    cout << dp[1][n][k];
    return 0;
}
