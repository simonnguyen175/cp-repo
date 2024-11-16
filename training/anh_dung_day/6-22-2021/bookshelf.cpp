#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 25;

int n, m;
int a[N], cnt[M][N], dp[(1 << M)];

int cost(int u, int l, int r){
    return cnt[u][n] - ( cnt[u][r] - cnt[u][l-1] );
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if ( a[i] == j ) cnt[j][i] = cnt[j][i-1] + 1;
            else cnt[j][i] = cnt[j][i-1];

    int mx = ( 1 << m ) - 1;

    for (int i = 0; i <= mx; i ++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int mask = 0; mask <= mx; mask ++){
        int pos = 0;
        for (int i = 0; i <= m - 1; i ++)
            if ( ( mask >> i ) & 1 ) pos += cnt[i + 1][n];
        for (int i = 0; i <= m - 1; i ++)
            if ( !( ( mask >> i ) & 1 ) ){
                int l = pos + 1;
                int r = pos + cnt[i + 1][n];
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + cost(i + 1, l, r));
            }
    }

    cout << dp[mx];

    return 0;
}
