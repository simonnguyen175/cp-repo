#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, q;
pi a[N], b[N];
ll f[N], sum[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + 1 + n, [&](pi x, pi y){
        return x.se < y.se;
    });
    a[n+1].se = a[n].se + 1;
    ll mxl = 0;
    for (int i = 1; i <= n; i ++){
        mxl = max(mxl, a[i].fi);
        f[i] = mxl;
        sum[i] = sum[i-1] + (a[i+1].se - a[i].se) * mxl;
    }

    cin >> q;
    while ( q -- ){
        int x, y;
        cin >> x >> y;

        int lo = 1, hi = n, l = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( f[mid] >= x ) l = mid, hi = mid - 1;
            else lo = mid + 1;
        }

        lo = 1, hi = n;
        int r = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( a[mid].se <= y ) r = mid, lo = mid + 1;
            else hi = mid - 1;
        }

        if ( l == -1 || r == -1 || l > r ) { cout << 0 << '\n'; continue; }

//        cout << l << ' ' << r << '\n';

        cout << sum[r-1] - sum[l-1]
        + (y - a[r].se + 1) * f[r] - (y - a[l].se + 1) * (x - 1) << '\n';
    }

    return 0;
}
