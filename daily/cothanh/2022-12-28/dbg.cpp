#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 1e3 + 5;

int n, A, B, D;
pi a[N];
ll dp[N][N*10];

void ckmn(ll &a, ll b){
    if ( a == -1 ) a = b;
    else a = min(a, b);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("dbg.inp", "r", stdin);
    freopen("dbg.out", "w", stdout);

    cin >> n >> A >> B >> D;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    sort(a + 1, a + 1 + n, [&](pi x, pi y){
        return x.se * y.fi >= y.se * x.fi;
    });

    memset(dp, -1, sizeof dp);

    /// dp(i, j) xet den mon i, ben phai D dai j
    for (int i = max(A, D - a[1].fi); i <= D; i ++)
        if ( i + a[1].fi <= B )
            dp[1][i+a[1].fi-D] = (i + a[1].fi - D) * a[1].se;

//    for (int i = 1; i <= n; i ++)
//        cout << a[i].fi << ' ' << a[i].se << '\n';

    int s = a[1].fi;
    ll ans = -1;
    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= min(B - D, s); j ++) if ( dp[i][j] != -1 ){
            if ( i == n ){
                ckmn(ans, dp[i][j]);
                continue;
            }

//            cout << i << ' ' << j << ' ' << dp[i][j] << '\n';

            if ( j + a[i+1].fi <= B - D ){
                ckmn(dp[i+1][j+a[i+1].fi], dp[i][j] + 1ll * (j + a[i+1].fi) * a[i+1].se);
//                cout << " -> " << i + 1 << ' ' << j + a[i+1].fi << ' ' << dp[i+1][j+a[i+1].fi] << '\n';
            }

            int lef = s - j;

            if ( D - A >= lef + a[i+1].fi ){
                ckmn(dp[i+1][j], dp[i][j] + 1ll * lef * a[i+1].se);
//                cout << " -> " << i + 1 << ' ' << j << ' ' << dp[i+1][j] << '\n';
            }
        }

        s += a[i+1].fi;
    }

    cout << ans;

    return 0;
}
