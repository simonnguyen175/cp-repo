#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define point pair<ll, ll>
using namespace std;

point a, b, c, d;

void solve(ll A, ll B, ll C, ll D, ll E, ll F){
    double y = ( C * D - F * A ) * 1.0 / ( B * D - E * A );
    double x = ( C - B * y ) * 1.0 / A;
    cout << fixed << setprecision(2) << -x << ' ' << -y << '\n';
}

int main(){
    int t;
    cin >> t;
    while ( t -- ){
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        ll A, B, C, D, E, F;
        A = a.y-b.y, B = b.x-a.x, C = a.x*b.y - a.y*b.x;
        D = c.y-d.y, E = d.x-c.x, F = c.x*d.y - c.y*d.x;

        if ( A * E == B * D ){
            if ( C * E == B * F ) cout << "LINE" << '\n';
            else cout << "NONE" << '\n';
        }
        else{
            cout << "POINT ";
            solve(A, B, C, D, E, F);
        }
    }

}
