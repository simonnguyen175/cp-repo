#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 5e2 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n, m;
char a[N][N];
int num[N][N], low[N][N], child[N][N], vis[N][N], joint[N][N], f[N][N];
int cnt = 0, pre = 0, timeDfs = 0;
ll tmp, ans = 0;

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= m );
}

void dfs(int x, int y, int u, int v){
    cnt ++;
    num[x][y] = low[x][y] = ++timeDfs;
    child[x][y] = 0;
    bool ck = 0;
    for (int i = 0; i < 4; i ++){
        int nx = x + row[i], ny = y + col[i];
        if ( !inside(nx, ny) || a[nx][ny] == '#') continue;
        if ( nx == u && ny == v ) continue;
        if ( !num[nx][ny] ){
            dfs(nx, ny, x, y);
            low[x][y] = min(low[x][y], low[nx][ny]);
            child[x][y] ++;
            if ( x == u && y == v ){
                if ( child[x][y] > 1 ) joint[x][y] = 1;
            }
            else if ( low[nx][ny] >= num[x][y] ) joint[x][y] = 1;
        }
        else low[x][y] = min(low[x][y], num[nx][ny]);
    }
}

void dfs1(int x, int y, int u, int v){
    vis[x][y] = 1;
    int s = 0;

    for (int i = 0; i < 4; i ++){
        int nx = x + row[i], ny = y + col[i];
        if ( !inside(nx, ny) || a[nx][ny] == '#') continue;
        if ( nx == u && ny == v ) continue;

        if ( !vis[nx][ny] ) dfs1(nx, ny, x, ny);

        f[x][y] += f[nx][ny];

        if ( joint[x][y] ){
            ans += 2ll * s * (child[nx][ny] - f[nx][ny] + 1);
            s += child[nx][ny] - f[nx][ny] + 1;
        }
    }

    if ( joint[x][y] ){
        ans += 2ll * ( child[x][y] - f[x][y] ) * (cnt - 1 - child[x][y]);
        f[x][y] = child[x][y];
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    int nn = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        cin >> a[i][j];
        if ( a[i][j] == '.' ) nn ++;
    }

    ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        if ( !num[i][j] && a[i][j] == '.' ){
            cnt = 0;
            dfs(i, j, i, j);
            ans += 2 * cnt * pre;
            pre += cnt;
            dfs1(i, j, i, j);
        }

    cout << ans;

    return 0;
}
