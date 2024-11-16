#include<bits/stdc++.h>
#define simon "wire"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, a[N];
ll f[N], ans;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    // DP

    for (int i=m+1; i<=2*m; i++)
        f[i] = max(f[i], (ll) a[i] + a[i-m]);

    for (int i=2*m+1; i<=n; i++)
        f[i] = max(f[i-m], f[i-2*m] + (ll) a[i] + a[i-m]);

    for (int i=n; i>=n-m+1; i--)
        ans += f[i];

    cout << ans;
    return 0;
}
