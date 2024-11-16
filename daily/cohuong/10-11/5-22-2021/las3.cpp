#include<bits/stdc++.h>
#define simon "las3"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 5e3 + 5;

int t, n, dp[N][N], ans;
ll a[N];

void solve(){
    if ( n <= 2 ) {ans = n; return;}
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            dp[j][i] = 2;
    ans = 2;

    for (int j = 2; j <= n - 1; j ++){
        int k = j - 1, i = j + 1;
        while ( k >= 1 && i <= n ){

            if ( a[i] + a[k] < 2 * a[j] ){
                //dp[j][k] = 2;
                i ++;
            }

            if ( a[i] + a[k] > 2 * a[j] ) {
                //dp[i][j] = 2;
                k --;
            }

            if ( a[i] + a[k] == 2 * a[j] ){
                dp[i][j] = dp[j][k] + 1;
                ans = max (ans, dp[i][j]);
                //cout << dp[i][j] << ' ' << i << ' ' <<j <<' '<< k <<'\n';
                i ++; k --;
            }

        }
    }

}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> t;
    while ( t -- ){
        cin >> n;
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        solve();
        cout << ans << '\n';
    }

    return 0;
}
