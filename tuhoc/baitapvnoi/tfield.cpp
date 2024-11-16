#include<bits/stdc++.h>
#define ll long long
#define pdi pair<double, int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;

struct Point{
    ll x, y;
    Point(){ x = y = 0; }
    Point(ll x, ll y) : x(x), y(y) {}

    ll operator % (const Point& a)  const { return x*a.y - y*a.x; }
};

int m, n, k;
Point p[N];
pdi a[N];
double s[N];
int diff[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> k;
    for (int i = 1; i <= m; i ++){
        cin >> n >> a[i].se;
        for (int j = 1; j <= n; j ++)
            cin >> p[j].x >> p[j].y;
        a[i].fi = 0;
        for (int j = 1; j < n; j ++)
            a[i].fi += p[j] % p[j+1];
        a[i].fi += p[n] % p[1];
        a[i].fi /= 2;
    }

    sort(a + 1, a + 1 + m);

    for (int i = m; i >= 1; i --)
        a[i].fi -= a[i-1].fi;

    s[0] = 0;
    for (int i = 1; i <= m; i ++)
        s[i] = s[i-1] + a[i].fi;

    double ans = 0.0;

    for (int c = 1; c <= m; c ++){
//        cout << "color " << c << " : \n";
        for (int i = 1; i <= m; i ++)
            if ( a[i].se != c ) diff[i] = 1;
            else diff[i] = 0;

        diff[0] = 0;
        for (int i = 1; i <= m; i ++)
            diff[i] += diff[i-1];

//        for (int i = 1; i <= m; i ++) cout << diff[i] << ' ';
//        cout << '\n';

        for (int i = 1; i <= m; i ++){
            int lo = 1, hi = i, res;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( diff[i] - diff[mid-1] <= k ){
                    res = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
//            cout << i << ' ' << res << '\n';
            ans = max(ans, s[i] - s[res-1]);
        }
    }

    cout << fixed << setprecision(1) << ans;

    return 0;
}
