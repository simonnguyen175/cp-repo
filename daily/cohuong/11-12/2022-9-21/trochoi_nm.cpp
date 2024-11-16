#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)
#define pb push_back

using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("trochoi.inp" , "r" , stdin);
	freopen("trochoi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t;
string s;
int n , f[N];
vector<int> ans;

void solve(string s , int x) {
	if(x) reverse(s.begin() , s.end());
	vector<int> res;
	bool ok = true;
	for(int i = 0 ; i < n / 2 ; i++) {
			if(i == 0) f[i] = (s[i] == s[n - i - 1]);
			else f[i] = f[i - 1] & (s[i] == s[n - i - 1]);
	}
	for(int i = (n - 1) / 2 ; i >= 0 ; i--) {
		if(i != (n - 1) / 2) ok &= (s[i + 1] == s[n - i - 1]);
		if((i == 0 || f[i - 1]) && ok) {
			if(x) ans.pb(n - i - 1);
			else ans.pb(i);
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	//file();
	cin >> t;
	while(t--) {
		ans.clear();
		cin >> n >> s;
		solve(s , 0);
		solve(s , 1);
		sort(ans.begin() , ans.end());
		ans.erase(unique(ans.begin() , ans.end()) , ans.end());
		cout << ans.size() << '\n';
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
	}
}
