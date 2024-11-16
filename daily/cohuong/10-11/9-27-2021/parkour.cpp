#include<bits/stdc++.h>
#define ld double
using namespace std;
const int N = 2e5 + 5;
const int oo = 1e6 + 5;
const ld eps = 1e-8;

int t, n, m;
int h[N];
ld mxu[N], mxd[N], low[N], up[N];

void init(){
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) cin >> h[i];

    for (int i = 1; i <= n; i ++)
        mxd[i] = mxu[i] = 1.0*oo;

    for (int i = 1; i <= m; i ++){
        int a, b, u, d;
        cin >> a >> b >> u >> d;
        if ( a > b ) swap(u, d), swap(a, b);
        for (int j = a + 1; j <= b; j ++){
            mxd[j] = min(mxd[j], (ld) d);
            mxu[j] = min(mxu[j], (ld) u);
        }
    }
}

bool meet(ld l, ld r, ld u, ld v){
    if ( r < u || l > v ) return false;
    return true;
}

bool check(ld t){
    low[1] = h[1]*1.0 - t; up[1] = h[1]*1.0 + t;

    for (int i = 2; i <= n; i ++){
        ld nl = h[i]*1.0 - t, nu = h[i]*1.0 + t;
        ld curl = low[i-1] - mxd[i], curu = up[i-1] + mxu[i];
        if ( !meet(nl, nu, curl, curu) ) return false;
        low[i] = max(nl, curl); up[i] = min(nu, curu);
    }

    return true;
}

void solve(){
    ld lo = 0.0, hi = 1000000.0, res;

    while ( lo <= hi ){
        ld mid = ( lo + hi ) / 2;
        if ( check(mid) ){
            res = mid;
            hi = mid - eps;
        }
        else lo = mid + eps;
    }

    cout << fixed << setprecision(6) << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("parkour.in", "r") ){
        freopen("parkour.in", "r", stdin);
        freopen("parkour.out", "w", stdout);
    }

    cin >> t;

    while ( t -- ){
        init();
        solve();
    }

    return 0;
}

