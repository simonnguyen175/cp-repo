#include<bits/stdc++.h>
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int range(int l, int r){
    return l + rng() % (r-l+1);
}
char t[] = {'H', 'V'};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n = range(1, 1000), m = range(1, 1000);
    int k = range(1, n+m+2);
    cout << n << ' ' << m << ' ' << k << '\n';
    for (int i = 1; i <= k; i ++){
        char type = t[range(0, 1)];
        cout << type << ' ';
        if ( type == 'H' ) cout << range(0, n) << '\n';
        else cout << range(0, m) << '\n';
    }

    return 0;
}
