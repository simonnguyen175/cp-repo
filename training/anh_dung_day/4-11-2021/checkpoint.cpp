#include <bits/stdc++.h>
#define simon "checkpoint"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=1e5+1;
const ll oo=1e18;

int n, a[N], dp[N][101], ans=0,k;

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j]=0;
    for(int i=1;i<=n;i++)
        if( a[i] > 0 )
            dp[i][0]=dp[i-1][0]+a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++){
            if( a[i] < 0 )
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+a[i]);
            else dp[i][j] = max(dp[i][j], dp[i-1][j]+a[i]);
            ans=max(ans, dp[i][j]);
        }
    cout << ans;
    return 0;
}
