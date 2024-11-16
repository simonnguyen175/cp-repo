#include<bits/stdc++.h>
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int range(int l, int r){
	return l + rng() % ( r - l + 1 );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int n = range(1, 20000);
    cout << n << ' ' << 1 << '\n';
    for (int i = 1; i <= n; i ++)
        cout << range(1, 60) << ' ';
    cout << '\n';
    cout << range(1, 5);

    return 0;
}
