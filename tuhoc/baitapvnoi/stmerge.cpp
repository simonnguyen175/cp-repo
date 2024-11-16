#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e15;

int q, m, n;
ll c[N][N], f[N][N][2];

void solve(){
    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> c[i][j];

    for (int i = 0; i <= m; i ++)
    for (int j = 0; j <= n; j ++)
        f[i][j][0] = f[i][j][1] = oo;

    for (int i = 1; i <= m; i ++) f[i][0][0] = 0;
    for (int j = 1; j <= n; j ++) f[0][j][1] = 0;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1] + c[i][j]);
        f[i][j][1] = min(f[i][j-1][1], f[i][j-1][0] + c[i][j]);
    }

    cout << min(f[m][n][0], f[m][n][1]) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> q;
    while ( q -- )
        solve();

    return 0;
}
