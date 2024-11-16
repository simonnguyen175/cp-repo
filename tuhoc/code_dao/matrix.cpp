#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e2 + 5;
const int oo = 1e15;

int m, n;
ll s[N][N], a[N], f[N];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            int x; cin >> x;
            s[j][i] = s[j][i-1] + x;
        }

    ll ans = -oo;
    for (int u = 1; u <= m; u ++)
    for (int d = u; d <= m; d ++){
        for (int i = 1; i <= n; i ++)
            a[i] = s[i][d] - s[i][u-1];
        f[0] = 0;
        ll s = 0, tmp = -oo;
        for (int i = 1; i <= n; i ++){
            s += a[i];
            tmp = max(tmp, s - f[i-1]);
            f[i] = min(s, f[i-1]);
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
