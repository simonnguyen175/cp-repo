#include<bits/stdc++.h>
#define simon "convex"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define pb push_back
using namespace std;

struct Point{
    ld x, y;
    Point() { x = y = 0; }
    Point(ld x, ld y) : x(x), y(y) {}

    Point operator + (const Point& a) { return Point(x + a.x, y + a.y); }
    Point operator - (const Point& a) { return Point(x - a.x, y - a.y); }

    ld operator % ( const Point& a ) const { return x*a.y - y*a.x; }
};

int n;
Point pivot;

ld ccw(Point a, Point b, Point c){
    ld t = (b-a)%(c-b);
    if ( t == 0 ) return 0;
    if ( t < 0 ) return 1;
    return -1;
}

ld sqrdis(Point u, Point v){
    return (u.x-v.x) * (u.x-v.x) + (u.y-v.y)*(u.y-v.y);
}

bool cmp1(Point u, Point v){
    if ( u.y == v.y ) return u.x < v.x;
    return u.y < v.y;
}

bool cmp2(Point u, Point v){
    ld o = ccw(pivot, u, v);
    if ( o == 0 ) return sqrdis(pivot, u) < sqrdis(pivot, v);
    return ( o == -1 );
}

vector<Point> convexhull(vector<Point> &a){
    vector<Point> hull;
    sort(a.begin(), a.end(), cmp1);

    for (int i = 0; i < a.size(); i ++){
        hull.pb(a[i]);
        while ( i + 1 < a.size() && a[i].x == a[i+1].x && a[i].y == a[i+1].y )
            i ++;
    }

    pivot = hull[0];
    sort(hull.begin() + 1, hull.end(), cmp2);

    int m = 0;
    for (int i = 0; i < hull.size(); i ++){
        while ( m >= 2 && ccw(hull[m-2], hull[m-1], hull[i]) >= 0 ) m --;
        hull[m ++] = hull[i];
    }

    hull.resize(m);
    return hull;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;

    vector<Point> a;
    for (int i = 1; i <= n; i ++){
        ld x, y; cin >> x >> y;
        a.push_back({x, y});
    }

    vector<Point> hull = convexhull(a);

    //cout << hull.size() << '\n';

    ld s = 0;
    for (int i = 0; i < hull.size(); i ++)
        if ( i < hull.size() - 1 )
            s += hull[i]%hull[i+1];
        else s += hull[i]%hull[0];

    s = abs(s * 1.0) / 2;

    ld cnt = 0;
    for (int i = 0; i < hull.size(); i ++){
        if ( i < hull.size() - 1 )
            cnt += __gcd((ll) abs(hull[i+1].x-hull[i].x), (ll) abs(hull[i+1].y-hull[i].y));
        else cnt += __gcd((ll) abs(hull[i].x-hull[0].x), (ll) abs(hull[i].y-hull[0].y));
    }

    cout << (long long) ( s + 1 - cnt/2 );

    return 0;
}
