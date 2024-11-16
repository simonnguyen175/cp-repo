#include<bits/stdc++.h>
#define ll long long
using namespace std;

long double x, y;

int main(){
    cin >> x >> y;
    long double a = sqrt(2.0*x*x + 2.0*x*y) + x*1.0 + y*1.0;
    if ( a >= y ) a = -sqrt(2.0*x*x + 2.0*x*y) + x*1.0 + y*1.0;
    long double b = 1.0*y - a;
    long double c = sqrt(1.0*a * a + 1.0*b * b);
    if ( a > b ) swap(a, b);
    cout << fixed << setprecision(9) << a << ' ' << b << ' ' << c;
    return 0;
}
