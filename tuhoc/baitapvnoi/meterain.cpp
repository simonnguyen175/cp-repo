#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n, t;
struct point{
    ll x, y;
    point() { x = y = 0; }
    point (int x, int y) : x(x), y(y) {}
    point operator + (const point &a) const { return point(x+a.x, y+a.y); }
    point operator - (const point &a) const { return point(x-a.x, y-a.y); }

    ll operator % (const point &a) const { return x*a.y - y*a.x; }
};
vector<point> hull;

int ccw(point a, point b, point c){
    ll ori = (b-a)%(c-b);
    if ( ori == 0 ) return 0;
    if ( ori < 0 ) return 1;
    return -1;
}

bool inside(point a){
    if ( ccw(hull[0], a, hull[1]) <= 0 ) return 0;

    int lo = 1, hi = n-1, res = -1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( ccw(hull[0], a, hull[mid]) < 0 ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    if ( res == -1 ) return 0;

    int o = ccw(hull[res-1], a, hull[res]);

    if ( o > 0 ) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("in.inp", "r") ){
        freopen("in.inp", "r", stdin);
        freopen("out.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x >> y;
        hull.pb({x, y});
    }

    cin >> t;
    while ( t -- ){
        int x, y;
        cin >> x >> y;
        if ( inside(point(x, y)) ) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
