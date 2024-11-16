#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 180;
const int oo = 1e9;
const int row[] = {-1, 1, 0, 0, 0};
const int col[] = {0, 0, -1, 1, 0};

int sub, m, n;
char a[N][N];
string C;
int id[300];
int c[N];
pi sta, fin;
int f[N][N][305];

struct node{
    int x, y, cur;
};

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

struct tracing{
    int x, y, cur, type, p, c;
} trace[N][N][305];

struct oper{
    int type, p, c;
};
vector<oper> cont;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("dichuyen.inp", "r", stdin);
    freopen("dichuyen.out", "w", stdout);

    cin >> sub >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];
    id['U'] = 0, id['D'] = 1, id['L'] = 2, id['R'] = 3, id['H'] = 4;
    cin >> C;
    for (int i = 0; i < C.size(); i ++)
        c[i+1] = id[C[i]];

    char com[] = {'U', 'D', 'L', 'R', 'H'};

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
    if ( a[i][j] == 'S' ) sta = {i, j};
    else if ( a[i][j] == 'E' ) fin = {i, j};

//    cout << sta.fi << ' ' << sta.se << " -> " << fin.fi << ' ' << fin.se << '\n';

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
    for (int k = 0; k <= C.size(); k ++)
        f[i][j][k] = f[i][j][k] = oo;

    deque<node> q;
    q.push_back({sta.fi, sta.se, 0});
    f[sta.fi][sta.se][0] = 0;
    while ( q.size() ){
        node tmp = q.front();
        q.pop_front();
        int x = tmp.x, y = tmp.y, cur = tmp.cur;

//        cout << x << ' ' << y << ' ' << cur << ' ' << f[x][y][cur] << '\n';

        /// ko thao tac
        int nx = x + row[c[cur+1]], ny = y + col[c[cur+1]];
        if ( !inside(nx, ny) || a[nx][ny] == '#' )
            nx = x, ny = y;
        if ( f[nx][ny][cur+1] > f[x][y][cur] ){
            f[nx][ny][cur+1] = f[x][y][cur];
            trace[nx][ny][cur+1] = {x, y, cur, -1, 0, 0};
            q.push_front({nx, ny, cur+1});
        }

        /// chen ki tu
        for (int i = 0; i < 5; i ++){
            nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) || a[nx][ny] == '#' ) continue;
            if ( f[nx][ny][cur] > f[x][y][cur] + 1 ){
                f[nx][ny][cur] = f[x][y][cur] + 1;
                trace[nx][ny][cur] = {x, y, cur, 0, cur+1, i};;
                q.push_back({nx, ny, cur});
            }
        }

        /// thay doi ki tu
        for (int i = 0; i < 5; i ++) if ( i != c[cur+1] ){
            nx = x + row[i], ny = y + col[i];
            if ( !inside(nx, ny) || a[nx][ny] == '#' ) continue;
            if ( f[nx][ny][cur+1] > f[x][y][cur] + 1 ){
                f[nx][ny][cur+1] = f[x][y][cur] + 1;
                trace[nx][ny][cur+1] = {x, y, cur, 1, cur+1, i};
                q.push_back({nx, ny, cur+1});
            }
        }

        /// xoa doan
        for (int nxt = cur + 1; nxt <= C.size(); nxt ++){
            if ( f[x][y][nxt] > f[x][y][cur] + 1 ){
                f[x][y][nxt] = f[x][y][cur] + 1;
                trace[x][y][nxt] = {x, y, cur, 2, cur+1, nxt};
                q.push_back({x, y, nxt});
            }
        }
    }

    int ans = f[fin.fi][fin.se][C.size()];
    if ( ans == oo ) cout << -1;
    else cout << ans;

//    int x = fin.fi, y = fin.se, cur = C.size();
//
//    cout << trace[x][y][cur].type << ' ' << trace[x][y][cur].c << '\n';
//
//    while ( x != sta.fi && y != sta.se ){
//        cerr << trace[x][y][cur].type << ' ' << trace[x][y][cur].p << ' ' << trace[x][y][cur].c << '\n';
//        cont.pb({trace[x][y][cur].type, trace[x][y][cur].p, trace[x][y][cur].c});
//        int px = trace[x][y][cur].x;
//        int py = trace[x][y][cur].y;
//        int pcur = trace[x][y][cur].cur;
//        x = px, y = py, cur = pcur;
//        cerr << " -> " << x << ' ' << y << '\n';
//    }
//
//    reverse(cont.begin(), cont.end());
//    int clen = 0;
//    for (auto it : cont){
//        int type = it.type;
//        int p = it.p;
//        int c = it.c;
//
//        if ( type == -1 ) clen ++;
//
//        /// chen
//        if ( type == 0 ){
//            cout << "INS " << clen + 1 << ' ' << com[c] << '\n';
//            clen ++;
//        }
//
//        /// thay doi
//        if ( type == 1 ){
//            cout << "REP " << clen + 1 << ' ' << com[c] << '\n';
//        }
//
//
//        /// xoa
//        if ( type == 2 ){
//            cout << "DEL " << clen + 1 << ' ' << clen + c - p + 1 << '\n';
//        }
//    }

    return 0;
}
