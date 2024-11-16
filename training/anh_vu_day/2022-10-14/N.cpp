#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 6e3 + 5;
const int MOD = 1e9 + 7;

int n;
pi a[N];
int dp[N][N][2];

void add(int &a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi;
        a[i].se = 0;
    }
    for (int i = n+1; i <= 2*n; i ++){
        cin >> a[i].fi;
        a[i].se = 1;
    }
    n *= 2;
    sort(a + 1, a + 1 + n);

    // dp(i, j, 0/1)
    // den chuong i
    // co j con duoc chon nhung chua co chuong
    // 0/1 co con nao bi bo qua hay chua

    int ans = 0;
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
    for (int k = 0; k <= 1; k ++) if ( dp[i][j][k] ){
        if ( i == n ){
            if ( j == 0 ) add(ans, dp[i][j][k]);
            continue;
        }

        if ( a[i+1].se == 0 ){
            // chon bo
            add(dp[i+1][j+1][k], dp[i][j][k]);
            add(dp[i+1][j][k|1], dp[i][j][k]);
        }
        else{
            // chon chuong
            if ( k == 1 ){
                if ( j ) add(dp[i+1][j-1][k], mul(dp[i][j][k], j));
            }
            else{
                add(dp[i+1][j][k], dp[i][j][k]);
                if ( j ) add(dp[i+1][j-1][k], mul(dp[i][j][k], j));
            }
        }
    }

    cout << ans;

    return 0;
}
