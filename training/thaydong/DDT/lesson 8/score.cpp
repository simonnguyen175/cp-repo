#include<bits/stdc++.h>
using namespace std;

int main(){
    int s = 0;
    for (int i = 1; i <= 6; i ++){
        int x;
        cin >> x;
        s += x;
    }

    if ( s >= 373 ) cout << "YES";
    else cout << "NO";

    return 0;
}
