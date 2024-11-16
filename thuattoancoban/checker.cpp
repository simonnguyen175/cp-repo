// random code 
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count()); 
ll range(ll l, ll r){
	return l + rng() % ( r - l + 1 ); 
}

// file bat 
b6_rd > in
b6_bf < in > out
b6 < in > ck
fc out ck
if errorlevel 1 exit
b6_ck