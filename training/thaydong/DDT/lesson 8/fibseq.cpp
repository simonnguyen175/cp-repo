#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100005;

int n, p, q;
ll f[61], ans = 0, s[N];

ll tknp(ll l, ll r, ll x){
	ll d = l, c = r, mid;
	while( d <= c ){
		mid = (d + c) / 2;
		if ( s[g] == x ) return mid;
		if ( s[g] < x ) d = g + 1;
		else c = g - 1;
	}
	return -1;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

	cin >> n >> p >> q ;
	s[0] = 0;
	for (int i = 1 ; i <= n ; i++){
        ll x;
        cin >> x;
        s[i] = s[i - 1] + x;
	}

	f[1] = 0 , f[2] = 1;

    for (int i = 3 ; i <= 60; i++) f[i] = f[i - 1] + f[i - 2] ;

    for (int i = 1 ; i <= n ; i++){
    	for (int j = 1 ; j <= 60; j++){
    		if ( j == 3 ) continue;
    		if ( s[i] < f[j] ) break;
    		ll pos = tknp(0 , i , s[i] - f[j]);
    		if ( pos == -1 ) continue;

    	    if ( i - pos  >= p && i - pos  <= q ) ans ++;

    	    int l = pos - 1, r = pos + 1;
    	    while ( l >= 0 && s[l] == s[i] - f[j] && i - l >= p && i - l <= q )
                    ans ++, l --;
    	    while ( r <= i && s[r] == s[i] - f[j] && i - r >= p && i - r >= p)
                    ans ++, r ++;
		}
	}
  cout << ans;
}

