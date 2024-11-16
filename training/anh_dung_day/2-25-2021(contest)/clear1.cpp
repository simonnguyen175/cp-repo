#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, t;
ll a[5001], dp[5001][5001];

void input(){
    FASTio;
    cin >> n >> t;
    for (int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    for (int i=1; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j]=-1;
    dp[0][0]=0;
    for (int i=1; i<=n-1; i++)
        for (int j=0; j<=n-1; j++){
            if ( dp[i-1][j] >= 0 ){
                if ( dp[i-1][j-1] < 0 || j == 0 ) dp[i][j]=dp[i-1][j]-t;
                else dp[i][j]=max(dp[i-1][j]-t, dp[i-1][j-1]+a[i]);
            }
            else
                if ( dp[i-1][j-1] >=0 && j > 0 ) dp[i][j]=dp[i-1][j-1]+a[i];
        }
}

void output(){
    for (int i=0; i<=n-1; i++)
        if ( dp[n-1][i] > 0 && dp[n-1][i]+a[n] > 0 ){
            cout <<  i+1;
            return;
        }
    cout << -1;
    return;
}

int main(){
    input();
    solve();
    output();
    return 0;
}
