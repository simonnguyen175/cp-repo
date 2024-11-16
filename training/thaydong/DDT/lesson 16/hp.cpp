#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
ll sall = 0;
ll t[N], h[N], s[N], pre, f[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> t[i] >> h[i];
        sall += h[i];
        s[t[i]] += h[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i ++){
        ans = ( ans + ( sall - s[t[i]] - pre + f[t[i]] ) * h[i] % MOD ) % MOD;
        pre += h[i];
        f[t[i]] += h[i];
    }

    cout << ans;

    return 0;
}
