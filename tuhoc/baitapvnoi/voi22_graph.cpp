#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
const int MOD = 1e9 + 7;

int n, b;
int a[N], dp[N][N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("graph.inp", "r", stdin);
    freopen("graph.out", "w", stdout);

    cin >> n >> b;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    reverse(a + 1, a + 1 + n);

    dp[0][0] = 1;

    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= min(i, b); j ++){
            if ( a[i] != -1 ){
                if ( a[i] > 0 && !j ) continue;
                if ( a[i] + (j-(a[i]>0)) > b ) continue;
                dp[i][j] = add(dp[i][j], dp[i-1][j-(a[i]>0)]);
            }
            else{
                // gan bac cua dinh i = 0
                dp[i][j] = add(dp[i][j], dp[i-1][j]);

                // gan bac cua dinh i > 0
                if ( j > 0 ){
                    int pre = max(0, min(b - j + 1, n - i));
                    dp[i][j] = add(dp[i][j], mul(pre, dp[i-1][j-1]));
                }
            }
        }
    }


    int ans = 0;
    for (int i = 0; i <= n; i ++)
        ans = add(ans, dp[n][i]);

    cout << ans;

    return 0;
}
