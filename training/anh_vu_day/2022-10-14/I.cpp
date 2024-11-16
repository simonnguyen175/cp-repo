#include<bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int R, C, K;
struct matrix{
    int v[55][55];
} A;
char a[55][55];
int b[55], d[55][55], go[55][55];

matrix mul(matrix a, matrix b){
    matrix c;
    memset(c.v, 0, sizeof c.v);
    for (int i = 1; i <= C; i ++)
    for (int j = 1; j <= C; j ++){
        c.v[i][j] = a.v[i][j];
        for (int k = 1; k <= C; k ++) if ( go[i][k] && go[k][j] )
            c.v[i][j] = max(c.v[i][j], a.v[i][k] + b.v[k][j]);
    }
    return c;
}

matrix Pow(matrix a, int b){
    if ( b == 1 ) return a;
    matrix tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

bool inside(int x, int y){
    return ( x >= 1 && x <= R && y >= 1 && y <= C );
}

void bfs(int x){
    memset(d, 0, sizeof d);
    queue<pi> q;
    q.push({0, x});
    d[0][x] = 1;
    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();

        if ( a[x][y] == '.' && inside(x+1, y) && a[x+1][y] != '#' && !d[x+1][y] )
            d[x+1][y] = 1, q.push({x+1, y});

        if ( a[x][y] == '?' || a[x][y] == 'R' )
        if ( inside(x, y+1) && a[x][y+1] != 'X' && !d[x][y+1] ) d[x][y+1] = 1, q.push({x, y+1});

        if ( a[x][y] == '?' || a[x][y] == 'L' )
        if ( inside(x, y-1) && a[x][y-1] != 'X' && !d[x][y-1]) d[x][y-1] = 1, q.push({x, y-1});
    }

    for (int i = 1; i <= C; i ++)
        if ( a[R][i] == '.' && d[R][i] )
            A.v[x][i] = b[i], go[x][i] = 1;

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> R >> C >> K;

    for (int i = 0; i <= C; i ++)
        a[0][i] = '.';

    for (int i = 1; i <= R; i ++)
    for (int j = 1; j <= C; j ++)
        cin >> a[i][j];
    for (int i = 1; i <= C; i ++)
        cin >> b[i];

    for (int i = 1; i <= C; i ++)
        bfs(i);

    A = Pow(A, K);

    int ans = 0;
    for (int i = 1; i <= C; i ++)
    for (int j = 1; j <= C; j ++)
        ans = max(ans, A.v[i][j]);

    cout << ans;

    return 0;
}
