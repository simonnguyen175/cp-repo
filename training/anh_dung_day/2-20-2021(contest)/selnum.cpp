#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll oo=-1000000000000;
ll n, k, m, a[1001], w[1001], dp[1001][1001];

int main(){
    FASTio;
    cin >> n >> k >> m;
    for (ll i=1; i<=m; i++) cin >> w[i];
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<=k; i++) dp[0][i]=oo;
    for (ll i=1; i<=n; i++)
        for (ll j=1; j<=k; j++)
            dp[i][j]=max(dp[i-1][j], dp[i-1][j-1]+(w[ j % m == 0 ? m : j%m ]*a[i]) );
    cout << dp[n][k];
    return 0;
}
