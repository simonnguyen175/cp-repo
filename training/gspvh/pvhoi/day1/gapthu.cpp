#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
ll s[N], p[N], l[N], r[N];

namespace sub2{
    ll need, t;

    ll get(ll turn){
        ll d = l[1], c = l[1] + turn - 1;
        if ( turn <= need )
            return (d + c) * turn / 2 - p[0] * turn;

        return (d + c) * turn / 2 - need * p[0] - (turn - need) * p[1];
    }

    void solve(){
        need = ( s[1] % p[0] == 0 ? s[1] / p[0] : s[1] / p[0] + 1 );

        while ( q -- ){
            cin >> t;
            ll lo = 1, hi = r[1] - l[1] + 1, res = -1;

            while ( lo <= hi ){
                ll mid = (lo + hi) / 2;
                if ( get(mid) >= t ) res = mid, hi = mid - 1;
                else lo = mid + 1;
            }

            cout << res << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("gapthu.inp", "r", stdin);
    freopen("gapthu.out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++) cin >> s[i];

    for (int i = 0; i <= n; i ++) cin >> p[i];

    for (int i = 1; i <= m; i ++)
        cin >> l[i] >> r[i];

    if ( n == 1 && m == 1 ) { sub2::solve(); return 0; }

    return 0;
}
