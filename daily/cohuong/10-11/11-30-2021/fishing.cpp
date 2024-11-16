#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 105 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("fishing.inp" , "r" , stdin);
	freopen("fishing.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N][N] , f[N][N][N] , g[N][N][N] , Max[N][N][N] , Min[N][N][N] , ans = 0;

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	for(int k = 1 ; k <= min(n , m) / 2; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++) {
				f[i][j][k] = Max[i - 1][j - 1][k - 1] + a[i][j];
				Max[i][j][k] = max({f[i][j][k] , Max[i - 1][j][k] , Max[i][j - 1][k]});
			}
	memset(Min , 0x3f , sizeof(Min));
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= m ; j++)
			Min[i][j][0] = 0;
	for(int k = 1 ; k <= min(n , m) ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++) {
				g[i][j][k] = Min[i - 1][j - 1][k - 1] + a[i][j];
				Min[i][j][k] = min({g[i][j][k] , Min[i - 1][j][k] , Min[i][j - 1][k]});
			}
	for(int i = 0 ; i <= min(n , m) / 2 ; i++) //cout << Max[n][m][i] << ' ' << Min[n][m][2 * i] << '\n';
		ans = max(ans , Max[n][m][i] - Min[n][m][2 * i]);
	cout << ans;
	return 0;
}



