#include <bits/stdc++.h>
#define FNAME "substr"
using namespace std;

#define BIT(x, i) ((x) >> (i) & 1)

typedef pair<int, int> pii;
#define fi first
#define se second

const int N = 1e5 + 5, Z = 500;

string st;
int n;
int p[N], pri[N], sec[N];
int level[N], cp[N];

void suffix_array() {
	for (int i = 0; i < n; ++i)
		pri[i] = st[i] - '@';
	iota(p, p + n, 0);

	int len = 1;
	while (true) {
		for (int i = 0; i < n; ++i)
			sec[i] = pri[(i + len) % n];

		sort(p, p + n, [&](int &x, int &y) {
			if (pri[x] == pri[y]) return sec[x] < sec[y];
			return pri[x] < pri[y];
		});

		int rank = 0;
		for (int i = 0; i < n; ++i) {
			int j = i + 1;

			while (j < n && pri[p[i]] == pri[p[j]] && sec[p[i]] == sec[p[j]])
				pri[p[j++]] = rank;
			pri[p[i]] = rank;

			--j; ++rank;
			i = j;
		}
		if (len >= n) break;
		len *= 2;
	}
}

void lcp_array() {
	for (int i = 0; i < n; ++i)
		level[p[i]] = i;
	cp[0] = 0;
	int q = 0;
	for (int i = 0; i < n - 1; ++i) {
		int j = p[level[i] - 1];
		while (st[i + q] == st[j + q])
			++q;
		cp[level[i]] = q;
		if (q > 0) --q;
	}
    for (int i = 0; i < n; i ++) cout << cp[i] <<  ' '; cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	if (fopen(FNAME".inp", "r")) {
		freopen(FNAME".inp", "r", stdin);
		freopen(FNAME".out", "w", stdout);
	}
	cin >> st;
	st += '@'; n = st.size();
	suffix_array();
	lcp_array();
	cout << 1LL * n * (n + 1) / 2 - accumulate(cp, cp + n, 0LL) - n;
 	return 0;
}
