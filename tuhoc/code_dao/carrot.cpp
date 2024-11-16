#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int nmax = 7000;

ll n, a[nmax], s[nmax], dp[nmax], last[nmax];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
    freopen("CARROT.inp", "r", stdin);
    freopen("CARROT.out", "w", stdout);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        last[i] = LLONG_MAX;
    }

    dp[1] = 1; last[1] = a[1];
    for (int i=2; i<=n; i++)
        for (int j=1; j<i; j++)
            if ( s[i] - s[j] >= last[j] && dp[i] <= dp[j] + 1 ){
                dp[i] = dp[j] + 1;
                last[i] = min(s[i] - s[j], last[i]);
            }
    /*
    for (int i=1; i<=n; i++)
        cout << dp[i] << ' ' << last[i] << '\n';
    */

    cout << dp[n];

    return 0;
}
