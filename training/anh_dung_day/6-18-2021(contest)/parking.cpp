#include<bits/stdc++.h>
#define simon "parking"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 55;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n, m;
struct pos{
    // u, v la toa do cua cho trong
    // x, y la toa do cua xe
    int u, v, x, y;
};
int carX, carY, empX, empY;
queue<pos> q;
char a[N][N];
int dp[N][N][N][N];
bool vis[N][N][N][N];

bool check(int u, int v, int x, int y){
    if ( vis[u][v][x][y] || u < 1 || u > m || v < 1 || v > n ) return false;
    if ( a[u][v] == '#' ) return false;
    return true;
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
            cin >> a[i][j];
            if ( a[i][j] == 'X' ) carX = i, carY = j;
            if ( a[i][j] == '.' ) empX = i, empY = j;
        }

    memset(vis, 0, sizeof vis);
    vis[empX][empY][carX][carY] = 1;
    dp[empX][empY][carX][carY] = 0;
    q.push({empX, empY, carX, carY});

    while( !q.empty() ){
        pos cur = q.front(); q.pop();
        //cout << cur.u << ' ' << cur.v << ' ' << cur.x << ' ' << cur.y << '\n';
        for (int i = 0; i < 4; i ++){
            int nu, nv, nx, ny;
            nu = cur.u + row[i]; nv = cur.v + col[i];

            if ( nu == cur.x && nv == cur.y ) nx = cur.u, ny = cur.v;
            else nx = cur.x, ny = cur.y;

            if ( !check(nu, nv, nx, ny) ) continue;
            //cout << "-> " << nu << ' ' << nv << ' ' << nx << ' ' << ny << '\n';

            dp[nu][nv][nx][ny] = dp[cur.u][cur.v][cur.x][cur.y] + 1;
            vis[nu][nv][nx][ny] = 1;
            q.push({nu, nv, nx, ny});
        }
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( vis[i][j][1][1] )
                ans = min(ans, dp[i][j][1][1]);
    if ( ans == INT_MAX ) cout << "Impossible";
    else cout << ans;
    return 0;
}
