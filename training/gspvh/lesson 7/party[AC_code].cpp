#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e3 + 5;

void file() {
	freopen("party.inp" , "r" , stdin);
	freopen("party.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a[N] , pos[N] , dp[N][N];
vector<int> f[N];

void Btk(int l , int r) {
	if(l > r) return;
	for(int i = l + 1 ; i <= r ; i += 2) {
		if(dp[l][r] == dp[l + 1][i - 1] + dp[i + 1][r] + (a[l] == a[i])) {
			cout << l << ' ' << i << '\n';
			Btk(l + 1 , i - 1);
			Btk(i + 1 , r);
			break;
		}
	}
}

int main() {
	//file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] , f[a[i]].pb(i) , pos[i] = f[a[i]].size() - 1;
	for(int len = 2 ; len <= n ; len += 2) {
		for(int i = 1 ; i <= n - len + 1 ; i++) {
			int j = i + len - 1;
			if(a[i] == a[i + 1]) dp[i][j] = dp[i + 2][j] + 1;
			else if(a[j] == a[j - 1]) dp[i][j] = dp[i][j - 2] + 1;
			else if(a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1] + 1;
			else {
				dp[i][j] = max({dp[i + 2][j] , dp[i][j - 2] , dp[i + 1][j - 1]});
				for(int k = pos[i] + 1 ; k < f[a[i]].size() ; k++) {
					int pos = f[a[i]][k];
					if(pos > j) break;
					if((pos - i) % 2)
						dp[i][j] = max(dp[i][j] , 1 + dp[i + 1][pos - 1] + dp[pos + 1][j]);
				}
				for(int k = pos[j] - 1 ; k >= 0 ; k--) {
					int pos = f[a[j]][k];
					if(pos < i) break;
					if((j - pos) % 2)
						dp[i][j] = max(dp[i][j] , 1 + dp[pos + 1][j - 1] + dp[i][pos - 1]);
				}
			}
		}
	}
	cout << dp[1][n] << '\n';
	Btk(1 , n);
}

