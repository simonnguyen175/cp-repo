#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
const ll oo = 1e15;

int n, m;
ll a[N];
map<int, ll> dp[N];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            dp[i][j] = oo;

    for (int i = 2; i <= m; i ++)
        for (int j = 1; j < i; j ++)
            dp[i][j] = a[i] + a[j];

    for (int i = m + 1; i <= n; i ++)
        for (int j = i - 1; j >= i - m + 1; j --){
            dp[i][j] = oo;
            for (int k = j - 1; k >= max(j - m + 1, 1); k --){
                if ( i - k > m ) break;
                dp[i][j] = min(dp[i][j], dp[j][k] + a[i]);
            }
        }

    ll res = oo;
    for (int i = n; i >= n - m + 1; i --)
    for (int j = i - 1; j >= n - m + 1; j --)
        res = min(res, dp[i][j]);

    cout << res << '\n';

    return 0;
}
