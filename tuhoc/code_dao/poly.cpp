#include<bits/stdc++.h>
using namespace std;

int m, n, ans = 0;
int f[500][500];

int main(){
    cin >> m;
    for (int i = 1; i <= m; i ++){
        cin >> n;
        int x = 500, y = 500, u = -500, v = -500;
        for (int j = 1; j <= n; j ++){
            int xx, yy;
            cin >> xx >> yy;
            x = min(x, xx);
            y = min(y, yy);
            u = max(u, xx);
            v = max(v, yy);
        }

        x += 102, y += 102;
        u += 101, v += 101;

        f[x][y] ++; f[x][v+1] --; f[u+1][y] --; f[u+1][v+1] ++;
    }

    for (int i = 1; i <= 205; i ++)
    for (int j = 1; j <= 205; j ++){
        f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
        if ( f[i][j] > 0 ) ans ++;
    }

    cout << ans;

    return 0;
}
