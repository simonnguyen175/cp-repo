#include<bits/stdc++.h>
using namespace std;

string a[7], x, y;
map<string, int> d;

int main(){
    if ( fopen("color.inp", "r") ){
        freopen("color.inp", "r", stdin);
        freopen("color.out", "w", stdout);
    }

    d["Yellow"] = 1, a[1] = "Yellow";
    d["Green"] = 2, a[2] = "Green";
    d["Blue"] = 3, a[3] = "Blue";
    d["Violet"] = 4, a[4] = "Violet";
    d["Red"] = 5, a[5] = "Red";
    d["Orange"] = 6, a[6] = "Orange";

    cin >> x >> y;
    if ( d[x] < d[y] ) swap(x, y);
    if ( d[x] == d[y] ) cout << "Same";
    else if ( d[x]-d[y] == 1 || ( d[x] == 6 && d[y] == 1 ) ) cout << "Adjacent";
    else if ( d[x]-d[y] == 2 || ( d[x] == 5 && d[y] == 1 ) || ( d[x] == 6 && d[y] == 2 ) ){
        if ( d[x]-d[y] == 2 ) cout << a[d[x]-1];
        else if ( d[x] == 5 && d[y] == 1 ) cout << a[6];
        else if ( d[x] == 6 && d[y] == 2 ) cout << a[1];
    }
    else if ( abs(d[x]-d[y]) == 3 )
        cout << "Complementary";

    return 0;
}
