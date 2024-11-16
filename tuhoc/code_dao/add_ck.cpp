#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

int range(int l, int r){
    return l + rng() % (r - l + 1);
}

int main(){
    int a = range(1, 100);
    int b = range(1, 100);
    cout << a << ' ' << b;
    return 0;
}
