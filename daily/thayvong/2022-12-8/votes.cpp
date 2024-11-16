#include<bits/stdc++.h>
#define pi pair<ld, ld>
#define fi first
#define se second
#define ld float
using namespace std;
const int N = 505;
const ld oo = 1e9;

int n, k;
pi a[N];
ld dp[N][N][N];

void ckmn(ld &a, ld b){
    a = min(a, b);
}

ld solve(int x){
    /// dp(i, j, t) den i, j phieu, t tnv
    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= min(i, k); j ++){
        if ( i == j )
            for (int t = 0; t <= min(i, x); t ++)
                dp[i][j][t] = oo;
        else dp[i][j][x] = oo;
    }

    dp[0][0][0] = 0.0;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= min(i, k); j ++){
        if ( i == j ){
            for (int t = 0; t <= min(i, x); t ++){
                ckmn(dp[i+1][j][t], dp[i][j][t]);
                ckmn(dp[i+1][j+1][t], dp[i][j][t] + a[i+1].se/(x+1));
                ckmn(dp[i+1][j+1][t+1], dp[i][j][t] + a[i+1].fi/(t+1));
            }
        }
        else{
            ckmn(dp[i+1][j][x], dp[i][j][x]);
            ckmn(dp[i+1][j+1][x], dp[i][j][x] + a[i+1].se/(x+1));
        }
    }

    return dp[n][k][x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("votes.inp", "r") ){
        freopen("votes.inp", "r", stdin);
        freopen("votes.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        if ( a[i].se == -1 ) a[i].se = oo;
    }
    for (int i = 1; i <= n; i ++) swap(a[i].fi, a[i].se);
    sort(a + 1, a + 1 + n);

    ld ans = oo;
    for (int i = 0; i <= n; i ++)
        ckmn(ans, solve(i));
    cout << fixed << setprecision(15) << ans;

    return 0;
}
