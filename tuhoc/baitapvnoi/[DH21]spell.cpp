#include<bits/stdc++.h>
using namespace std;
const int N = 305;
const int oo = 1e9;

int m, n, k;
char s[N], a[N][N];
int dp[N][N][N];
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

struct opt{
    int x, y, len;
};

bool check(int x, int y){
    for (int i = 0; i < 4; i ++)
        if ( a[x+row[i]][y+col[i]] == s[1] ) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    if ( fopen("[DH21]spell.inp", "r") ){
        freopen("[DH21]spell.inp", "r", stdin);
        freopen("[DH21]spell.out", "w", stdout);
    }

    cin >> m >> n >> k;

    for (int i = 1; i <= k; i ++)
        cin >> s[i];

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    queue<opt> q;

    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            if ( a[i][j] == s[1] ) continue;
            if ( !check(i, j) ) continue;
            q.push({i, j, 0});
            dp[0][i][j] = 0;
        }

    while ( !q.empty() ){
        int x = q.front().x, y = q.front().y, len = q.front().len;

        q.pop();

        if ( len == k ){
            cout << dp[len][x][y];
            return 0;
        }

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];

            if ( nx < 1 || nx > m || ny < 1 || ny > n ) continue;

            if ( a[nx][ny] == s[len+1] && dp[len+1][nx][ny] == -1 ){
                dp[len+1][nx][ny] = dp[len][x][y] + 1;
                q.push({nx, ny, len+1});
            }
            else if ( dp[len][nx][ny] == -1 ){
                dp[len][nx][ny] = dp[len][x][y] + 1;
                q.push({nx, ny, len});
            }
        }
    }

    return 0;
}
