#include<bits/stdc++.h>
using namespace std;

string a;
int d[6];

int main(){
    int cnt = 0;

    while ( cin >> a ){
        if ( a.find("Welcome") != -1 && !d[1] ) d[1] = 1, cnt ++;
        if ( a.find("Hue") != -1 && !d[2] ) d[2] = 1, cnt ++;
        if ( a.find("University") != -1 && !d[3] ) d[3] = 1, cnt ++;
        if ( a.find("of") != -1 && !d[4] ) d[4] = 1, cnt ++;
        if ( a.find("Sciences") != -1 && !d[5] ) d[5] = 1, cnt ++;
        if ( cnt == 5 ) {cout << "Yes"; return 0;}
    }
    cout << "No";

    return 0;
}
