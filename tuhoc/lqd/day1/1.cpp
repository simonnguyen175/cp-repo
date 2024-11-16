#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, t;
int cell[N][N];
struct query{
    int type, u, v, x, y, tt;
};
query q[N*N];

namespace sub3{
    int nn = 0;
    int row[] = {0, 0, 1, -1};
    int col[] = {1, -1, 0, 0};
    int id[N][N];
    vector<int> adj[N*N];
    int p[N*N][22], h[N*N];
    int Par[N*N], Rank[N*N];
    int ans[N*N];

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

    int Find(int u){
        if ( u == Par[u] ) return u;
        else return Par[u] = Find(Par[u]);
    }

    void Join(int u, int v){
        u = Find(u); v = Find(v);
        if ( u != v ){
            if ( Rank[u] < Rank[v] ) swap(u, v);
            Par[v] = u;
            if ( Rank[u] == Rank[v] ) Rank[u] ++;
        }
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

        for (int i = 1; i <= t; i ++){
            cin >> q[i].type;
            if ( q[i].type == 1 ){
                cin >> q[i].u >> q[i].v;
                if ( cell[q[i].u][q[i].v] == 1 ) q[i].tt = 0;
                else q[i].tt = 1, cell[q[i].u][q[i].v] = 1;
            }
            else cin >> q[i].u >> q[i].v >> q[i].x >> q[i].y;
        }

        for (int i = 1; i <= nn; i ++)
            Par[i] = i, Rank[i] = 0;

        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) if ( !cell[i][j] ){
            for (int k = 0; k <= 3; k ++){
                int x = i + row[k], y = j + col[k];
                if ( x < 1 || x > n || y < 1 || y > n ) continue;
                if ( cell[x][y] ) continue;
                Join(id[i][j], id[x][y]);
            }
        }

        for (int i = t; i >= 1; i --){
            if ( q[i].type == 1 ){
                if ( !q[i].tt ) continue;

                int u = q[i].u, v = q[i].v;
                cell[u][v] = 0;
                for (int j = 0; j <= 3; j ++){
                    int x = u + row[j], y = v + col[j];
                    if ( x < 1 || x > n || y < 1 || y > n ) continue;
                    if ( cell[x][y] ) continue;
                    Join(id[u][v], id[x][y]);
                }
            }
            else{
                int u = q[i].u, v = q[i].v, x = q[i].x, y = q[i].y;
                if ( Find(id[u][v]) != Find(id[x][y]) ) ans[i] = -1;
                else ans[i] = h[id[u][v]] + h[id[x][y]] - 2 * h[lca(id[x][y], id[u][v])] + 1;
            }
        }

        for (int i = 1; i <= t; i ++) if ( q[i].type == 2 ) cout << ans[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("1.inp", "r") ){
        freopen("1.inp", "r", stdin);
        freopen("1.out", "w", stdout);
    }

    cin >> n >> t;

    sub3::solve();

    return 0;
}
