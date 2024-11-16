#include<bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int range(int l, int r){
	return l + rng() % ( r - l + 1 );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n = range(1, 5), m = range(1, n*(n-1)/2);
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i ++)
        cout << range(1, 1000000000) << ' ';

    return 0;
}
