#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

struct point{
    ll x, y;
    point() { x = y = 0; }
    point(int x, int y) : x(x), y(y) {}
    point operator + (const point &a) const { return point(x+a.x, y+a.y); }
    point operator - (const point &a) const { return point(x-a.x, y-a.y); }

    ll operator % (const point &a) const { return x*a.y - y*a.x; }
};

int n;
vector<point> p, hull;
point pivot;

int ccw(point a, point b, point c){
    ll ori = (b-a)%(c-b);
    if ( ori == 0 ) return 0; // thang hang
    if ( ori < 0 ) return 1; // cung chieu dh
    return -1; // nguoc chieu dh
}

ll dis(point a, point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp1(point a, point b){
    if ( a.y == b.y ) return a.x < b.x;
    return a.y < b.y;
}

bool cmp2(point a, point b){
    int o = ccw(pivot, a, b);
    if ( o == 0 ) return dis(pivot, a) < dis(pivot, b);
    return ( o == -1 );
}

vector<point> convexhull(vector<point> &p){
    vector<point> q;
    sort(p.begin(), p.end(), cmp1);
    for (int i = 0; i < p.size(); i ++){
        q.pb(p[i]);
        while ( i + 1 < p.size() && p[i].x == p[i+1].x && p[i].y == p[i+1].y)
            i ++;
    }

    pivot = q[0];
    sort(q.begin() + 1, q.end(), cmp2);

    int m = 0;
    for (int i = 0; i < q.size(); i ++){
        while ( m >= 2 && ccw(q[m-2], q[m-1], q[i]) >= 0 )
            m --;
        q[m++] = q[i];
    }
    q.resize(m);
    return q;
}

void solve(){
    cin >> n;

    p.clear();
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x >> y;
        p.pb({x, y});
    }

    hull = convexhull(p);

//    cout << hull.size() << '\n';
//    for (auto it : hull) cout << it.x << ' ' << it.y << '\n';

    double area = 0;
    for (int i = 0; i < hull.size()-1; i ++)
        area += hull[i] % hull[i+1];
    area += hull[hull.size()-1] % hull[0];
    area = abs(area) * 1.0 /2;
    cout << area << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    while ( cin >> n )
//        if ( !n ) break;
//        else
            solve();

    return 0;
}
