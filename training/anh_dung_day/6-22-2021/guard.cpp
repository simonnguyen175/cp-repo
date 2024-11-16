#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e12;

int n, hm;
ll h[25], m[25], c[25], dp[(1 << 25)];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> hm;
    for (int i = 1; i <= n; i ++)
        cin >> h[i] >> m[i] >> c[i];

    int mx = ( 1 << n ) - 1;

    dp[0] = oo;

    ll ans = -1;
    for (int mask = 0; mask <= mx; mask ++){
        ll con = 0, hei = 0;
        for (int i = 0; i <= n - 1; i ++)
            if ( (mask >> i) & 1 ) con += m[i+1], hei += h[i+1];
        for (int i = 0; i <= n - 1; i ++)
            if ( !((mask >> i) & 1) && c[i+1] >= con ){
                dp[mask | (1 << i)] = max({dp[mask | (1 << i)], min(dp[mask], c[i+1] - con)});
                if ( hei + h[i+1] >= hm )
                    ans = max(ans, dp[mask | (1 << i)]);
            }
    }


    if ( ans == - 1 ) cout << "Mark is too tall";
    else cout << ans;
    return 0;
}
