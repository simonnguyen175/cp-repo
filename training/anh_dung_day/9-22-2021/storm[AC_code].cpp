
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 3e5 + 5 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	freopen("storm.inp" , "r" , stdin);
	freopen("storm1.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , q;
ll a[N] , nxr[N][25] , nxl[N][25] , suml[N][25] , sumr[N][25] , s[N] , ans;

void DequeMax() {
	deque<ll> dq;
	for(int i = n ; i >= 1 ; i--) {
		while(dq.size() && a[i] > a[dq.back()]) dq.pop_back();
		if(dq.size()) nxr[i][0] = dq.back() , sumr[i][0] = ((dq.back() - i - 1) * a[i] - s[dq.back() - 1] + s[i]) % MOD;
		else nxr[i][0] = n + 1 , sumr[i][0] = 0;
		dq.pb(i);
	}
	dq.clear();
    for(int i = 1 ; i <= n ; i++) {
		while(dq.size() && a[i] >= a[dq.back()]) dq.pop_back();
		if(dq.size()) nxl[i][0] = dq.back() , suml[i][0] = ((i - dq.back() - 1) * a[i] - s[i - 1] + s[dq.back()]) % MOD;
		else nxl[i][0] = 0 , suml[i][0] = 0;
		dq.pb(i);
	}
	nxr[n + 1][0] = n + 1;
	nxl[0][0] = 0;
}

void Build() {
	for(int j = 1 ; j <= log2(n) ; j++)
	  for(int i = 0 ; i <= n ; i++) {
	  	nxl[i][j] = nxl[nxl[i][j - 1]][j - 1];
	  	suml[i][j] = (suml[i][j - 1] + suml[nxl[i][j - 1]][j - 1]) % MOD;
	  	cout << i << ' ' << j << ' ' << nxl[nxl[i][j - 1]][j - 1] << '\n';
	  }

	for(int j = 1 ; j <= log2(n) ; j++)
	  for(int i = n + 1; i >= 1 ; i--) {
	  	nxr[i][j] = nxr[nxr[i][j - 1]][j - 1];
	  	sumr[i][j] = (sumr[i][j - 1] + sumr[nxr[i][j - 1]][j - 1]) % MOD;;
	  }
}

void get(int l , int r) {
   int	x = l , y = r ;
	for(int i = log2(n) ; i >= 0 ; i--) {
		if(nxr[x][i] <= r)  ans = (ans + sumr[x][i]) % MOD , x = nxr[x][i] ;
		if(nxl[y][i] >= l)  ans = (ans + suml[y][i]) % MOD , y = nxl[y][i] ;
	}
}

void solve() {
	ans = 0;
  cin >> n >> q;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
  DequeMax();
  Build();
  while(q--) {
  	int l , r;
  	cin >> l >> r;
  	get(l , r);
  }
  cout << ans << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

