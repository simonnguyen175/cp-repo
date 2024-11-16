#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 105;
const int base = 100;
const ll oo = 1e15;

int n, l, r, k, na, nb;
pair<ll, int> a[N], b[N];
ll f[2][N][10005];

void solve(){
    cin >> n >> l >> r >> k;
    na = 0; nb = 0;
    ll s = 0;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        s += x;
        if ( i >= l && i <= r ) b[++nb] = {x, i};
        else a[++na] = {x, i};
    }

    if ( r - l + 1 == n ) {cout << s; return;}

    for (int i = 0; i <= 1; i ++)
    for (int j = 1; j <= nb; j ++)
    for (int t = 0; t <= k; t ++)
        f[i][j][t] = oo;

    f[0][0][0] = 0;


    for (int i = 1; i <= na; i ++)
    for (int j = 1; j <= nb; j ++)
    for (int t = 0; t <= k; t ++){
        // exchange i j
        if ( t-abs(a[i].se-b[j].se) >= 0 )
        f[i%2][j][t] = min(f[i%2][j][t], f[1-i%2][j-1][t-abs(a[i].se-b[j].se)] + a[i].fi);

        // not exchange i j
        f[i%2][j][t] = min({f[i%2][j][t], f[1-i%2][j][t], f[i%2][j-1][t] + b[j].fi});
    }

    ll ans = oo;
    for (int i = 1; i <= na; i ++)
    for (int t = 0; t <= k; t ++)
        ans = min(ans, f[i%2][nb][t]);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    solve();
    return 0;
}
