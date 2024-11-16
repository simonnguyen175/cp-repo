#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll oo = 1e15;

int k, n, r;
ll a[N], s[N], f[N];

void solve(){
    s[0] = 0;
    for (int i = 1; i <= n; i ++)
        s[i] = s[i-1] + a[i];

    for (int i = 1; i <= n; i ++)
        f[i] = -oo;

    ll ans = -oo;
    for (int i = 1; i <= n; i ++){
        int left = max(1, i-r), right = min(i + r, n);
        f[i] = max(f[i], s[right] - s[left-1]);
        for (int j = 1; j < i; j ++){
            int nl = max(min(j+r, n), left - 1);
            f[i] = max(f[i], f[j] + s[right] - s[nl]);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cin.tie(0);
    cin >> k;
    while ( k -- ){
        cin >> n >> r;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        solve();
    }
}
