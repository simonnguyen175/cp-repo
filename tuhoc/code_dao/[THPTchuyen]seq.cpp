#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int MOD=1e9+7;

int n, m;
ll dp[N][N], ans=0;

void xuli(int i, int j){
    for (int u=1; u<=sqrt(i); u++)
        if ( i % u == 0 ){
            cout << u <<' '<<dp[u][j-1] <<'\n';
            if ( (i/u)*(i/u) != u ){
                dp[i][j] += dp[u][j-1] + dp[i/u][j-1];
                cout << i/u <<' '<<dp[i/u][j-1] <<'\n';
            }
            else
                dp[i][j] += dp[u][j-1];
        }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        dp[i][1]=1;

    for (int i=1; i<=n; i++){
        cout << i <<'\n';
        for (int j=2; j<=m; j++){
            xuli(i, j);
            dp[i][j] %= MOD;
            cout<< dp[i][j] <<'\n';
        }
        cout <<'\n';
    }

    for (int i=1; i<=n; i++){
        ans += dp[i][m];
        ans %= MOD;
    }

    cout << ans;
    return 0;
}
