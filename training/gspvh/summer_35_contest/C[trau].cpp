#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pi pair <ll, ll>
using namespace std;

int t;
int a, b;
pi f[12];
pi res;

void solve(int x) {
	vector < int > digit;
	while (x > 0) {
		digit.push_back(x % 10);
		x /= 10;
	}
	reverse(digit.begin(), digit.end());
	for (int i = 0; i < digit.size(); i++) {
		f[i] = {1, 1};
		for (int j = 0; j < i; j++) if ( digit[i] > digit[j] ){
			if ( f[i].fi < f[j].fi + 1){
				f[i] = f[j];
				f[i].fi ++;
			}
			else if ( f[i].fi == f[j].fi + 1) f[i].se += f[j].se;
		}
		if (res.fi < f[i].fi) res = f[i];
		else if (res.fi == f[i].fi) res.se += f[i].se;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

    if ( fopen("C.inp", "r") ){
        freopen("C.inp", "r", stdin);
        freopen("C.out", "w", stdout);
    }

    cin >> t;
    while ( t -- ){
        res = {0, 0};
        cin >> a >> b;
        for (int i = a; i <= b; i ++) solve(i);
            cout << res.fi << " " << res.se << '\n';
    }

    return 0;
}
