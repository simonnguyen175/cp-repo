#include<bits/stdc++.h>
#define simon "homecoming"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 4e6 + 5;
const ll oo = 1e18;

int t, n, k;
ll a[N], b[N], f[N], mx[N];
ll ans;

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    for (int i = n + 1; i <= 2 * n; i ++)
        a[i] = a[i-n], b[i] = b[i-n];
    for (int i = 1; i <= 2 * n; i ++)
        b[i] += b[i-1];

    ans = 0;
    // th bat dau bang 1
    for (int i = 1; i <= n; i ++) f[i] = -oo;
    f[1] = mx[1] = a[1] - b[k] + b[0];
    ans = max(ans, f[1]);

    for (int i = 2; i <= n; i ++){
        if ( i < 1 + k )
            f[i] = f[i-1] + a[i] - b[min(n, i+k-1)] + b[min(n, i+k-2)];
        else
            f[i] = max(f[i-1] + a[i] - b[min(n, i+k-1)] + b[min(n, i+k-2)],
                        mx[i-k] + a[i] - b[min(n, i+k-1)] + b[i-1]);
        mx[i] = max(mx[i-1], f[i]);
        ans = max(ans, f[i]);
    }

    // th ko bat dau bang 1
    for (int i = 1; i <= n; i ++)
        f[i] = -oo, mx[i] = 0;

    for (int i = 2; i <= n; i ++){
        if ( i < 1 + k )
            f[i] = max(f[i-1] + a[i] - b[i+k-1] + b[i+k-2], a[i] - b[i+k-1] + b[i-1]);

        else
            f[i] = max(f[i-1] + a[i] - b[i+k-1] + b[i+k-2],
                        mx[i-k] + a[i] - b[i+k-1] + b[i-1]);
        mx[i] = max(mx[i-1], f[i]);
        ans = max(ans, f[i]);
    }

    cout << ans << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".in", "r") ){
        freopen(simon".in", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
