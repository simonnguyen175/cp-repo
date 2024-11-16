#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, k;
int a[N], b[N];

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	for (int i = 1; i <= m; i ++)
		cin >> b[i];

	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);

	int j = 1, ans = 0;
	for (int i = 1; i <= n; i ++){
		while ( j < m && b[j] < a[i] - k ){
			j ++;
		}

		if ( b[j] >= a[i] - k && b[j] <= a[i] + k ){
			ans ++;
			j ++;
		}
	}

	cout << ans;

	return 0;
}
