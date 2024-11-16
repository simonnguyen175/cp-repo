#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 5e3 + 5;

int n;
pi a[N];
int f[N];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("crect.inp", "r", stdin);
    freopen("crect.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        a[i].fi = abs(a[i].fi);
        a[i].se = abs(a[i].se);
    }
    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i ++) f[i] = LLONG_MAX;

    f[0] = 0;
    for (int i = 1; i <= n; i ++){
        int mxy = 0;
        for (int j = i; j >= 1; j --){
            mxy = max(mxy, a[j].se);
            f[i] = min(f[i], f[j-1] + mxy * a[i].fi);
        }
    }

    cout << 4 * f[n] << '\n';

    return 0;
}
