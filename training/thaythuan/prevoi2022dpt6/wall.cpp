#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;

int n, k;
int a[N], dp[N][N], mx[N][N];
map<int, int> d;

void ckmn(int &a, int b){
    a = min(a, b);
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n; j ++) d[a[j]] = 0;
        for (int j = i; j <= n; j ++){
            d[a[j]] ++;
            mx[i][j] = max(mx[i][j-1], d[a[j]]);
        }
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= k; j ++)
        dp[i][j] = n + 1;

    for (int i = 1; i <= n; i ++){
        dp[i][0] = i - mx[1][i];
        for (int k = 1; k < i; k ++)
        for (int j = 1; j < i; j ++)
            ckmn(dp[i][k], dp[j][k-1] + i - j - mx[j+1][i]);
    }

    int ans = n + 1;
    for (int i = 0; i <= k; i ++)
        ckmn(ans, dp[n][i]);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
