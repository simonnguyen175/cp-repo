#include<bits/stdc++.h>
using namespace std;

namespace sub1{
    int base = m + n;
    int trace[1005][1005][2*1005];
    struct node{
        int x, y, delta;
    };

    void solve(){
        cin >> x >> y >> u >> v;
        queue<node> q;
        q.push({x, y, base});
        while ( q.size() ){
            int x = q.front().x, y = q.front().y, delta = q.front().delta;
            q.pop();

            for (int i = 0; i <= 3; i ++){
                int nx = x + row[i], ny = y + col[i];
                if ( !inside(nx, ny) ) continue;
                int ndelta = delta + a[nx][ny];
                if ( ndelta < 0 || ndelta > 2*(m+n) ) continue;
                trace[nx][ny][ndelta] = {x, y};
            }
        }

        int curd = base;
        if ( !trace[u][v][curd].fi ) { cout << -1; return; }

        vector<char> ans;
        while ( trace[u][v][curd].fi ){

        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        char x;
        cin >> x
        if ( x == 'W' ) a[i][j] = 1;
        else a[i][j] = -1;
    }

    cin >> q;
    while ( q -- )
        solve();

    return 0;
}
