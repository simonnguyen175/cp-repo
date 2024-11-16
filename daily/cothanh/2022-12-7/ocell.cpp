#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m, q;
vector<vector<int>> a;
int mxr[N], mxc[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("ocell.in", "r", stdin);
    freopen("ocell.out", "w", stdout);

    cin >> n >> m >> q;
    a.resize(n+1);
    a[0].resize(m+1);
    for (int i = 1; i <= n; i ++){
        a[i].resize(m+1);
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        if ( a[i][j] > a[i][mxr[i]] )
            mxr[i] = j;

    for (int j = 1; j <= m; j ++)
    for (int i = 1; i <= n; i ++)
        if ( a[i][j] > a[mxc[j]][j] )
            mxc[j] = i;

    int ans = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        if ( mxr[i] == j && mxc[j] == i )
            ans ++;

    while ( q -- ){
        int x, y, v;
        cin >> x >> y >> v;

        a[x][y] = v;
        if ( mxr[x] == y && mxc[y] == x ){
            cout << ans << '\n';
            continue;
        }

        if ( y != mxr[x] && v > a[x][mxr[x]] ){
            if ( mxc[mxr[x]] == x ) ans --;
            mxr[x] = y;
        }

        if ( x != mxc[y] && v > a[mxc[y]][y] ){
            if ( mxr[mxc[y]] == y ) ans --;
            mxc[y] = x;
        }

        if ( mxr[x] == y && mxc[y] == x )
            ans ++;

        cout << ans << '\n';
    }

    return 0;
}
