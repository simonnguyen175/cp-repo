#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
using namespace std;
const int N = 205;

int n, k, cnt = 0;
int id[N][N], c[N*N], a[N][N];
pi mx[2*N];

namespace sub1{
    ll f[N*N][2], ans = 0;

    void solve(){
        for (int i = 1; i <= n; i ++)
            f[id[1][i]][0] = c[id[1][i]], f[id[1][i]][1] = mx[1].fi;

        for (int i = 1; i <= 2 * n - 2; i ++)
        for (int j = 1; j <= min(n + i - 1, 3 * n - i - 1); j ++){
            int u = id[i][j];
            int v1, v2;
            if ( i < n )
                v1 = id[i+1][j], v2 = id[i+1][j+1];
            else v1 = id[i+1][j-1], v2 = id[i+1][j];

            f[v1][0] = max(f[v1][0], f[u][0] + c[v1]);
            f[v1][1] = max({f[v1][1], f[u][1] + c[v1], f[u][0] + mx[i+1].fi});

            f[v2][0] = max(f[v2][0], f[u][0] + c[v2]);
            f[v2][1] = max({f[v2][1], f[u][1] + c[v2], f[u][0] + mx[i+1].fi});
        }

        for (int i = 1; i <= n; i ++)
            ans = max({ans, f[id[2*n-1][i]][0], f[id[2*n-1][i]][1]});

        cout << ans;
    }
}

namespace sub2{
    ll f[N][N][N][2], ans = 0;

    void solve(){
        memset(f, 0, sizeof f);

        for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++){
            ll mxu = max(a[1][i], a[1][j]);
            f[1][i][j][0] = a[1][i] + a[1][j];
            f[1][i][j][1] = mxu + mx[1].fi;
            if ( mxu == mx[1].fi ) f[1][i][j][1] = mxu + mx[1].se;
        }

        for (int i = 1; i <= 2 * n - 2; i ++)
        for (int j = 1; j <= min(n + i - 1, 3 * n - i - 1); j ++)
        for (int k = j + 1; k <= min(n + i - 1, 3 * n - i - 1); k ++){
            if ( i < n ){
                for (int t1 = 0; t1 <= 1; t1 ++)
                for (int t2 = 0; t2 <= 1; t2 ++){
                    f[i+1][j+t1][k+t2][0] = max(f[i+1][j+t1][k+t2][0], f[i][j][k][0] + a[i+1][j+t1] + a[i+1][k+t2]);
                    f[i+1][j+t1][k+t2][1] = max(f[i+1][j+t1][k+t2][1], f[i][j][k][1] + a[i+1][j+t1] + a[i+1][k+t2]);
                    ll mxu = max(a[i+1][j+t1], a[i+1][k+t2]);
                    if ( mxu < mx[i+1].fi ) f[i+1][j+t1][k+t2][1] = max(f[i+1][j+t1][k+t2][1], f[i][j][k][0] + mxu + mx[i+1].fi);
                    if ( mxu == mx[i+1].fi ) f[i+1][j+t1][k+t2][1] = max(f[i+1][j+t1][k+t2][1], f[i][j][k][0] + mxu + mx[i+1].se);
                }
            }
            else{
                for (int t1 = -1; t1 <= 0; t1 ++)
                for (int t2 = -1; t2 <= 0; t2 ++){
                    f[i+1][j+t1][k+t2][0] = max(f[i+1][j+t1][k+t2][0], f[i][j][k][0] + a[i+1][j+t1] + a[i+1][k+t2]);
                    f[i+1][j+t1][k+t2][1] = max(f[i+1][j+t1][k+t2][1], f[i][j][k][1] + a[i+1][j+t1] + a[i+1][k+t2]);
                    ll mxu = max(a[i+1][j+t1], a[i+1][k+t2]);
                    if ( mxu < mx[i+1].fi ) f[i+1][j+t1][k+t2][1] = max(f[i+1][j+t1][k+t2][1], f[i][j][k][0] + mxu + mx[i+1].fi);
                    if ( mxu == mx[i+1].fi ) f[i+1][j+t1][k+t2][1] = max(f[i+1][j+t1][k+t2][1], f[i][j][k][0] + mxu + mx[i+1].se);
                }
            }
        }

        for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            ans = max({ans, f[2*n-1][i][j][0], f[2*n-1][i][j][1]});

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= 2 * n - 1; i ++)
    for (int j = 1; j <= min(n + i - 1, 3 * n - i - 1); j ++){
        ll x; cin >> x; a[i][j] = x;
        if ( mx[i].fi < x ) mx[i].se = mx[i].fi, mx[i].fi = x;
        else if ( mx[i].se < x ) mx[i].se = x;
        id[i][j] = ++ cnt;
        c[cnt] = x;
    }

    if ( k == 1 ) sub1::solve();
    else sub2::solve();

    return 0;
}
