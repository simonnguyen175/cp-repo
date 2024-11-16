#include <bits/stdc++.h>
#define ii      pair<int, int>
using namespace std;
const int N = 1e3 + 3;
int m, n;
char cell[N][N];
int floodTime[N][N], visitTime[N][N];
queue<ii> Q;
ii startCell, finishCell;

int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };

void firstBFS() {
    memset(floodTime, 0x3f, sizeof floodTime);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (cell[i][j] == '*') {
                floodTime[i][j] = 0;
                Q.push({ i, j });
            }
        }
    }

    while (Q.size()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        int value = floodTime[x][y];
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + row[dir], ny = y + col[dir];
            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
            if (cell[nx][ny] != '.' || floodTime[nx][ny] <= value + 1) continue;
            floodTime[nx][ny] = value + 1;
            Q.push({ nx, ny });
        }
    }
}

void secondBFS() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (cell[i][j] == 'S') startCell = { i, j };
            if (cell[i][j] == 'D') finishCell = { i, j };
        }
    }

    memset(visitTime, 0x3f, sizeof visitTime);
    visitTime[startCell.first][startCell.second] = 0;
    Q.push(startCell);
    while (Q.size()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        int value = visitTime[x][y];
        if (finishCell == ii(x, y)) {
            cout << value;
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + row[dir], ny = y + col[dir];
            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
            if (cell[nx][ny] != '.' && cell[nx][ny] != 'D' || visitTime[nx][ny] <= value + 1) continue;
            if (floodTime[nx][ny] <= value + 1) continue; // it will be flooded, can't move on
            visitTime[nx][ny] = value + 1;
            Q.push({ nx, ny });
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("trash.inp", "r")) {
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++) {
            cell[i][j] = s[j - 1];
        }
    }
    // first bfs, find shortest time for water to reach cells
    firstBFS();
    // second bfs, check if we can move from S to D
    secondBFS();
}
