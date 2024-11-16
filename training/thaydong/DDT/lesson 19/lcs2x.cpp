#include<bits/stdc++.h>
using namespace std;
const int N = 2e3;

int m, n, t;
int a[N], b[N], f[N][2];

void solve(){
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];

    for (int i = 1; i <= n; i ++)
        f[i][0] = f[i][1] = 0;

    for (int i = 1; i <= m; i ++){
        int curLen = 0;
        for (int j = 1; j <= n; j ++){
            if ( a[i] == b[j] && curLen + 1 > f[j] ) f[j] = curLen + 1;
            if ( a[i] >= 2 * b[j] && f[j] > curLen ) curLen = f[j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[i]);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> t;
    while ( t -- )
        solve();

    return 0;
}
