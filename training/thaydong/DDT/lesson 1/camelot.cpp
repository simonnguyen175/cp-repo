#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

int n;
char cell[105][105];
pair<int, int> king;
vector<pair<int, int>> horse;
queue<pair<pair<int,int>, int>> q;
bool vis[105][105][2];
int d[10][100][100][2];
const int rk[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ck[] = {1, -1, 0, 0, 1, -1, -1, 1};
const int rh[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int ch[] = {2, -2, 2, -2, 1, -1, 1, -1};

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            cin >> cell[i][j];
            if ( cell[i][j] == 'T' ) king = {i, j};
            if ( cell[i][j] == 'M' ) horse.push_back({i, j});
        }

    // kingmove
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
    for (int k = 1; k <= 1 + horse.size(); k ++)
        d[k][i][j][1] = d[k][i][j][0] = INT_MAX;

    memset(vis, 0, sizeof vis);
    vis[king.fi][king.se][0] = 1;
    d[1][king.fi][king.se][0] = 0;
    q.push({{king.fi, king.se},0});

    while ( !q.empty() ){
        int x = q.front().fi.fi, y = q.front().fi.se;
        int tt = q.front().se;
        q.pop();

        for (int i = 0; i < 8; i ++){
            int nx = x + rk[i], ny = y + ck[i], ntt = 1 - tt;
            if ( nx < 1 || ny < 1 || nx > n || ny > n ) continue;
            if ( vis[nx][ny][ntt] || cell[nx][ny] == '#' ) continue;

            d[1][nx][ny][ntt] = d[1][x][y][tt] + 1;
            vis[nx][ny][ntt] = 1;

            q.push({{nx, ny}, ntt});
        }
    }


    for (int i = 0; i < horse.size(); i ++){
        memset(vis, 0, sizeof vis);
        vis[horse[i].fi][horse[i].se][0] = 1;
        d[i+2][horse[i].fi][horse[i].se][0] = 0;
        q.push({{horse[i].fi, horse[i].se}, 0});

        while ( !q.empty() ){
            int x = q.front().fi.fi, y = q.front().fi.se;
            int tt = q.front().se;
            q.pop();

            for (int j = 0; j < 8; j ++){
                int nx = x + rh[j], ny = y + ch[j], ntt = 1 - tt;
                if ( nx < 1 || ny < 1 || nx > n || ny > n ) continue;
                if ( vis[nx][ny][ntt] || cell[nx][ny] == '#' ) continue;

                d[i+2][nx][ny][ntt] = d[i+2][x][y][tt] + 1;
                vis[nx][ny][ntt] = 1;

                q.push({{nx, ny}, ntt});
            }
        }
    }

    int ans = INT_MAX;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int t = 0; t <= 1; t ++){
                int res = 0;
                for (int k = 1; k <= 1 + horse.size(); k ++){
                    //cout << k << ' ' << i << ' ' << j << ' ' << t << ' ' << d[k][i][j][t] << "   ";
                    res = max(res, d[k][i][j][t]);
                }
                ans = min(ans, res);
                //cout << '\n';
            }

    if ( ans == INT_MAX ) cout << -1;
    else cout << ans;

    return 0;
}
