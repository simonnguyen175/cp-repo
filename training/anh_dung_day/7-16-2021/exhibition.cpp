#include<bits/stdc++.h>
#define simon "exhibition"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define se second
#define fi first
using namespace std;
const int N = 1e5+5;

int n;
pair<ll, ll> a[N];
ll s[N], f[N], ans;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n);

    for (int i=1; i<=n; i++)
        s[i] = s[i-1] + a[i].se;

    f[0] = LLONG_MAX;
    for (int i = 1; i <= n; i ++)
        f[i] = min(f[i-1], s[i-1] - a[i].fi);

    ans = s[1];
    for (int i = 2; i <= n; i++)
        ans = max({ans, s[i] - a[i].fi - f[i-1], a[i].se});

    cout << ans;

    return 0;
}
