#include<bits/stdc++.h>
#define simon "las2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e4 + 5;

int n, a[N], dp[N][N], ans;
unordered_map<int, int> d;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++){
        for (int  j = 1; j < i; j ++){
            dp[i][j] = max(dp[j][d[2 * a[j] - a[i]]] + 1, dp[i][j]);
            d[a[j]] = j;
            ans = max(ans, dp[i][j] + 1);
        }
        d[a[i]] = i;
    }

    cout << ans;
    return 0;
}
