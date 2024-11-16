#include<bits/stdc++.h>
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int t, n;
string s;

int range(int l, int r){
    return l + rng() % ( r - l + 1 );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    t = range(1, 10);
    cout << t << '\n';
    while ( t -- ){
        n = range(1, 10);
        s = "";
        for (int i = 1; i <= n; i ++)
            s += (char) ( 'a' + range(0, 25) );
        cout << n << '\n' << s << '\n';
    }

    return 0;
}
