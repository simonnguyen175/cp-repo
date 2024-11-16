#include<bits/stdc++.h>
#define pb push_back
#define simon "listab"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int m, n, ans = 0;
struct cell{
    int val, x, y;
    bool operator < (const cell &a) const{
        return val < a.val;
    }
};
vector<cell> cells;
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n;
    int a[m+5][n+5], f[m+5][n+5];

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            cin >> a[i][j];
            cells.pb({a[i][j], i, j});
        }

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            f[i][j] = 1;

    sort(cells.begin(), cells.end());

    for (int i = 0; i < cells.size(); i ++){
        int val = cells[i].val, x = cells[i].x, y = cells[i].y;
        ans = max(ans, f[x][y]);
        for (int j = 0; j <= 3; j ++){
            int nx = x + row[j], ny = y + col[j];
            if ( a[nx][ny] > a[x][y] )
            f[nx][ny] = max(f[nx][ny], f[x][y] + 1);
        }
    }

    cout << ans;

    return 0;
}
