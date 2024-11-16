#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
long long a[N], f[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	f[1] = a[1];
	f[2] = a[1] + a[2];
    long long res = max(f[1], f[2]);

	for(int i = 3; i <= n; i ++){
		f[i] = max(f[i-2], f[i-3] + a[i-1]) + a[i];
		res = max(res, f[i]);
	}

    res = max(res, 0LL);
	cout << res;
}
