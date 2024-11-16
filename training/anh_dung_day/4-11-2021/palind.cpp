#include <bits/stdc++.h>
#define simon "chiphi"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=5e2+1;
const ll oo=1e15;
const int MOD=123456789;

int n, dp[51][51][51][51];
char a[N][N];

int main(){
    FASTio
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    if ( a[1][1] == a[n][n] ) dp[1][1][n][n]=1;
    else{
        cout << 0;
        return 0;
    }
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    for (int x=n; x>=1; x--)
    for (int y=n; y>=1; y--){
        if ( i > x || j > y ) continue;
        if ( a[i][j] != a[x][y] ) continue;
        dp[i][j][x][y] += dp[i-1][j][x+1][y]+
                          dp[i-1][j][x][y+1]+
                          dp[i][j-1][x+1][y]+
                          dp[i][j-1][x][y+1];
        dp[i][j][x][y]%=MOD;
    }
    int ans=0;
    for (int i=1; i<=n; i++){
        ans += dp[i][n-i+1][i][n-i+1];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}
