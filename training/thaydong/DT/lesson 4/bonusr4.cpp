#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>
using namespace std;
const int N = 1005, M = 5e4 + 5;
const int row[] = {1 , 0 , -1 , 0};
const int col[] = {0 , 1 , 0 , -1};

int n, m, q;
int a[N][N], d[N][N], f[N][N];
pi par[N][N];

void dfs(int x, int y){
    for (int i = 0; i < 4; i ++){
		int	nx = x + row[i], ny = y + col[i];
        if ( nx < 1 || ny < 1 || nx > n || ny > m || a[x][y] != a[nx][ny] || par[nx][ny].fi ) continue;
        par[nx][ny] = par[x][y];
        dfs(nx, ny);
    }
}

int Get(int x, int y, int u, int v){
    return f[u][v] - f[u][y-1] - f[x-1][v] + f[x-1][y-1];
}

void solve(int x1, int y1, int x2, int y2){
    vector<pi> trace;
    int res = Get(x1, y1, x2, y2);
    pi p;

    for (int i = x1; i <= x2; i ++){
        p = par[i][y1];
        if ( (p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se] )
            res++, d[p.fi][p.se] = 1, trace.pb(p);
        p = par[i][y2];
        if ( (p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se] )
            res++, d[p.fi][p.se] = 1, trace.pb(p);
    }

    for(int i = y1; i <= y2; i ++){
        p = par[x1][i];
        if ( (p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se])
            res++, d[p.fi][p.se] = 1, trace.pb(p);

        p = par[x2][i];
        if ( (p.fi < x1 || p.fi > x2 || p.se < y1 || p.se > y2) && !d[p.fi][p.se])
            res++, d[p.fi][p.se] = 1, trace.pb(p);
    }

    cout << res << '\n';
    for (auto x : trace) d[x.fi][x.se] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> a[i][j];

    for(int i = 1; i <= n; i ++)
		 for(int j = 1; j <= m; j ++){
		 	f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1];
		 	if ( !par[i][j].fi ){
		  	   par[i][j] = {i, j}, dfs(i, j);
		  	   f[i][j]++;
		    }
		}

	cin >> q;
	while ( q -- ){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        solve(x1, y1, x2, y2);
	}

	return 0;
}

