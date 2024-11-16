#include<bits/stdc++.h>
#define simon "moveboard"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define x first
#define y second
#define ii pair<int, int>
using namespace std;
const int N = 1e3 + 5;

int m, n;
char a[N][N];
bool can[N][N], point[N][N];
string ans = "";

void solveMin(){
    ans = "";
    // mang danh dau co di tiep hay ko
    memset(point, 0, sizeof point);
    point[1][1] = 1;
    // chieu ngang
    for (int i = 1; i <= m; i ++){
        vector<ii> dc; dc.clear();
        char minC = (char) 125;
        for (int x = i, y = 1; x >= 1 && y <= i; x --, y ++)
            if ( can[x][y] ){
                dc.push_back({x, y});
                minC = min(minC, a[x][y]);
            }
        for (auto tmp : dc)
            if ( a[tmp.x][tmp.y] == minC )
                point[tmp.x+1][tmp.y] = point[tmp.x][tmp.y+1] = 1;
        for (int x = i + 1, y = 1; x >= 1 && y <= i + 1; x --, y ++)
            if ( !point[x][y] ) can[x][y] = 0;
        ans += minC;
    }
    // chieu doc
    for (int i = 2; i <= n; i ++){
        vector<ii> dc; dc.clear();
        char minC = (char) 125;
        for (int x = m, y = i; x >= 1 && y <= n; x --, y ++)
            if ( can[x][y] ){
                dc.push_back({x, y});
                minC = min(minC, a[x][y]);
            }
        for (auto tmp : dc)
            if ( a[tmp.x][tmp.y] == minC )
                point[tmp.x+1][tmp.y] = point[tmp.x][tmp.y+1] = 1;
        for (int x = m, y = i + 1; x >= 1 && y <= n; x --, y ++)
            if ( !point[x][y] ) can[x][y] = 0;
        ans += minC;
    }
    cout << ans << '\n';
}

void solveMax(){
    ans = "";
    // tao mang co the di den (m, n) hay ko
    memset(can, 0, sizeof can);
    for (int i = m; i >= 1; i --)
        for (int j = n; j >= 1; j --){
            if ( i == m && j == n ){
                can[i][j] = 1;
                continue;
            }
            if ( a[i][j] == '#' ) continue;
            can[i][j] = can[i+1][j] || can[i][j+1] ;
        }
    // mang danh dau co di tiep hay ko
    memset(point, 0, sizeof point);
    point[1][1] = 1;
    // chieu ngang
    for (int i = 1; i <= m; i ++){
        vector<ii> dc; dc.clear();
        char maxC = (char) 90;
        for (int x = i, y = 1; x >= 1 && y <= i; x --, y ++)
            if ( can[x][y] ){
                dc.push_back({x, y});
                maxC = max(maxC, a[x][y]);
            }
        for (auto tmp : dc)
            if ( a[tmp.x][tmp.y] == maxC )
                point[tmp.x+1][tmp.y] = point[tmp.x][tmp.y+1] = 1;
        for (int x = i + 1, y = 1; x >= 1 && y <= i + 1; x --, y ++)
            if ( !point[x][y] ) can[x][y] = 0;
        ans += maxC;
    }
    // chieu doc
    for (int i = 2; i <= n; i ++){
        vector<ii> dc; dc.clear();
        char maxC = (char) 90;
        for (int x = m, y = i; x >= 1 && y <= n; x --, y ++)
            if ( can[x][y] ){
                dc.push_back({x, y});
                maxC = max(maxC, a[x][y]);
            }
        for (auto tmp : dc)
            if ( a[tmp.x][tmp.y] == maxC )
                point[tmp.x+1][tmp.y] = point[tmp.x][tmp.y+1] = 1;
        for (int x = m, y = i + 1; x >= 1 && y <= n; x --, y ++)
            if ( !point[x][y] ) can[x][y] = 0;
        ans += maxC;
    }
    cout << ans;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];
    // solve
    if ( a[1][1] == '#' || a[m][n] == '#' ){
        cout << -1;
        return 0;
    }
    memset(can, 0, sizeof can);
    for (int i = m; i >= 1; i --)
        for (int j = n; j >= 1; j --){
            if ( i == m && j == n ){
                can[i][j] = 1;
                continue;
            }
            if ( a[i][j] == '#' ) continue;
            can[i][j] = can[i+1][j] || can[i][j+1] ;
        }
    if ( !can[1][1] ){
        cout << -1;
        return 0;
    }
    solveMin();
    solveMax();
    return 0;
}
