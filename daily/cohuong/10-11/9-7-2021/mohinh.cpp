#include <bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<long long, pi>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int m, n;
long long a[N][N], h[N][N];
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("mohinh.inp", "r") ){
        freopen("mohinh.inp", "r", stdin);
        freopen("mohinh.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    priority_queue<pii, vector<pii>, greater<pii>> heap;

    memset(h, 0x3f3f3f, sizeof h);

    for (int i = 1; i <= m; i ++){
        h[i][1] = a[i][1]; h[i][n] = a[i][n];
        heap.push({h[i][1], {i, 1}});
        heap.push({h[i][n], {i, n}});
    }

    for (int i = 1; i <= n; i ++){
        h[1][i] = a[1][i]; h[m][i] = a[m][i];
        heap.push({h[1][i], {1, i}});
        heap.push({h[m][i], {m, i}});
    }

    while ( heap.size() ){
        int x = heap.top().se.fi, y = heap.top().se.se;
        long long du = heap.top().fi;
        heap.pop();
        if ( du != h[x][y] ) continue;
        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i];
            if ( nx < 1 || nx > m || ny < 1 || ny > n ) continue;
            if ( h[nx][ny] > max(a[nx][ny], h[x][y]) ){
                h[nx][ny] =  max(a[nx][ny], h[x][y]);
                heap.push({h[nx][ny], {nx, ny}});
            }
        }
    }

    long long ans = 0 ;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            if ( h[i][j] > a[i][j] ) ans += h[i][j] - a[i][j];

    cout << ans;

    return 0;
}
