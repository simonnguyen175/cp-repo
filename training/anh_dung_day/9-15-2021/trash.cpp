#include<bits/stdc++.h>
#define pb push_back
using namespace std;

struct Point{
    int x, y;
    Point() { x = y = 0; }
    Point(int x, int y) : x(x), y(y) {}

    Point operator + (const Point& a) { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) { return Point(x-a.x, y-a.y); }

    int operator % (const Point& a) const { return x*a.y - y*a.x; }
};

struct Line{
    int a, b, c;

    double kc(Point M){
        return abs(a*M.x + b*M.y + c) / sqrt(a*a + b*b);
    }
};

int n;
Point pivot;

int ccw(Point a, Point b, Point c){
    int t = (b-a)%(c-b);
    if ( t == 0 ) return 0;
    if ( t < 0 ) return 1;
    return -1;
}

int sqrdis(Point u, Point v){
    return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
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
        hull[m++] = hull[i];
    }

    hull.resize(m);
    return hull;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    while ( cin >> n ){
        if ( n == 0 ) break;
        vector<Point> a;
        for (int i = 1; i <= n; i ++){
            int x, y; cin >> x >> y;
            a.pb({x, y});
        }
        vector<Point> hull = convexhull(a);

        vector<Line> lines;
        int A, B, C, m = hull.size();
        for (int i = 0; i < m - 1; i ++){
            A = hull[i].y - hull[i+1].y;
            B = hull[i+1].x - hull[i].x;
            C = hull[i].x*hull[i+1].y - hull[i].y*hull[i+1].x;
            lines.pb({A, B, C});
        }
        A = hull[m-1].y - hull[0].y;
        B = hull[0].x - hull[m-1].x;
        C = hull[m-1].x*hull[0].y - hull[m-1].y*hull[0].x;
        lines.pb({A, B, C});

        double res = INT_MAX;
        for (auto d : lines){
            double tmp = 0;
            for (auto p : hull)
                tmp = max(tmp, d.kc(p));
            res = min(res, tmp);
        }

        cout << fixed << setprecision(2) << res << '\n';
    }

    return 0;
}
