#include<bits/stdc++.h>
#define simon "viking"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 7e2 + 5;
const int oo = 1e9;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int t, m, n;
char a[N][N];
bool vis[N][N];
int fb[N][N], fa[N][N];
int u[N][N], d[N][N], l[N][N], r[N][N];
pi pb, pa, pc;

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

bool check(int x, int y, int t){
    //cout << x << ' ' << y << ' ' << t << '\n';
    //cout << u[x-1][y] << ' ' << d[x+1][y] << ' ' <<  r[x][y+1] << ' ' << l[x][y-1] << '\n';
    return ( u[x-1][y] <= t || d[x+1][y] <= t || r[x][y+1] <= t || l[x][y-1] <= t );
}

void solve(){
    //cout << "-------------------" << '\n';
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        if ( a[i][j] == 'V' ) pb = {i, j};
        if ( a[i][j] == 'Y' ) pa = {i, j};
        if ( a[i][j] == 'T' ) pc = {i, j};
    }

    // make binh
    memset(vis, 0, sizeof vis);
    queue<pi> q; q.push(pb); vis[pb.fi][pb.se] = 1; fb[pb.fi][pb.se] = 0;
    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( vis[nx][ny] || !inside(nx, ny) || a[nx][ny] == 'I' ) continue;
            fb[nx][ny] = fb[x][y] + 1;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    // make u, d, l, r
    for (int i = 0; i <= m + 1; i ++)
    for (int j = 0; j <= n + 1; j ++)
        u[i][j] = d[i][j] = r[i][j] = l[i][j] = oo;

    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++)
            if ( a[i][j] != 'T' && a[i][j] != 'I' )
                l[i][j] = min(l[i][j-1], fb[i][j]);
        for (int j = n; j >= 1; j --)
            if ( a[i][j] != 'T' && a[i][j] != 'I' )
                r[i][j] = min(r[i][j+1], fb[i][j]);
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++)
            if ( a[j][i] != 'T' && a[j][i] != 'I' )
                u[j][i] = min(u[j-1][i], fb[j][i]);
        for (int j = m; j >= 1; j --)
            if ( a[j][i] != 'T' && a[j][i] != 'I' )
                d[j][i] = min(d[j+1][i], fb[j][i]);
    }

    // make an
    memset(vis, 0, sizeof vis);
    while ( q.size() ) q.pop();
    q.push(pa); vis[pa.fi][pa.se] = 1; fa[pa.fi][pa.se] = 0;
    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();
        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( vis[nx][ny] || !inside(nx, ny) || a[nx][ny] == 'I'
                || check(nx, ny, fa[x][y] + 1) ) continue;
            fa[nx][ny] = fa[x][y] + 1;
            vis[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    if ( vis[pc.fi][pc.se] ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
