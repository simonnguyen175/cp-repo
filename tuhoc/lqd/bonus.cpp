#include<bits/stdc++.h>
#define simon "bonus"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e3 + 5;

int n, d, c[2*N], dp[2*N][2*N], ans = 0 ;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> d;
    for (int i=1; i<=2*n; i++)
        cin >> c[i];
    for (int l=1; l<=2*n; l++)
        for (int r=2*n; r>=1; r--){
            if ( r <= l ) continue;
            dp[l][r] = max(dp[l-1][r], dp[l][r+1]);
            if ( abs(c[r]-c[l]) <= d )
                dp[l][r] = max(dp[l][r], dp[l-1][r+1] + 1);
            ans = max(dp[l][r], ans);
        }

    cout << ans;
    return 0;
}
