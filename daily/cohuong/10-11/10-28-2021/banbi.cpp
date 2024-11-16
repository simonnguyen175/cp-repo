#include<bits/stdc++.h>
#define simon "banbi"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e3 + 5;

int m, n, ans = 0, p, k, tt = 0;
int a[N][N], f[N][N][5], vis[N][N];

// 1 la dong, 2 la tay, 3 la nam, 4 la bac
int dfs(int x, int y, int dir){
    if ( x == 0 && dir == 4 ) return 0;
    if ( x == m + 1 && dir == 3 ) return 0;
    if ( y == 0 && dir == 2 ) return 0;
    if ( y == n + 1 && dir == 1 ) return 0;

    if ( f[x][y][dir] != -1 ) return f[x][y][dir];

    int res, nx, ny, c = 1;

    //cout << x << ' ' << y << ' ' << dir << '\n';

    if ( dir == 1 ){
        nx = x, ny = y + 1;
        //if ( vis[nx][ny] != tt ) c = 1, vis[nx][ny] = tt;
        if ( a[nx][ny] == 1 ) res = c + dfs(nx, ny, 3);
        if ( a[nx][ny] == 2 ) res = c + dfs(nx, ny, 4);
        if ( a[nx][ny] == 0 ) res = c + dfs(nx, ny, dir);
    }

    if ( dir == 2 ){
        nx = x, ny = y - 1;
        //if ( vis[nx][ny] != tt ) c = 1, vis[nx][ny] = tt;
        if ( a[nx][ny] == 1 ) res = c + dfs(nx, ny, 4);
        if ( a[nx][ny] == 2 ) res = c + dfs(nx, ny, 3);
        if ( a[nx][ny] == 0 ) res = c + dfs(nx, ny, dir);
    }

    if ( dir == 3 ){
        nx = x + 1, ny = y;
        //if ( vis[nx][ny] != tt ) c = 1, vis[nx][ny] = tt;
        if ( a[nx][ny] == 1 ) res = c + dfs(nx, ny, 2);
        if ( a[nx][ny] == 2 ) res = c + dfs(nx, ny, 1);
        if ( a[nx][ny] == 0 ) res = c + dfs(nx, ny, dir);
    }

    if ( dir == 4 ){
        nx = x - 1, ny = y;
        //if ( vis[nx][ny] != tt ) c = 1, vis[nx][ny] = tt;
        if ( a[nx][ny] == 1 ) res = c + dfs(nx, ny, 1);
        if ( a[nx][ny] == 2 ) res = c + dfs(nx, ny, 2);
        if ( a[nx][ny] == 0 ) res = c + dfs(nx, ny, dir);
    }

    f[x][y][dir] = res;

    return res;
}

void ckmax(int tmpp, int tmpk, int v){
    //cout << tmpp << ' ' << tmpk << ' ' << v << '\n' << '\n';
    if ( ans < v )
        ans = v, k = tmpk, p = tmpp;
    else if ( ans == v )
        if ( tmpp * 1001 + tmpk < p * 1001 + k )
            k = tmpk, p = tmpp;
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
        if ( x == '1' ) a[i][j] = 1;
        else if ( x == '2' ) a[i][j] = 2;
        else a[i][j] = 0;
    }

    memset(f, -1, sizeof f);

    for (int i = 1; i <= m; i ++){
        ++ tt, ckmax(1, i, dfs(i, 0, 1));
        ++ tt, ckmax(2, i, dfs(i, n+1, 2));
    }

    for (int i = 1; i <= n; i ++){
        ++ tt, ckmax(3, i, dfs(0, i, 3));
        ++ tt, ckmax(4, i, dfs(m+1, i, 4));
    }

    cout << p << ' ' << k;

    return 0;
}
