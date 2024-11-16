#include <bits/stdc++.h>
using namespace std;
long long x,y,x2,y2,x3,y3,d,c;
int main()
{
    cin >> x >> y;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    d=max(x,max(x2,x3));
    c=min(y,min(y2,y3));
    if (d > c) cout << 0;
    else
        cout <<  c - d +1;
    return 0 ;
}
