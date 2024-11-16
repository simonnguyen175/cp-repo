#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 505 , inf = 1e9 ,
	      row[] = {1 , -1 , 0 , 0} ,
	      col[] = {0 , 0 , 1 , -1};

int n , m , d1[15][N][N] , d2[15][N][N] , p[N][N][2][2] , ans = inf , a[N][N];
queue<pi> Q[10005];

void file() {
	//freopen("connect.inp" , "r" , stdin);
	//freopen("connect.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}

struct block {
	int u , v , t1 , t2;
};

bool in(int x , int y) {
	return (x >= 1 && x <= m && y >= 1 && y <= n);
}

void Dijkstra1(int C , int type , int d[15][N][N]) {
	for(int i = 1 ; i <= m ; i++)
	  for(int j = 1 ; j <= n ; j++)
	  	d[C][i][j] = inf;
	for(int i = 1 ; i <= m ; i++)
		d[C][i][type] = abs(a[i][type] - C),
		Q[abs(a[i][type] - C)].push({i , type});
	for(int i = 0 ; i <= 10000 ; i++) {
		while(!Q[i].empty()) {
			int u = Q[i].front().fi , v = Q[i].front().se;
			Q[i].pop();
			if(d[C][u][v] != i) continue;
			for(int j = 0 ; j < 4 ; j++) {
				int nxu = u + row[j] , nxv = v + col[j];
				if(!in(nxu , nxv)) continue;
				if(d[C][nxu][nxv] > i + abs(a[nxu][nxv] - C))
					d[C][nxu][nxv] = i + abs(a[nxu][nxv] - C) ,
					Q[d[C][nxu][nxv]].push({nxu , nxv});
			}
		}
	}
}

void Dijkstra2(int C) {
	queue<block> Q[10005];
	for(int i = 1 ; i <= m ; i++)
	  for(int j = 1 ; j <= n ; j++)
	  	p[i][j][0][0] = p[i][j][0][1] = p[i][j][1][0] = p[i][j][1][1] = inf;
	for(int i = 1 ; i <= n ; i++)
		p[1][i][0][0] = abs(a[1][i] - C),
		Q[abs(a[1][i] - C)].push({1 , i , 0 , 0});
	for(int i = 0 ; i <= 10000 ; i++) {
		while(!Q[i].empty()) {
			int u = Q[i].front().u , v = Q[i].front().v ,
				t1 = Q[i].front().t1 , t2 = Q[i].front().t2;
			Q[i].pop();
			if(p[u][v][t1][t2] != i) continue;
			for(int j = 0 ; j < 4 ; j++) {
				int nxu = u + row[j] , nxv = v + col[j];
				if(!in(nxu , nxv)) continue;
				if(p[nxu][nxv][t1][t2] > i + abs(a[nxu][nxv] - C))
					p[nxu][nxv][t1][t2] = i + abs(a[nxu][nxv] - C),
					Q[p[nxu][nxv][t1][t2]].push({nxu , nxv , t1 , t2});
			}
			if(p[u][v][1][t2] > i + d1[C][u][v] - abs(a[u][v] - C))
				p[u][v][1][t2] = i + d1[C][u][v] - abs(a[u][v] - C),
				Q[p[u][v][1][t2]].push({u , v , 1 , t2});
			if(p[u][v][t1][1] > i + d2[C][u][v] - abs(a[u][v] - C))
				p[u][v][t1][1] = i + d2[C][u][v] - abs(a[u][v] - C),
				Q[p[u][v][t1][1]].push({u , v , t1 , 1});
		}
	}
	for(int i = 1 ; i <= n ; i++)
		ans = min(ans , p[m][i][1][1]);
}

int main() {
	file();
	cin >> m >> n;
	for(int i = 1 ; i <= m ; i++)
      for(int j = 1 ; j <= n ; j++) {
			char x ; cin >> x ;
		    a[i][j] = x - '0';
		}
	for(int s = 0 ; s <= 9 ; s++)
		Dijkstra1(s , 1 , d1) , Dijkstra1(s , n , d2);
	for(int s = 0 ; s <= 9 ; s++)
		Dijkstra2(s);
	cout << ans;
	return 0;
}

