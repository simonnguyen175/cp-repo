#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define BIT(x,k) ((x>>k)&1)
#define simon "maze"
using namespace std;
const int N = 1e2 + 5;
const int oo = 1e9 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int r, c;
char a[N][N];
int d[N][N][1<<4], id[300];
pi s;
struct node{
    int x, y, t;
};

bool inside(int x, int y){
    return ( x >= 1 && x <= r && y >= 1 && y <= c );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> r >> c;
    for (int i = 1; i <= r; i ++)
    for (int j = 1; j <= c; j ++){
        cin >> a[i][j];
        if ( a[i][j] == '*' ) s = {i, j};
    }

    id['y'] = id['Y'] = 0;
    id['r'] = id['R'] = 1;
    id['g'] = id['G'] = 2;
    id['b'] = id['B'] = 3;

    queue<node> q;
    memset(d, -1, sizeof d);

    int ans = oo;
    d[s.fi][s.se][0] = 0;
    q.push({s.fi, s.se, 0});
    while ( q.size() ){
        int x = q.front().x, y = q.front().y, t = q.front().t;
        if ( a[x][y] == 'X' ) ans = min(ans, d[x][y][t]);
        q.pop();
        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i], nt = t;

            if ( !inside(nx, ny) || a[nx][ny] == '#' ) continue;

            if ( a[nx][ny] >= 'A' && a[nx][ny] <= 'Z' && a[nx][ny] != 'X' )
                if ( !BIT(t, id[a[nx][ny]]) ) continue;

            if ( a[nx][ny] >= 'a' && a[nx][ny] <= 'z' )
                nt = t | (1<<id[a[nx][ny]]);

            if ( d[nx][ny][nt] != -1 ) continue;

            d[nx][ny][nt] = d[x][y][t] + 1;
            q.push({nx, ny, nt});
        }
    }

    if ( ans == oo ) cout << "The poor student is trapped!";
    else cout << "Escape possible in " << ans << " steps.";

    return 0;
}
