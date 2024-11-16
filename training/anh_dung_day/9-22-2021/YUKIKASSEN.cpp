#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define EPS 1e-9
using namespace std;

inline int cmp(double a, double b) {
    return (a < b - EPS) ? -1 : ((a > b + EPS) ? 1 : 0);
}

struct Point{
    int x, y;
    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}

    Point operator + (const Point& a) { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) { return Point(x-a.x, y-a.y); }

    int operator % (const Point& a) const { return x*a.y - y*a.x; }
    int operator * (const Point& a) const { return x*a.x + y*a.y; }
    int norm() { return x*x + y*y; }
};

int n;
vector<Point> a, b;
Point pivot;
vector<Point> hull[2];

int sqrdis(Point u, Point v){
    return (u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y);
}

double angle(Point a, Point o, Point b){
    a = a - o; b = b - o;
    return acos((a*b) / sqrt(a.norm()) / sqrt(b.norm()));
}

int ccw(Point a, Point b, Point c){
    int t = (b-a)%(c-b);
    if ( t == 0 ) return 0;
    if ( t < 0 ) return 1;
    return -1;
}

bool cmp1(Point a, Point b){
    if ( a.y == b.y ) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(Point u, Point v){
    int o = ccw(pivot, u, v);
    if ( o == 0 ) return sqrdis(pivot, u) < sqrdis(pivot, v);
    return ( o == -1 );
}

vector<Point> convexhull(vector<Point>& a){
    vector<Point> hull;
    sort(a.begin(), a.end(), cmp1);

    for (int i = 0; i < a.size(); i ++){
        hull.pb(a[i]);
        while ( i + 1 < a.size() && a[i].x == a[i+1].x && a[i].y == a[i+1].y )
            i ++;
    }

    pivot = hull[0];
    sort(hull.begin()+1, hull.end(), cmp2);

    int m = 0;
    for (int i = 0; i < hull.size(); i ++){
        while ( m >= 2 && ccw(hull[m-2], hull[m-1], hull[i]) >= 0 ) m --;
        hull[m++] = hull[i];
    }

    hull.resize(m);
    return hull;
}

double stg(Point a, Point b, Point c){
    return abs( a % b + b % c + c % a ) * 1.0 / 2;
}

bool inside(Point u, int x){
    //cout << u.x << ' ' << u.y << ' ' << x << '\n';

    double g1 = angle(hull[x][hull[x].size()-1], hull[x][0], hull[x][1]);
    double g2 = angle(u, hull[x][0], hull[x][1]);
    double g3 = angle(u, hull[x][0], hull[x][hull[x].size()-1]);

    if ( cmp(g2 + g3, g1) != 0 ) return 0;

    int lo = 1, hi = hull[x].size()-1, res = 0;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        double g = angle(hull[x][1], hull[x][0], hull[x][mid]);
        if ( cmp(g, g2) >= 0 ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    //cout << res << '\n';

    double S = stg(hull[x][0], hull[x][res], hull[x][res-1]);
    double s1 = stg(hull[x][0], hull[x][res], u);
    double s2 = stg(hull[x][0], hull[x][res-1], u);
    double s3 = stg(hull[x][res], hull[x][res-1], u);

    //cout << s1 + s2 + s3 <<  ' ' << S << '\n';

    return ( cmp(s1 + s2 + s3, S) == 0 );
}

int solve(int x){
    int u = x, v = 1-x;
    int res = 0;
    for (auto it : hull[v])
        if ( inside(it, x) ) res ++;
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("YUKIKASSEN.inp", "r") ){
        freopen("YUKIKASSEN.inp", "r", stdin);
        freopen("YUKIKASSEN.out", "w", stdout);
    }

    cin >> n;

    for (int i = 1; i <= n; i ++){
        int x, y; cin >> x >> y;
        a.pb({x, y});
    }

    for (int i = 1; i <= n; i ++){
        int x, y; cin >> x >> y;
        b.pb({x, y});
    }

    hull[0] = convexhull(a);
    hull[1] = convexhull(b);

    /*
    cout << "print convexhull A" << '\n';
    for (auto x : hull[0]) cout << x.x << ' ' << x.y << '\n';
    cout << "print convexhull B" << '\n';
    for (auto x : hull[1]) cout << x.x << ' ' << x.y << '\n';
    cout << '\n';
    */

    cout << solve(0) << ' ' << solve(1);

    return 0;
}
