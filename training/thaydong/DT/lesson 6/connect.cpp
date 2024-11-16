#include<bits/stdc++.h>
#define simon "connect"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e2 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};
const int oo = 1e9;

int m, n, ans = oo;
int a[N][N], c[N][N], g[2][15][N][N], f[N][N][2][2];
queue<pi> q[10005];
struct cell{
    int d, x, y;
    bool operator > (const cell &a) const{
        return d > a.d;
    }
};

struct node{
    int x, y, tl, tr;
};
queue<node> heap[10005];

void dijkstra(int id, int s){
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = abs(a[i][j] - s);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        g[id][s][i][j] = oo;

    if ( !id )
        for (int i = 1; i <= m; i ++)
            g[id][s][i][1] = c[i][1], q[c[i][1]].push({i, 1});
    else
        for (int i = 1; i <= m; i ++)
            g[id][s][i][n] = c[i][n], q[c[i][n]].push({i, n});

    for (int d = 0; d <= 10000; d ++){
        while ( q[d].size() ){
            int x = q[d].front().fi, y = q[d].front().se;
            q[d].pop();
            if ( d != g[id][s][x][y] ) continue;
            for (int i = 0; i <= 3; i ++){
                int nx = x + row[i], ny = y + col[i];
                if ( nx < 1 || ny < 1 || nx > m || ny > n ) continue;
                if ( g[id][s][nx][ny] > d + c[nx][ny] ){
                    g[id][s][nx][ny] = d + c[nx][ny];
                    q[g[id][s][nx][ny]].push({nx, ny});
                }
            }
        }
    }
}

void anal(int s){
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        c[i][j] = abs(a[i][j] - s);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
    for (int t = 0; t <= 1; t ++)
        f[i][j][t][t] = f[i][j][t][1-t] = oo;

    for (int i = 1; i <= n; i ++){
        f[1][i][0][0] = c[1][i];
        heap[c[1][i]].push({1, i, 0, 0});
    }

    for (int d = 0; d <= 10000; d ++){
        while ( heap[d].size() ){
            int x = heap[d].front().x, y = heap[d].front().y;
            int tl = heap[d].front().tl, tr = heap[d].front().tr;
            heap[d].pop();

            if ( d != f[x][y][tl][tr] ) continue;

            if ( !tl && f[x][y][1][tr] > f[x][y][tl][tr] + g[0][s][x][y] - c[x][y] ){
                f[x][y][1][tr] = f[x][y][tl][tr] + g[0][s][x][y] - c[x][y];
                heap[f[x][y][1][tr]].push({x, y, 1, tr});
            }

            if ( !tr && f[x][y][tl][1] > f[x][y][tl][tr] + g[1][s][x][y] - c[x][y] ){
                f[x][y][tl][1] = f[x][y][tl][tr] + g[1][s][x][y] - c[x][y];
                heap[f[x][y][tl][1]].push({x, y, tl, 1});
            }

            for (int i = 0; i <= 3; i ++){
                int nx = x + row[i], ny = y + col[i];
                if ( nx < 1 || ny < 1 || nx > m || ny > n ) continue;
                if ( f[nx][ny][tl][tr] > f[x][y][tl][tr] + c[nx][ny] ){
                    f[nx][ny][tl][tr] = f[x][y][tl][tr] + c[nx][ny];
                    heap[f[nx][ny][tl][tr]].push({nx, ny, tl, tr});
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++)
        ans = min(ans, f[m][i][1][1]);
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x; cin >> x;
        a[i][j] = x - '0';
    }

    for (int s = 0; s <= 9; s ++)
        dijkstra(0, s), dijkstra(1, s);

    for (int s = 0; s <= 9; s ++)
        anal(s);

    cout << ans;

    return 0;
}
