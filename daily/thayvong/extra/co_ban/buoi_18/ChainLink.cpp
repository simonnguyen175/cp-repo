#include <bits/stdc++.h>
using namespace std;

int n;
int a[20020];

int main() {
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	sort(a+1, a+1+n);
	int save = 0;
	for(int i=0, total=0; i<n; ++i) {
		total += a[i];
		if( total < n-i-1 ) save = i + 1;
	}
	cout << n-1-save;
	//system("pause");
	return 0;
}
