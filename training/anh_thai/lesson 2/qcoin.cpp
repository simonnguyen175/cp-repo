#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 6e3 + 5;
const int MOD = 1e9 + 7;

int n, s, t;
int a[N], b[N];
ll dp[2][N], ans = 0;
vector<int> divset;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i ++)
        cin >> a[i] >> b[i];

    for (int i = 1; i <= sqrt(s); i ++)
        if ( s % i == 0 )
            if ( i * i == s ) divset.pb(i);
            else divset.pb(i), divset.pb(s/i);

    for (int sl : divset){
        t = s/sl;

        for (int i = 0; i <= t; i ++)
            dp[0][i] = dp[1][i] = 0;
        dp[0][0] = 1;

        t = s/sl;

        for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= t; j ++){
            dp[i%2][j] = dp[(i-1)%2][j];
            if ( a[i] >= sl && j >= b[i] )
                ( dp[i%2][j] += dp[(i-1)%2][j-b[i]] ) %= MOD;
        }

        ( ans += dp[n%2][t] ) %= MOD;
    }

    cout << ans;

    return 0;
}
