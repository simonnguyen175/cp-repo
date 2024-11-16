#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e3 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n;
char a[N][N];
int f[N][N], g[N][N];
pi sta, fin;
vector<pi> sna;
queue<pi> q;

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

bool check(int d){
    if ( f[sta.fi][sta.se] < d || f[fin.fi][fin.se] < d ) return false;
    memset(g, -1, sizeof g);
    q.push(sta); g[sta.fi][sta.se] = 0;

    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for (int i = 0; i <= 3; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) ) continue;
            if ( g[nx][ny] != -1 || f[nx][ny] < d ) continue;
            g[nx][ny] = g[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return g[fin.fi][fin.se] != -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        if ( a[i][j] == 'P' ) sta = {i, j};
        if ( a[i][j] == 'C' ) fin = {i, j};
        if ( a[i][j] == '+' ) sna.pb({i, j});
    }

    memset(f, -1, sizeof f);
    for (pi x : sna) q.push(x), f[x.fi][x.se] = 0;
    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for (int i = 0; i <= 3; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) ) continue;
            if ( f[nx][ny] != -1 ) continue;
            f[nx][ny] = f[x][y] + 1;
            q.push({nx, ny});
        }
    }

//    for (int i = 1; i <= m; i ++){
//    for (int j = 1; j <= n; j ++)
//        cerr << f[i][j] << ' ';
//    cerr << '\n';
//    }
//    cerr << "-------------\n";
//
//    cerr << check(2) << '\n';

    int lo = 0, hi = m + n, res;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }
    cout << res;

    return 0;
}
