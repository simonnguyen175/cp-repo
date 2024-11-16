#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n;
char a[N][N];
int d[N][N], vis[N][N];

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= n );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    queue<pi> q;
    for (int i = 1; i <= n; i ++){
        if ( a[1][i] == 'O' ) d[1][i] = 1, vis[1][i] = 1, q.push({1, i});
        if ( a[n][i] == 'O' ) d[n][i] = 1, vis[n][i] = 1, q.push({n, i});
    }

    for (int i = 2; i <= n - 1; i ++){
        if ( a[i][1] == 'O' ) d[i][1] = 1, vis[i][1] = 1, q.push({i, 1});
        if ( a[i][n] == 'O' ) d[i][n] = 1, vis[i][n] = 1, q.push({i, n});
    }

    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) || a[nx][ny] == 'X' || vis[nx][ny] ) continue;
            d[nx][ny] = 1;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        if ( d[i][j] ) cnt ++;

    if ( cnt > n * n - cnt ) cout << 1;
    else if ( cnt == n * n - cnt ) cout << 0;
    else cout << -1;

    return 0;
}
