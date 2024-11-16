#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 2001;
const int oo = 1e9;
const int base = 1001;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n, s;
int bar[N+5][N+5], d[N+5][N+5], ans[2];

bool inside(int x, int y){
    return ( x >= 0 && y >= 0 && x <= N && y <= N );
}

void bfs(){
    for (int i = 0; i <= N; i ++)
    for (int j = 0; j <= N; j ++)
        d[i][j] = oo;
    d[base][base] = 0;
    queue<pi> q;
    q.push({base, base});
    while ( q.size() ){
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        if ( d[x][y] > s ) break;

        ans[d[x][y]&1] ++;

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) || bar[nx][ny] || d[nx][ny] != oo ) continue;
            d[nx][ny] = d[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

void add(int x){
    if ( x >= s ) return;
    ans[x&1] += (s-x) / 2;
    ans[!(x&1)] += (s-x+1) / 2;
}

void add1(int x){
    if ( x >= s ) return;
    for (int i = 1; i < s-x; i ++)
        ans[(x+i+1)&1] += i;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("hoinghi.inp", "r", stdin);
    freopen("hoinghi.out", "w", stdout);

    cin >> n >> s;
    for (int i = 1, x, y; i <= n; i ++){
        cin >> x >> y;
        x += base;
        y += base;
        bar[x][y] = 1;
    }

    bfs();

    for (int i = 0; i <= N; i ++){
        add(d[0][i]);
        add(d[N][i]);
        add(d[i][0]);
        add(d[i][N]);
    }

    add1(d[0][0]);
    add1(d[0][N]);
    add1(d[N][0]);
    add1(d[N][N]);

    cout << ans[0] << ' ' << ans[1];

    return 0;
}
