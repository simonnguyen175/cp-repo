#include<bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define fi first
#define se second
#define pb push_back
#define ld long double
using namespace std;
const int N = 2e3 + 5;
const ld PI = 3.141592653589793238;
const ld eps = 1e-9;

int n;
struct Point{
    ll x, y;
    Point() { x = y = 0; };
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator - (const Point &a) { return Point(x - a.x, y - a.y); }
    ll operator * (const Point &a) { return x * a.x + y * a.y; }

    ld norm() { return x*x + y*y; }
} a[N];
map<pair<pair<ll, ll>, ll>, vector<ld>> mp;

ld abs(Point u){
    return (ld) sqrt(u.norm());
}

ld angle(Point u, Point v){
    ld cosTheta = u * v / abs(u) / abs(v);
    return acos(max((ld)-1.0, min((ld)1.0, cosTheta)));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y;

    sort(a + 1, a + 1 + n, [&](Point b, Point c){
        return b.y < c.y;
    });

//    for (int i = 1; i <= n; i ++)
//        cout << a[i].x << ' ' << a[i].y << '\n';

    for (int i = 1; i <= n; i ++)
    for (int j = i + 1; j <= n; j ++){
        Point tmp = a[j] - a[i];
        pair<pair<ll, ll>, ll> t;
        t = {{a[j].x + a[i].x, a[j].y + a[i].y}, tmp.norm()};
//        cout << i << ' ' << j << " -> " << tmp.x << ' ' << tmp.y << '\n';
//        cout << " -> " << t.fi.fi << ' ' << t.fi.se << ' ' << t.se << ' ' << angle(tmp, Point(1, 0)) * 180 * 1.0 / PI << '\n';
        mp[t].pb(angle(tmp, Point(1, 0)) * 180 * 1.0 / PI);
    }

    ll ans = 0;
    vector<ld> cont;
    for (auto it : mp){
        cont = it.se;
        sort(cont.begin(), cont.end());
        int ptr = 0;

//        cout << it.fi.fi.fi << ' ' << it.fi.fi.se << ' ' << it.fi.se << ' ' << it.se.size() << " : \n";

        for (int i = 1; i < cont.size(); i ++){
            while ( ptr < i - 1 && cont[i] - cont[ptr] - eps > 90.0 ) ptr ++;
            ld alp = cont[i] - cont[ptr];
            alp = alp * PI / 180;
            ld tmp = it.fi.se * sin(alp) / 2;
            ans = max(ans, (ll)(tmp + 0.5));

            if ( ptr >= 1 ){
                ld alp = cont[i] - cont[ptr-1];
                alp = alp * PI / 180;
                ld tmp = it.fi.se * sin(alp) / 2;
                ans = max(ans, (ll)(tmp + 0.5));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
