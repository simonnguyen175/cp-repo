#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e2+1;

int n, m, k;
ll a[401], dp[401][401], ans=1e15;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    //solve
    //duyet do dai 1->m
    for (int l=0; l<=m; l++){
        //khoi tao
        for (int i=0; i<=n; i++)
            for (int j=0;j<=m;j++)
                dp[i][j] = 1e15;
        for (int i=0; i<=m; i++)
            dp[0][i] = 0;
        for (int i=1; i<=n; i++)
            dp[i][0] = dp[i-1][0] + ( i % k == 0 ? 0 : a[i] );
        //DP
        for (int i=1; i<=n; i++)
            for (int j=1; j<=min(i,l); j++){
                if (i == j){
                    dp[i][j] = dp[i-1][j-1] + ( ( n-l+j ) % k == 0 ? 0 : a[i] );
                    continue;
                }
                if (i != j)
                    dp[i][j] = min( dp[i-1][j-1] + ( ( n-l+j ) % k == 0 ? 0 : a[i] ), dp[i-1][j] + ( ( i-j ) % k == 0 ? 0 : a[i] ) );
            }
        //cap nhat ans
        ans = min(ans, dp[n][l]);
    }
    cout << ans;
    return 0;
}
