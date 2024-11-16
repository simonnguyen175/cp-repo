#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e3 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int n;
int a[N][N], deg[N][N], d[N][N];

bool inside(int x, int y){
    return ( x >= 1 && x <= n && y >= 1 && y <= n );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        char x;
        cin >> x;
        a[i][j] = x - '0';
        deg[i][j] = 2;
    }

    queue<pi> q;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++) if ( !a[i][j] ){
        deg[i][j] = 0;
        d[i][j] = 0;
        q.push({i, j});
    }

    while ( q.size() ){
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for (int i = 0; i <= 3; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( inside(nx, ny) && deg[nx][ny] ){
                deg[nx][ny] --;
                if ( !deg[nx][ny] ){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        ans = max(ans, d[i][j]);

    cout << ans;

    return 0;
}
