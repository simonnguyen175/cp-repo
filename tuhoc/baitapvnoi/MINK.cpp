#include <bits/stdc++.h>
using namespace std;

const int N = 17005;

int t, n, a[N], k;
deque<int> q;


void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> a[i];

	while(q.size()) q.pop_front();
	for(int i = 1; i <= n; ++i) {
		while(q.size() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		if(q.front() < i - k + 1) q.pop_front();
		if(i >= k) cout << a[q.front()] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
		solve();
}
