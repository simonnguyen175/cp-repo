#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

int n, x;
int res[N], used[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> x;

	if ( x == 1 || x == 2*n-1 ) return cout << "No", 0;

	if ( n == 2 ) return cout << "Yes\n1\n2\n3", 0;

	res[n] = x;
	if (x == 2){
		res[n-1] = 2*n-1;
		res[n+1] = 1;
		res[n+2] = 2*n-2;
	}
	else if (x == 2 * n - 2) {
		res[n-1] = 1;
		res[n+1] = 2 * n - 1;
		res[n+2] = 2;
	}
	else{
		res[n-1] = x+1;
		res[n+1] = x-1;
		res[n+2] = x+2;
	}

	cout << "Yes\n";
	for (int i = 1; i <= 2*n-1; i ++) if ( res[i] )
        used[res[i]] = 1;

	for (int i = 1, id = 1; i <= 2*n-1; i ++)
		if ( res[i] ) cout << res[i] << '\n';
		else{
			while (used[id]) id ++;
			cout << id++ << '\n';
		}

	return 0;
}
