#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("ball.inp" , "r" , stdin);
    freopen("ball.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll dp[N][N] , t;

int main() {
	file();
	dp[1][1] = 2 , dp[1][0] = 2;
  for(int i = 2 ; i <= 1000 ; i++) {
  	for(int j = i ; j >= 0 ; j--) {
  		dp[i][j] = ((dp[i][j + 1] * (j + 1)) % MOD + (dp[i - 1][j - 1] * 4) % MOD) % MOD;
	  }
  }
  cin >> t;
  while(t--) {
  	int x ;
  	cin >> x;
  	cout << dp[x][0] << endl;
  }
}


