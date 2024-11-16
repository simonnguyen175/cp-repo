#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

ll range(ll l, ll r){
	return l + rng() % ( r - l + 1 );
}

int main(){
    freopen("product.inp", "w", stdout);
    cout << range(1, 100) << ' ' << range(1, 100);
}
