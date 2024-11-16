#include<bits/stdc++.h>
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
const int N = 2e3 + 5;

using namespace std;

int n , m;
vector<pi> tree[N];

void solve(int x) {
	m = 1;
	tree[1].pb({1, 2});
	for (int i = 3; i <= x; i += 2, m++){
		for (int j = 1; j <= m; j ++)
			tree[j].pb({j, i}), tree[j].pb({j+m, i+1});

		for (int j = 1; j <= m; j ++)
			tree[m+1].pb({j+m, i}), tree[m+1].pb({j, i+1});

		tree[m+1].pb({i, i+1});
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	cin >> n;
	if ( n % 2 ){
		solve(n-1);
		for (int i = 1; i <= m; i ++)
            tree[i].pb({i , n});
	}
	else solve(n);

	cout << n/2 << '\n';
	for(int i = 1; i <= m; i ++) {
		cout << n-1 << '\n';
		for (auto it : tree[i])
            cout << it.fi << ' ' << it.se << '\n';
	}

	return 0;
}

