#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int n) {
	while (n % 2 == 0) n /= 2;
	return (n == 1);
}

int main(){
//    ios::sync_with_stdio(0);
//    cin.tie(0);cout.tie(0);

	cin >> n;
	if (check(n)) {
		cout << 0 <<  '\n';
		while (n != 0) {
			int x;
			cin >> x;
			n -= x;
			int dem = 0;
			int tam = n;
			while (tam % 2 == 0) {
				dem ++;
				tam /= 2;
			}
			cout << (1 << dem) << '\n';
			n -= (1 << dem);
		}
		return 0;
	}
	while (n > 0) {
		int dem = 0;
		int tam = n;
		while (tam % 2 == 0) {
			dem ++;
			tam /= 2;
		}
		cout << (1 << dem) << '\n';
		n -= (1 << dem);
		if (n == 0) return 0;
		int x;
		cin >> x;
		n -= x;
	}
	return 0;
}
