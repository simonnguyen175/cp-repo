#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};
const int oo = 1e9;

int r, c, k, hx, hy, sx, sy;
string s;
int a[N][N];
struct cell{
    int x, y, t;
} trace[N][N][2];
int d[N][N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("gotoschool.inp", "r", stdin);
    freopen("gotoschool.out", "w", stdout);

    cin >> r >> c >> k >> hx >> hy >> sx >> sy;
    for (int i = 1; i <= r; i ++){
        cin >> s;
        int x, cnt = 0;
        for (int j = 0; j < s.size(); j ++){
            if ( '0' <= s[j] && s[j] <= '9' ) x = s[j] - '0';
            if ( 'A' <= s[j] && s[j] <= 'Z' ) x = s[j] - 'A' + 10;
            if ( 'a' <= s[j] && s[j] <= 'z' ) x = s[j] - 'a' + 36;
            if ( s[j] == '#' || s[j] == '$' ) x = s[j] - '#' + 62;
            for (int k = 0; k <= 5; k ++)
                a[i][++cnt] = BIT(x, k);
        }
    }

    for (int i = 1; i <= r; i ++)
    for (int j = 1; j <= c; j ++)
        d[i][j][0] = d[i][j][1] = oo;

    deque<cell> dq;
    d[hx][hy][0] = d[hx][hy][1] = 0;
    dq.push_back({hx, hy, 0});
    dq.push_back({hx, hy, 1});

    while ( dq.size() ){
        int x = dq.front().x, y = dq.front().y, t = dq.front().t;
        dq.pop_front();

        for (int i = 0; i <= 3; i ++){
            int nx = x + row[i], ny = y + col[i], w = 0, nt = t;
            if ( t == 0 && nx != x ) w = 1, nt = 1 - t;
            if ( t == 1 && ny != y ) w = 1, nt = 1 - t;

            if ( nx < 1 || nx > r || ny < 1 || ny > c ) continue;
            if ( a[nx][ny] ) continue;

            if ( d[nx][ny][nt] <= d[x][y][t] + w ) continue;

            d[nx][ny][nt] = d[x][y][t] + w;
            trace[nx][ny][nt] = {x, y, t};
            if ( nt != t ) dq.push_back({nx, ny, nt});
            else dq.push_front({nx, ny, nt});
        }
    }

    if ( min(d[sx][sy][0], d[sx][sy][1]) > k ){
        cout << -1; return 0;
    }

    cout << min(d[sx][sy][0], d[sx][sy][1]) << '\n';

    int t = 0;
    if ( d[sx][sy][0] > d[sx][sy][1] ) t = 1;
    vector<pi> ans;
    ans.pb({sx, sy});

    while ( sx != hx || sy != hy ){
        cell tmp = trace[sx][sy][t];
        if ( tmp.t != t ) ans.pb({tmp.x, tmp.y});
        sx = tmp.x, sy = tmp.y, t = tmp.t;
    }

    ans.pb({hx, hy});

    reverse(ans.begin(), ans.end());

    for (auto it : ans)
        cout << it.fi << ' ' << it.se << '\n';

    return 0;
}
