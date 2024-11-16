#include <bits/stdc++.h>
using namespace std;

string x, y;

int main(){
    cin >> x >> y ;
    if (x.size()<y.size()) cout << x+y;
    else cout << y +x ;
}
