#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define int long long
#define double long double
using namespace std;
const int N = 1e5 + 5;

int W, H, n, m, q;

struct Point{
    int x, y;
    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}
    ll operator % (const Point& a) const { return 1ll * x*a.y - 1ll * y*a.x; }
};
Point p[N][10];

namespace sub2{
    vector<int> adj[N];
    double dt[N];

    double stg(Point a, Point b, Point c){
        double res = 0.0;
        res += a % b + b % c + c % a;
        res = abs(res) * 1.0 / 2;
        return res;
    }

    bool inside(Point a, int id){
        double tmp = 0;
        for (int i = 1; i <= m; i ++)
            tmp += stg(a, p[id][i], p[id][i+1]);
        return (tmp == dt[id]);
    }

    void solve(){
        for (int i = 1; i <= n; i ++){
            for (int j = 1; j <= m; j ++)
                cin >> p[i][j].x >> p[i][j].y;
        }

        for (int i = 1; i <= n; i ++){
            dt[i] = 0.0;
            p[i][m+1] = p[i][1];
            for (int j = 1; j <= m; j ++)
                dt[i] += p[i][j] % p[i][j+1];
            dt[i] = abs(dt[i]) * 1.0 / 2;
        }

        dt[0] = 1ll * W * H;

        for (int i = 1; i <= n; i ++){
            int par = 0;
            for (int j = 1; j <= n; j ++) if ( i != j ){
                bool ck = 1;
                for (int k = 1; k <= m; k ++)
                    ck &= inside(p[i][k], j);

                if ( ck ){
                    if ( !par ) par = j;
                    else if ( dt[par] > dt[j] ) par = j;
                }
            }

            adj[par].pb(i);
        }



        while ( q -- ){
            Point u;
            cin >> u.x >> u.y;

            int par = 0;
            for (int i = 1; i <= n; i ++) if ( inside(u, i) ){
                if ( !par ) par = i;
                else if ( dt[par] > dt[i] ) par = i;
            }

            double ans = dt[par];
            for (int v : adj[par])
                ans -= dt[v];

            cout << fixed << setprecision(1) << ans << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);

    cin >> W >> H >> n >> m >> q;

    if ( n <= 2000 && q <= 2000 )
        sub2::solve();

    return 0;
}
