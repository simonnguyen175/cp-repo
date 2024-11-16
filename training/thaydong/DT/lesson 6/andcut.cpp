#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;

int n, m, q;
int a[N][N], f[N][N], g[N][N], row[N][N], col[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        if ( (i-1)&(j-1) ) a[i][j] = 0;
        else a[i][j] = 1;

        f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        g[i][j] = g[i-1][j] + g[i][j-1] - g[i-1][j-1];
        if ( a[i][j] ){
            if ( a[i-1][j] ) g[i][j] ++;
            if ( a[i][j-1] ) g[i][j] ++;
        }
    }

//    for (int i = 1; i <= n; i ++){
//        for (int j = 1; j <= m; j ++)
//            cout << a[i][j] << ' ';
//        cout << '\n';
//    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++){
        row[i][j] = row[i][j-1] + ( a[i-1][j] && a[i][j] );
        col[i][j] = col[i-1][j] + ( a[i][j-1] && a[i][j] );
    }

    while ( q -- ){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 ++, y1 ++, x2 ++, y2 ++;
        int ver = f[x2][y2] - f[x1-1][y2] - f[x2][y1-1] + f[x1-1][y1-1];
        int edg = g[x2][y2] - g[x1-1][y2] - g[x2][y1-1] + g[x1-1][y1-1] - ( row[x1][y2] - row[x1][y1-1] ) - ( col[x2][y1] - col[x1-1][y1] );
        cout << ver - edg << '\n';
    }

    return 0;
}
