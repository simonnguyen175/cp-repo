#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;
const int oo = 1e9;

int m, n, k;
vector<vector<int>> a, s;
vector<vector<pi>> swi;
int ans = oo;

void upd(int x, int y, int u, int v, int del){
    s[x][y] += del, s[x][v+1] -= del, s[u+1][y] -= del, s[u+1][v+1] += del;
}

void solve(int c){
//    cout << c << " : \n";

    int res = 0;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        s[i][j] = 0;

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        s[i][j] = s[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];

        int cur = ( a[i][j] + s[i][j] ) % 3;
        if ( cur < 0 ) cur += 3;

        int del = ( c - cur + 3 ) % 3;

        if ( del && !swi[i][j].fi ) return;

        res += del;

        if ( swi[i][j].fi ) upd(i, j, swi[i][j].fi, swi[i][j].se, del);
    }

//    cout << "-> " << res << '\n';

    ans = min(ans, res);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("light.inp", "r", stdin);
    freopen("light.out", "w", stdout);

    cin >> m >> n >> k;
    a.resize(m + 2);
    swi.resize(m + 2);
    s.resize(m + 2);
    for (int i = 0; i <= m + 1; i ++)
        a[i].resize(n + 2), swi[i].resize(n + 2), s[i].resize(n + 2);

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= k; i ++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        swi[x][y] = {u, v};
    }

    solve(1);
    solve(2);

    cout << ( ans == oo ? -1 : ans );

    return 0;
}
