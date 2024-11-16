#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Point{
    ll x, y;
    Point operator - (const Point &a) { return {x - a.x, y - a.y}; }
    ll operator % (const Point &a) { return x * a.y - y * a.x; }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        Point a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

        Point ab = b - a;
        Point bc = c - b;
        ll tmp = ab % bc;
        if ( tmp == 0 ) cout << "TOUCH\n";
        else if ( tmp < 0 ) cout << "RIGHT\n";
        else cout << "LEFT\n";
    }

    return 0;
}
