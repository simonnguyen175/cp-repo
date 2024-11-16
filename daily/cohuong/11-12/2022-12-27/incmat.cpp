#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int m, n, q;
vector<vector<int>> a, b, mxd, mxu;
struct query{
    int x, y, u, v, c;
} que[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("incmat.inp", "r", stdin);
    freopen("incmat.out", "w", stdout);

    cin >> m >> n;
    a.resize(m+2), b.resize(m+2), mxd.resize(m+2), mxu.resize(m+2);
    for (int i = 0; i < m+2; i ++)
        a[i].resize(n+2), b[i].resize(n+2), mxd[i].resize(n+2), mxu[i].resize(n+2);
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    cin >> q;
    for (int i = 1, x, y, u, v, c; i <= q; i ++){
        cin >> x >> y >> u >> v >> c;
        que[i] = {x, y, u, v, c};
        b[x][y] += c, b[u+1][y] -= c, b[x][v+1] -= c, b[u+1][v+1] += c;
    }
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        b[i][j] = b[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        a[i][j] += b[i][j];

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        mxd[i][j] = max({mxd[i-1][j], mxd[i][j-1], a[i][j]});
    for (int i = m; i >= 1; i --)
    for (int j = n; j >= 1; j --)
        mxu[i][j] = max({mxu[i+1][j], mxu[i][j+1], a[i][j]});

    int ans = mxd[m][n];
    for (int i = 1, x, y, u, v, c; i <= q; i ++){
        x = que[i].x, y = que[i].y, u = que[i].u, v = que[i].v, c = que[i].c;
        ans = min(ans, max(max({mxd[x-1][n], mxd[m][y-1], mxu[u+1][y], mxu[x][v+1]}), mxd[m][n]-c));
    }

    cout << ans;

    return 0;
}
