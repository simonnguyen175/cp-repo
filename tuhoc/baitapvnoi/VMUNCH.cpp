#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>

int r, c;
char cell[101][101];
queue<pair<int,int>> Q;
int VisitTime[101][101];
int row[] = { -1, 1, 0, 0 };
int col[] = { 0, 0, -1, 1 };


void BFS(){
    pair<int, int> StartCell, FinishCell;
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++){
            if ( cell[i][j] == 'C' ) StartCell={i, j};
            if ( cell[i][j] == 'B' ) FinishCell={i, j};
        }
    memset(VisitTime, 0x3f, sizeof VisitTime);
    VisitTime[StartCell.first][StartCell.second]=0;
    Q.push(StartCell);
    while ( !Q.empty() ){
        int x=Q.front().first, y=Q.front().second;
        Q.pop();
        int value=VisitTime[x][y];
        if ( FinishCell == ii(x, y) ){
            cout << value;
            return;
        }
        for (int  i=0; i<=3; i++){
            int tx=x+row[i], ty=y+col[i];
            if ( tx < 1 ||  ty < 1 || tx > r || ty > c ) continue;
            if ( cell[tx][ty] != '.' && cell[tx][ty] != 'B' || VisitTime[tx][ty] <= value+1) continue;
            VisitTime[tx][ty]=value+1;
            Q.push({tx, ty});
        }
    }
}

int main(){
    cin >> r >> c;
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)
            cin >> cell[i][j];
    BFS();
    return 0;
}
