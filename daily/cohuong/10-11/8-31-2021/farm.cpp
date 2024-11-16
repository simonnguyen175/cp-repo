#include<bits/stdc++.h>
#define simon "farm"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, x[N], c[N], minc[N], dp[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> x[i];

    sort(x + 1, x + 1 + n);

    for (int i = 1; i <= m; i ++)
        cin >> c[i];

    minc[m] = c[m];
    for (int i = m - 1; i >= 1; i --)
        minc[i] = min(c[i], minc[i+1]);

    for (int i = 1; i <= n; i ++){
        dp[i] = min(dp[i-1] + c[1], minc[x[i]]);
        for (int j = 0; j < i; j ++)
            dp[i] = min(dp[i], dp[j] + minc[x[i]-x[j+1]+1]);
    }

    cout << dp[n];

    return 0;
}
