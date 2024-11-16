#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main(){
    freopen("numcube.inp","r",stdin);
    freopen("numcube.out","w",stdout);
    cin >> x >> y ;
    long long a=cbrt(x);
    long long b=cbrt(y);
    cout << b-a+1;
}
