#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, q;
int cell[N][N];

namespace sub1{
    int row[] = {0, 0, 1, -1};
    int col[] = {1, -1, 0, 0};
    int d[N][N];

    void bfs(int u, int v){
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            d[i][j] = -1;

        d[u][v] = 1;
        queue<pi> Q;
        Q.push({u, v});

        while ( Q.size() ){
            int x = Q.front().fi, y = Q.front().se;
            Q.pop();

            for (int i = 0; i <= 3; i ++){
                int nx = x + row[i], ny = y + col[i];
                if ( nx < 1 || nx > n || ny < 1 || ny > n ) continue;
                if ( d[nx][ny] != -1 || cell[nx][ny] ) continue;
                d[nx][ny] = d[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            char x; cin >> x;
            if ( x == '1' ) cell[i][j] = 1;
            else cell[i][j] = 0;
        }

        while ( q -- ){
            int type, u, v, x, y;
            cin >> type;
            if ( type == 1 ){
                cin >> u >> v;
                cell[u][v] = 1;
            }
            else{
                cin >> u >> v >> x >> y;
                if ( cell[u][v] || cell[x][y] ) { cout << -1; continue; }
                bfs(u, v);
                cout << d[x][y] << '\n';
            }
        }
    }
}

namespace sub2{
    int nn = 0;
    int row[] = {0, 0, 1, -1};
    int col[] = {1, -1, 0, 0};
    int id[N][N];
    vector<int> adj[N];
    int p[N*N][22], h[N*N];

    void dfs(int u, int pu){
        for (int v : adj[u]){
            if ( v == pu ) continue;
            p[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int u, int v){
        if ( h[u] < h[v] ) swap(u, v);

        for (int i = 20; i >= 0; i --)
            if ( h[p[u][i]] >= h[v] ) u = p[u][i];

        if ( u == v ) return u;

        for (int i = 20; i >= 0; i --)
            if ( p[u][i] != p[v][i] )
                u = p[u][i], v = p[v][i];

        return p[u][0];
    }

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            char x; cin >> x;
            if ( x == '1' ) cell[i][j] = 1;
            else cell[i][j] = 0;

            if ( !cell[i][j] ) id[i][j] = ++ nn;
        }


        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) if ( !cell[i][j] ){
            for (int k = 0; k <= 3; k ++){
                int x = i + row[k], y = j + col[k];
                if ( x < 1 || x > n || y < 1 || y > n ) continue;
                if ( !cell[x][y] ) adj[id[i][j]].pb(id[x][y]);
            }
        }

        dfs(1, 0);

        for (int i = 1; i <= 20; i ++)
        for (int u = 1; u <= nn; u ++)
            p[u][i] = p[p[u][i-1]][i-1];

        while ( q -- ){
            int type, u, v, x, y;
            cin >> type >> u >> v >> x >> y;
            if ( cell[u][v] || cell[x][y] ) { cout << -1; continue; }
            int s = id[u][v], f = id[x][y];
            cout << h[s] + h[f] - 2*h[lca(s, f)] + 1 << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("maze.inp", "r") ){
        freopen("maze.inp", "r", stdin);
        freopen("maze.out", "w", stdout);
    }

    cin >> n >> q;
//    if ( n <= 100 && q <= 100 ) sub1::solve();
////    else
        sub2::solve();

    return 0;
}
