#include<bits/stdc++.h>
#define simon "fair"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int, pair<int, int>>
#define fi first
#define se second
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int m, n;
int a[N][N], d[N][N];
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    // dijkstra
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            d[i][j] = oo;
    for (int i = 1; i <= m; i ++){
        d[i][1] = 1;
        heap.push({d[i][1],{i, 1}});
    }

    while ( heap.size() ){
        int du = heap.top().fi, x = heap.top().se.fi, y = heap.top().se.se;
        heap.pop();

        for (int i = 0; i < 4; i ++){
            int nx = x + row[i], ny = y + col[i], w;
            if ( nx < 1 || nx > m || ny < 1 || ny > n ) continue;
            if ( a[x][y] != a[nx][ny] ) w = 1; else w = 0;
            if ( d[nx][ny] > du + w ){
                d[nx][ny] = du + w;
                heap.push({d[nx][ny],{nx, ny}});
            }
        }
    }

    int ans = oo;
    for (int i = 1; i <= m; i ++)
        ans = min(ans, d[i][n]);

    cout << ans;

    return 0;
}
