#include <bits/stdc++.h>
using namespace std;

string a,b;

int main(){
    cin >> a >> b ;
    if ( a + b > b + a ) cout << a << b ;
    else cout << b << a ;
    return 0;
}
