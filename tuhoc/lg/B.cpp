#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e2 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int R, C, n, r, c;
pi pawn[N];
char a[N][N];
int d[55][N][N];

bool inside(int x, int y){
    return (x >= 1 && x <= R && y >= 1 && y <= C && a[x][y] != 'W');
}

void bfs(int p, int px, int py){
    queue<pi> q;
    d[p][px][py] = 0;
    q.push({px, py});

    while ( !q.empty() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( inside(nx, ny) && a[nx][ny] != 'W' && d[p][nx][ny] == -1 ){
                d[p][nx][ny] = d[p][x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void solve(){
    cin >> R >> C >> n >> r >> c;
    for (int i = 1; i <= n; i ++){
        int x, y;
        cin >> x >> y;
        pawn[i] = {x, y};
    }

    vector<pi> wall;
    for (int i = 1; i <= R; i ++)
    for (int j = 1; j <= C; j ++){
        cin >> a[i][j];
        if ( a[i][j] == 'W' ) wall.push_back({i, j});
    }

    for (int k = 0; k <= n; k ++)
    for (int i = 0; i <= R; i ++)
    for (int j = 0; j <= C; j ++)
        d[k][i][j] = -1;

    for (int i = 1; i <= n; i ++){
        bfs(i, pawn[i].fi, pawn[i].se);
    }
    bfs(0, r, c);

    int score = 0;
    for (int i = 1; i <= n; i ++){
        score += d[i][r][c];
//        cerr << d[i][r][c] << ' ';
    }
//    cerr << score << '\n';

    int net = 0;
    for (auto w : wall){
        int nscore = score;
//        cerr << "wall " << w.fi << ' ' << w.se << '\n';
        for (int k = 1; k <= n; k ++){
            int nd = d[k][r][c];
            for (int i = 0; i < 4; i ++)
            for (int j = 0; j < 4; j ++) if ( i != j ){
                int ix = w.fi + row[i], iy = w.se + col[i];
                int jx = w.fi + row[j], jy = w.se + col[j];
                if ( inside(ix, iy) && inside(jx, jy) && d[k][ix][iy] != -1 && d[0][jx][jy] != -1 ){
                    nd = min(nd, d[k][ix][iy] + 2 + d[0][jx][jy]);
//                    cerr << ix << ' ' << iy << " and " << jx << ' ' << jy << " : " << d[k][ix][iy] << ' ' << d[0][jx][jy] << '\n';
                }
            }
            nscore += nd - d[k][r][c];
//            cerr << pawn[k].fi << ' ' << pawn[k].se << ' ' << d[k][r][c] << ' ' << nd << '\n';
        }
//        cerr << "-> " << nscore << '\n';
        net += score - nscore;
    }

    cout << score << ' ' << net << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int test;
    cin >> test;
    while ( test -- ){
        solve();
    }

    return 0;
}
