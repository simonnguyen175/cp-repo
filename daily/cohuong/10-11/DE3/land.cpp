#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e18;

int m, n, k;
ll t;
ll s[N][N], a[N][N], b[N][N];

ll get(int x, int y, int u, int v){
    return ( s[u][v] - s[x-1][v] - s[u][y-1] + s[x-1][y-1] );
}

namespace sub1{
    void solve(){
        int ans = 0;

        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            int lo = 1, hi = min(i, j), res = 0;

            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( get(i-mid+1, j-mid+1, i, j) <= t ) res = mid, lo = mid + 1;
                else hi = mid - 1;
            }

            ans = max(ans, res * res);
        }

        cout << ans << '\n';
    }
}

namespace sub2{
    ll mn[N];
    int mx[N];
    int lim;
    vector<pi> areaD[N], areaU[N];
    int ans = 0;

    void xuli(){
        for (int i = 1; i <= m; i ++) areaD[i].clear(), areaU[i].clear();

        lim = min(m, n);

        for (int i = 1; i <= lim; i ++) mn[i] = oo;

        for (int i = 1; i <= m; i ++){
            for (int j = 1; j <= n; j ++){
                for (int len = 1; len <= min(i, j); len ++){
                    if ( get(i-len+1, j-len+1, i, j) <= t )
                        mn[len] = min(mn[len], get(i-len+1, j-len+1, i, j));
                }
            }

            for (int len = 1; len <= lim; len ++)
                areaD[i].pb({mn[len], len});
        }


//        for (int i = 1; i <= m; i ++){
//            cout << i << " : \n";
//            for (auto it : areaD[4]) cout << it.fi << ' ' << it.se << " , "; cout << '\n';
////        }

        for (int j = 1; j <= lim; j ++)
            mn[j] = oo;

        for (int i = m; i >= 1; i --){
            for (int j = 1; j <= n; j ++)
            for (int len = 1; len <= min(m-i+1, j); len ++)
                if ( get(i, j-len+1, i+len-1, j) <= t )
                    mn[len] = min(mn[len], get(i, j-len+1, i+len-1, j));

            for (int len = 1; len <= lim; len ++)
                areaU[i].pb({mn[len], len});
        }

//        for (int i = 1; i <= m; i ++){
//            cout << i << " : \n";
//            for (auto it : areaU[5]) cout << it.fi << ' ' << it.se << " , "; cout << '\n';
//        }

        for (int i = 1; i < m; i ++){
            sort(areaD[i].begin(), areaD[i].end());
            sort(areaU[i+1].begin(), areaU[i+1].end());

            mx[0] = areaU[i+1][0].se;
            for (int i = 1; i < lim; i ++) mx[i] = max(mx[i-1], areaU[i+1][i].se);

            for (auto it : areaD[i]){
                int lo = 0, hi = lim - 1, res = -1;
                while ( lo <= hi ){
                    int mid = lo + hi >> 1;
                    if ( areaU[i+1][mid].fi + it.fi <= t ) res = mid, lo = mid + 1;
                    else hi = mid - 1;
                }

                if ( res == -1 ) continue;

                ans = max(ans, it.se*it.se + mx[res]*mx[res]);
            }
        }
    }

    void solve(){
        xuli();

        swap(m, n);

        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            a[i][j] = b[n-j+1][i];

//        for (int i = 1; i <= m; i ++){
//            for (int j = 1; j <= n; j ++)
//                cout << a[i][j] << ' ';
//            cout << '\n';
//        }

        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];

        xuli();

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("land.inp", "r") ){
        freopen("land.inp", "r", stdin);
        freopen("land.out", "w", stdout);
    }

    cin >> m >> n >> k >> t;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j], b[i][j] = a[i][j];

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];

    if ( k == 1 ) sub1::solve();
    else sub2::solve();

    return 0;
}
