#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e15;

int n, k;
ll h[N], dp[N][N][2];

void ckmn(ll &a, ll b){
    a = min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> h[i];
    sort(h + 1, h + 1 + n);

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= k; j ++)
    for (int t = 0; t <= 1; t ++)
        dp[i][j][t] = oo;
    dp[1][0][0] = 0;

    for (int i = 2; i <= n; i ++)
    for (int j = 0; j <= i/2; j ++){
        ckmn(dp[i][j][1], dp[i-1][j-1][0] + h[i] - h[i-1]);
        ckmn(dp[i][j][0], dp[i-1][j][1]);
        ckmn(dp[i][j][0], dp[i-1][j][0]);
    }

    cout << min(dp[n][k][0], dp[n][k][1]);

    return 0;
}
