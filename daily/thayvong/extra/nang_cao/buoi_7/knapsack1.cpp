#include <bits/stdc++.h>
using namespace std;

struct dat{
    long long w=0, v=0;
};

dat a[1001];
long long n,m ;
long long dp[101][100001];
long long res=0;

int main(){
    freopen("Knapsack1.inp","r",stdin);
    freopen("Knapsack1.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m ;
    for (int i=1; i<=n; i++)
        cin >> a[i].w ;
    for (int i=1; i<=n; i++)
        cin >> a[i].v ;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m ; j++){
            if ( j < a[i].w )
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max (dp[i-1][j] , dp[i-1][j-a[i].w] + a[i].v);
        }
    cout << dp[n][m];
}
