#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
const double pi = 3.14159265358979323846;
const double eps = 0.6666;

int n, l;
struct point{
    int x, y;
    point() { x = y = 0.0; }
    point (int x, int y) : x(x), y(y){}
    point operator + (const point& a) const { return point(x+a.x, y+a.y); }
    point operator - (const point& a) const { return point(x-a.x, y-a.y); }

    double operator * (const point& a) const { return x*a.x + y*a.y; }
    double norm() { return x*x + y*y; }
};
vector<point> p;
point pivot;

int dis(point u, point v){
    return (u.x-v.x)*(u.x-v.x) + (u.y-v.y)*(u.y-v.y);
}

double angle(point a, point o, point b){
    a = a - o; b = b - o;
    return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));
}

double arc(int r, double angle){
    return r * angle;
}

bool cmp1(point a, point b){
    if ( a.y == b.y ) return a.x < b.x;
    return a.y < b.y;
}

int ccw(point a, point b, point c){
    int ori = (b.y-a.y)*(c.x-a.x) - (b.x-a.x)*(c.y-a.y);
    if ( ori == 0 ) return 0;
    if ( ori < 0 ) return -1;
    return 1;
}

bool cmp2(point u, point v){
    int o = ccw(pivot, u, v);
    if ( o == 0 ) return dis(pivot, u) < dis(pivot, v);
    return ( o == -1 );
}

vector<point> convexhull(vector<point> &p){
    vector<point> qu;
    sort(p.begin(), p.end(), cmp1);

    for (int i = 0; i < p.size(); i ++){
        qu.pb(p[i]);
        while ( i + 1 < p.size() && p[i].x == p[i+1].x && p[i].y == p[i+1].y )
            i ++;
    }

    pivot = qu[0];
    sort(qu.begin() + 1, qu.end(), cmp2);

    int m = 0;
    for (int i = 0; i < qu.size(); i ++){
        while ( m >= 2 && ccw(qu[m-2], qu[m-1], qu[i]) >= 0 )
            m --;
        qu[m++] = qu[i];
    }

    qu.resize(m);
    return qu;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> l;
    for (int i = 1; i <= n; i ++){
        int x, y;
        cin >> x >> y;
        p.pb({x, y});
    }

    vector<point> hull = convexhull(p);

    double ans = 0;
    for (int i = 0; i < hull.size() - 1; i ++)
        ans += (double) sqrt(dis(hull[i], hull[i+1]));
    ans += (double) sqrt(dis(hull[hull.size()-1], hull[0]));

    ans += arc(l, pi - angle(hull[hull.size()-1], hull[0], hull[1]));
    for (int i = 1; i < hull.size() - 1; i ++){
        ans += arc(l, pi - angle(hull[i-1], hull[i], hull[i+1]) );
    }
    ans += arc(l, pi - angle(hull[hull.size()-2], hull[hull.size()-1], hull[0]) );

    if ( ans - (int) ans  >= eps ) cout << (int) (ans+1.0);
    else cout << (int) ans;

    return 0;
}
