
#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 405 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

int n , a[N][N] , ans[N][N] , row[N][N] , col[N][N] , f[N][N];

int id(int x , int y) {
	int u = (x - 1) / n + 1;
	int v = (y - 1) / n + 1;
	return (u - 1) * n + v;
}

void gen(int x , int y) {
	if(a[x][y]) {
		int i = a[x][y];
		if(row[x][i] || col[y][i] || f[id(x , y)][i]) return ;
		row[x][i] = col[y][i] = f[id(x , y)][i] = 1;
		ans[x][y] = i;
		if(x == n * n && y == n * n) {
			for(int i = 1 ; i <= n * n ; i++) {
				for(int j = 1 ; j <= n * n ; j++)
					cout << ans[i][j] << ' ';
				cout << '\n';
			}
			exit(0);
		}
		else {
			if(y == n * n) gen(x + 1 , 1);
			else gen(x , y + 1);
		}
	}
	else {
		for(int i = 1 ; i <= n * n ; i++) {
			if(row[x][i] || col[y][i] || f[id(x , y)][i]) continue;
			row[x][i] = col[y][i] = f[id(x , y)][i] = 1;
			ans[x][y] = i;
			if(x == n * n && y == n * n) {
				for(int u = 1 ; u <= n * n ; u++) {
					for(int v = 1 ; v <= n * n ; v++)
						cout << ans[u][v] << ' ';
					cout << '\n';
				}
				exit(0);
			}
			else {
				if(y == n * n) gen(x + 1 , 1);
				else gen(x , y + 1);
			}
			row[x][i] = col[y][i] = f[id(x , y)][i] = 0;
			ans[x][y] = 0;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1 ; i <= n * n ; i++)
		for(int j = 1 ; j <= n * n ; j++)
			cin >> a[i][j];
	gen(1 , 1);
	return 0;
}


