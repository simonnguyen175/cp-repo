#include<bits/stdc++.h>
#define pi pair<int, int>
#define x first
#define y second
using namespace std;
const int N = 1e3 + 5;

pi a[N][4*N];
int c[N][N][N];
struct stop{
    int x1, y1, x2, y2, t;
} bus[N];

int main(){
    cin >> w >> h >> Sx >> Sy >> Tx >> Ty;
    memset(c, -1, sizeof c);
    for (int i = 1; i <= n; i ++){
        int x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;

        bus[i] = {x1, y1, x2, y2, t};

        cnt = -1;
		for (int j = x1; j <= x2; j ++) a[i][++cnt] = {j,y1}, c[i][j][y1] = cnt;
		for (int j = y1+1; j <= y2-1; j ++) a[i][++cnt] = {x2,j}, c[i][x2][j] = cnt;
		for (int j = x2; j >= x1; j --) a[i][++cnt] = {j,y2}, c[i][j][y2] = cnt;
		for (int j = y2-1; j >= y1+1; j --) a[i][++cnt] = {x1,j}, c[i][x1][j] = cnt;
    }

    for (int i = 1; i <= n; i ++)
        if ( c[i][Sx][Sy] != -1 ){
            d[Sx][Sy][i] = c[i][Sx][Sy];
            heap.push({d[Sx][Sy][i], i, Sx, Sy});
        }

    while ( heap.size() ){
        int u = heap.top().u, x = heap.top().x, y = heap.top().y;
        int du = heap.top().u;
        heap.pop();

        if ( du != d[u][x][y] ) continue;

        for (int = )
    }
}
