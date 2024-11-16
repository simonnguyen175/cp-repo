#include<bits/stdc++.h>
#define simon "keven"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n, k;
long long a[N], cost[N][2], dp[N][2];

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int main(){
    file();
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    memset(cost, 0, sizeof cost);

    for (int i = 1; i <= n; i ++){
        if ( a[i] % 2 == 0 ) cost[((i%k == 0) ? k : i % k)][1] ++;
        else cost[((i%k == 0) ? k : i % k)][0] ++;
    }

    dp[0][0] = 0;
    dp[0][1] = INT_MAX;

    for (int i = 1; i <= k; i ++){
        dp[i][1] = min(dp[i-1][1] + cost[i][0], dp[i-1][0] + cost[i][1]);
        dp[i][0] = min(dp[i-1][1] + cost[i][1], dp[i-1][0] + cost[i][0]);
    }

    cout << dp[k][0];

    return 0;
}
