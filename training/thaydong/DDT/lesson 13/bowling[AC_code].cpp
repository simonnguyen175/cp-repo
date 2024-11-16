#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll oo = 1e15;

int n, k, r;
ll a[3*N], s[3*N], f[3*N][2];

void solve(){
    cin >> n >> r;
    for (int i = 1; i <= n; i ++)
        cin >> a[i + r];
    for (int i = 1; i <= r; i ++) a[i] = a[i+n+r] = 0;

    s[0] = 0;
    for (int i = 1; i <= n + 2 * r; i ++)
        s[i] = s[i-1] + a[i];

    for (int i = 0; i <= n + 2 * r; i ++)
        for (int j = 0; j <= 1; j ++)
            f[i][j] = -oo;

    f[0][0] = 0;
    for (int i = 1; i <= n + 2 * r; i ++){
        f[i][0] = max(f[i-1][0], f[i-1][1]);
        f[i][1] = f[i-1][1] + a[i];
        if ( i >= 2 * r + 1 )
            f[i][1] = max(f[i][1], f[i-(2*r+1)][0] + s[i] - s[i-(2*r+1)]);
    }

    ll ans = -oo;

    for (int i = 1; i <= n + 2 * r; i ++)
        ans = max(ans, f[i][1]);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //cout << "code O(n)" << '\n';
    cin >> k;
    while ( k -- ) solve();
    return 0;
}
