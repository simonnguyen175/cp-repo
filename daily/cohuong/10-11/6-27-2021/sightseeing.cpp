#include<bits/stdc++.h>
#define simon "sightseeing"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e3 + 5;

void file(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
}

int t, n;
ll t1, t2;
ll s[N], f[N], d[N], dp[N][N];

ll next(ll t, ll s, ll f, ll d){
    if ( s >= t ) return s + d;
    return t + (t - s) % f + d;
}

void solve(){
    for (int i = 1; i <= n - 1; i ++) dp[0][i] = 1e15;
    dp[0][0] = 0;

    for (int i = 1; i <= n - 1; i ++)
        for (int j = 0; j <= n - 1; j ++){
            dp[i][j] = next(dp[i-1][j], s[i], f[i], d[i]);
            if ( j ) dp[i][j]= min(dp[i][j], next(dp[i-1][j-1] + t1, s[i], f[i], d[i]));
        }

    for (int i = n - 1; i >= 0; i --){
        if ( dp[n-1][i] <= t2 ){
            cout << i << '\n';
            return;
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return;
}

int main(){
    file();
    cin >> t;
    while ( t -- ){
        cin >> n >> t1 >> t2;
        for (int i = 1; i <= n - 1; i ++)
            cin >> s[i] >> f[i] >> d[i];
        solve();
    }
    return 0;
}
