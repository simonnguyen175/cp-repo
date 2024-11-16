#include<bits/stdc++.h>
#define EPS 1e-6;
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 5005;

inline int cmp(double a, double b){
    return ( a < b - EPS ) ? -1 : ( (a > b + EPS) ? 1 : 0 );
}

struct Point{
    ll x, y;
    Point() { x = y = 0; }
    Point(ll x, ll y) : x(x), y(y) {}

    Point operator + (const Point &a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point &a) const { return Point(x-a.x, y-a.y); }

    ll norm() { return x*x + y*y;}
};

double angle(Point a, Point o, Point b){
    a = a - o; b = b - o;
    return acos(1.0 * (a*b) / sqrt(a.norm()) / sqrt(b.norm()));
}

bool cmp(Point a, Point b){
    return a.x < b.x;
}

pair<Point, int> a[N];


/// ncl xet goc tao ra lon nhat tren duong thang haizz luoi code qua
/// bai toan la 2 dinh nhin duoc nhau khi duong thang noi chung ko bi cat nhau qua boi dinh nao

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].x >> a[i].y, a[i].id = i;
    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i ++){
        ans[a[i].id] ++;
        mxang = angle(Point)
        for (int j = i-1; j >= 1; j --){
            if ( mxange )
        }
    }
}
