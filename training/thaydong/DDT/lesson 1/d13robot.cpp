#include<bits/stdc++.h>
using namespace std;

struct opt{
    int a, b, c, d;
    string way;
};

int n, m, a, b, c, d;
bool cell[205][205], vis[205][205];
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};
const char mov[] = {'R', 'L', 'D', 'U'};

int main(){
    cin >> n >> m >> a >> b >> c >> d;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> cell[i][j];

    queue<opt> q;
    vis[a+1][b+1] = 1;
    q.push({a+1, b+1, c+1, d+1, ""});

    while ( !q.empty() ){
        a = q.front().a; b = q.front().b;
        c = q.front().c; d = q.front().d;
        string way = q.front().way;
        q.pop();

        if ( a == 1 && b == 1 && c == 1 && d == 1 ){
            cout << way.size() << '\n' << way;
            return 0;
        }

        if ( a == 1 && b == 1 ){
            swap(a, c); swap(b, d);
            memset(vis, 0, sizeof vis);
            vis[a][b] = 1;
        }

        for (int i = 0; i < 4; i ++){
            int na = a + row[i], nb = b + col[i];
            int nc = c + row[i], nd = d + col[i];

            if ( na > n ) na = n; if ( nb > m ) nb = m;
            if ( na < 1 ) na = 1; if ( nb < 1 ) nb = 1;
            if ( cell[na][nb] ) na = a, nb = b;

            if ( nc > n ) nc = n; if ( nd > m ) nd = m;
            if ( nc < 1 ) nc = 1; if ( nd < 1 ) nd = 1;
            if ( cell[nc][nd] ) nc = c, nd = d;

            if ( vis[na][nb] ) continue;

            string nway = way + mov[i];
            vis[na][nb] = 1;

            q.push({na, nb, nc, nd, nway});
        }
    }
}
