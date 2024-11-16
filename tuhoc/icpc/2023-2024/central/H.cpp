#include <bits/stdc++.h>
using namespace std;

const int nmax = 1e5 + 10;

int n, m, a[nmax];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	int t = -1;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		int j = 1, k = 1, res = 0;
		for (int i = 1; i <= n; i++) {
			while (!(a[i] - a[j] < x)) j++;
			while (!(a[i] - a[k] <= y)) k++;
			res += j - k;
			if (res >= z) {
				t = max(t, a[i]);
				break;
			}
		}	
		if (res < z) {
			cout << -1;
			return 0;
		}	
	}
	cout << t;
	return 0;
}
