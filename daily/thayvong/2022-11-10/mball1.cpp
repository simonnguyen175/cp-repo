#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 5;

int n;
int a[N];
map<int, int> dp[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("mball1.inp", "r") ){
        freopen("mball1.inp", "r", stdin);
        freopen("mball1.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++)
    for (auto it : dp[i-1]){
        int j = it.fi, w = it.se;
        w += abs(j);
        j += 1-a[i];
        if ( dp[i].find(j) != dp[i].end() )
            dp[i][j] = min(dp[i][j], w);
        else dp[i][j] = w;
    }

    cout << dp[n][0];

    return 0;
}
