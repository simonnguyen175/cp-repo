#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9 + 5;

int n;
int a[N], dp[N][N];

void ckmn(int &a, int b){
    a = min(a, b);
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        dp[i][j] = oo;

    dp[0][0] = 0;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= i; j ++) if ( dp[i][j] != oo ){
        if ( j == 0 ){
            ckmn(dp[i+3][i+1], dp[i][j] + max(a[i+2], a[i+3]));
            ckmn(dp[i+3][i+2], dp[i][j] + max(a[i+1], a[i+3]));
            ckmn(dp[i+2][0], dp[i][j] + max(a[i+1], a[i+2]));
        }
        else{
            ckmn(dp[i+2][j], dp[i][j] + max(a[i+1], a[i+2]));
            ckmn(dp[i+2][i+1], dp[i][j] + max(a[j], a[i+2]));
            ckmn(dp[i+1][0], dp[i][j] + max(a[j], a[i+1]));
        }
    }

    int ans = min(dp[n][0], dp[n-1][0] + a[n]);
    for (int i = 1; i <= n; i ++)
        ans = min(ans, dp[n][i] + a[i]);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("SuperMarket.inp", "r") ){
//        freopen("SuperMarket.inp", "r", stdin);
//        freopen("SuperMarket.out", "w", stdout);
//    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
