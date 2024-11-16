#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 8e3 + 5 , MOD = 1e6 + 3 , M = 4e5 + 5;

using namespace std;

void file() {
	freopen("mine.inp" , "r" , stdin);
	freopen("mine.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , m , a[N] , dp[N] , f[M] , inv[M];

ll Pow(int a , int b) {
	if(b == 0) return 1;
	ll res = Pow(a , b / 2);
	res = res * res % MOD;
	if(b % 2) return res * a % MOD;
	return res;
}

int Catalan(int x) {
	return (Pow(x + 1 , MOD - 2) * f[2 * x] % MOD) * (inv[x] * inv[x] % MOD) % MOD;
}

int main() {
	file();
	cin >> n >> m;
	f[0] = 1;
	for(int i = 1 ; i < M ; i++)
		f[i] = f[i - 1] * i % MOD;
	inv[M - 1] = Pow(f[M - 1] , MOD - 2);
	for(int i = M - 2 ; i >= 0 ; i--)
		inv[i] = inv[i + 1] * (i + 1) % MOD;
	if(m == 1e6) {
		cout << Catalan(n);
		return 0;
	}
	for(int i = 1 ; i <= 2 * n ; i++) cin >> a[i];
	dp[0] = 1;
	for(int i = 2 ; i <= 2 * n ; i += 2)
		for(int j = i - 2 ; j >= 0 ; j -= 2) {
			if(a[i] - a[j + 1] <= m) {
				dp[i] = (dp[i] + dp[j] * Catalan((i - j - 2) / 2)) % MOD;
			}
		}
	cout << dp[2 * n];
	return 0;
}
