#include<bits/stdc++.h>
const int base = 13234;
using namespace std;

int main(){
    freopen("thu.out", "w", stdout);

    cout << 200000 << ' ' << 200000 << '\n';
    for (int i = 1; i <= 200000; i ++)
        cout << i << ' ';
    cout << '\n';

    for (int i = 1; i <= 200000; i ++){
        int l = i, r = ( i + base ) % 200000;
        if ( l > r ) swap(l, r);
        cout << l << ' ' << r  << '\n';
    }

    return 0;
}
