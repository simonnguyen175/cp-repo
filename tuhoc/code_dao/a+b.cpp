#include<bits/stdc++.h>
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

ll range(ll l, ll r){
	return l + rng() % ( r - l + 1 );
}

int main(){

}
