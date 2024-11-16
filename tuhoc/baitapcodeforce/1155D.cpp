#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll oo=-300000000000000;

int n, x;
ll a[300001], dp[300001][3], ans=0;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n >> x;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++){
            dp[i][0]=max(dp[i-1][0]+a[i], a[i]);
            dp[i][1]=max(max(dp[i-1][0],dp[i-1][1])+a[i]*x,a[i]*x);
            dp[i][2]=max(max(dp[i-1][1],dp[i-1][2])+a[i],a[i]);
            ans=max(ans,max(max(dp[i][1],dp[i][2]),dp[i][0]))-+;
        }
    cout << ans;
    return 0;
}
