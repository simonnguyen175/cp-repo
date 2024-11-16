#include <bits/stdc++.h>
using namespace std;

int n, x, a[101][101], dp[101][101];

int main(){
    cin >> n >> x;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=x; j++)
            cin >> a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=x; j++){
            dp[i][j]=dp[i-1][j];
            for (int k=1; k<=j; k++)
                dp[i][j]= max(dp[i][j], dp[i-1][j-k]+a[i][k]);
        }
    cout << dp[n][x];
    return 0;
}
