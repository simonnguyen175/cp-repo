#include <bits/stdc++.h>
#define simon "chiphi"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=5e2+5;
const ll oo=1e15;
const int MOD=123456789;

int n, dp[N][N][2];
char a[N][N];

int main(){
    /// input
    FASTio
    cin >> n;
    for(int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    if ( a[1][1] != a[n][n] ){
        cout << 0;
        return 0;
    }

    /// DP
    /* dp[i][j][k] so cach di de duoc xau palin khi di den i dong tu
    tren xuong va j dong tu duoi len va da di duoc k buoc */
    int cur=1, pre=0;
    dp[1][n][pre]=1;
    for(int k=2; k<=n; k++){
        for(int i=1; i<=n; i++){
            if ( i > k ) break;
            for(int j=n; j>=i; j--){
                if ( n-j+1 > k ) break;
                if ( a[i][k-i+1] == a[j][n-k+n-j+1] )
                    dp[i][j][cur] = (dp[i-1][j][pre] + dp[i][j][pre] + dp[i][j+1][pre] + dp[i-1][j+1][pre] ) % MOD;
                else dp[i][j][cur]=0;
            }
        }
        swap(cur, pre);
    }

    /// output
    int ans=0;
    for(int i=1; i<=n; i++)
        ans = ( ans + dp[i][i][pre] ) % MOD;
    cout << ans;
    return 0;
}
