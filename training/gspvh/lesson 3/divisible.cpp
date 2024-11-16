#include<bits/stdc++.h>
#define eps 1e-6
using namespace std;

int n, k[55];
long double t = 0, p;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("divisible.inp", "r") ){
        freopen("divisible.inp", "r", stdin);
        freopen("divisible.out", "w", stdout);
    }

	cin >> n;
	for (int i = 1; i <= n; i ++)
        cin >> k[i], k[i] ++;

	for (int i = 1; i <= n; i ++)
        t = t + 1.0 * 1 / k[i];

	p = 1;
	if ( abs(t - 1) <= eps ){
		bool ck = true;
		sort(k + 1, k + n + 1);
		for (int i = 2; i <= n; i ++)
            if ( k[i] == k[i-1] )
                ck = false;

		cout << ( ck ? "Yes" : "No" );
	}
	else{
		if ( t > 1 ) cout << "No";
	    else cout << "Yes";
	}

    return 0;
}

