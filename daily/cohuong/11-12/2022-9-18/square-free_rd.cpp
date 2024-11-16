#include<bits/stdc++.h>
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
const int N = 1e4;

int range(int l, int r){
    return l + rng() % (r-l+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test, l, r;
    test = range(1, 10);
    cout << test << '\n';
    while ( test -- ){
        l = range(1, N);
        r = range(l, N);
        cout << l << ' ' << r << '\n';
    }

    return 0;
}

