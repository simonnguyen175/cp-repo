#include<bits/stdc++.h>
using namespace std;

int n, b;
pair<int, int> bonus[25];
int s[25][25], dp[10000005];

int BIT(int x, int k){
    return ( x >> k ) & 1;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> b;

    for (int i = 1; i <= b; i ++){
        int k, p, a;
        cin >> k >> p >> a;
        bonus[k].first = p; bonus[k].second = a;
    }

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> s[i][j];

    int mx = ( 1 << n ) - 1;

    for (int mask = 0; mask <= mx; mask ++){
        int nn = __builtin_popcount(mask);
        for (int i = 0; i <= n-1; i ++)
            if ( !BIT(mask, i) )
                if ( dp[mask] + s[i+1][nn+1] >= bonus[nn+1].first )
                    dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + s[i+1][nn+1] + bonus[nn+1].second);
                else
                    dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + s[i+1][nn+1]);
    }

    cout << dp[mx];

    return 0;
}
