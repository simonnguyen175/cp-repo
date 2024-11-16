#include<bits/stdc++.h>
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int range(int l, int r){
    return l + rng()%(r-l+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cout << 1 << '\n';
    int n = range(50, 100);
    for (int i = 1; i <= n; i ++)
        cout << (char)( 'a' + range(0, 25) );
    cout << ' ' << range(2, n);

    return 0;
}
