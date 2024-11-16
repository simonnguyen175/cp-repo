#include<bits/stdc++.h>
#define pi pair<int, int>
#define pii pair<int, pi>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e2 + 5;
const int row[] = {1, 0, -1, 0};
const int col[] = {0, 1, 0, -1};

int m, n, timeDfs = 0, scc = 0;
int id[N][N];
char cell[N][N];
pii a[N*N];
vector<int> adj[N*N], adje[N*N];
int num[N*N], low[N*N], val[N*N], root[N*N];
stack<int> cont;
bool del[N*N];
int f[N*N];

void dfs(int u){
    low[u] = num[u] = ++timeDfs;
    cont.push(u);

    for (int v : adj[u]){
        if ( del[v] ) continue;
        if ( !num[v] ){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }else low[u] = min(low[u], num[v]);
    }


    if ( low[u] == num[u] ){
        scc ++; int v;
        do{
            v = cont.top();
            val[scc] += a[v].fi;
            root[v] = scc;
            del[v] = 1;
            cont.pop();
        }while ( v != u );
    }
}

void init(){
    cin >> m >> n;
    int cnt = 0;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> cell[i][j];
        id[i][j] = ++cnt;
        if ( cell[i][j] >= '0' && cell[i][j] <= '9' )
            a[cnt] = {cell[i][j]-'0', {i, j}};
        else
            a[cnt] = {0, {i, j}};
    }

    for (int i = 1; i <= m*n; i ++){
        int x = a[i].se.fi, y = a[i].se.se;
        if ( cell[x][y] == '#' ) continue;
        if ( cell[x][y] == 'N' ){
            for (int k = 0; k < 3; k ++){
                int nx = x + row[k], ny = y + col[k];
                if ( nx < 1 || nx > m || ny < 1 || ny > n ) continue;
                adj[i].pb(id[nx][ny]);
            }
        }
        else
        if ( cell[x][y] == 'W' ){
            for (int k = 0; k < 4; k ++){
                if ( k == 2 ) continue;
                int nx = x + row[k], ny = y + col[k];
                if ( nx < 1 || nx > m || ny < 1 || ny > n ) continue;
                adj[i].pb(id[nx][ny]);
            }
        }
        else{
            for (int k = 0; k < 2; k ++){
                int nx = x + row[k], ny = y + col[k];
                if ( nx < 1 || nx > m || ny < 1 || ny > n ) continue;
                adj[i].pb(id[nx][ny]);
            }
        }
    }
}

int calc(int u){
    if ( adje[u].size() == 0 ) return val[u];
    if ( f[u] != -1 ) return f[u];
    int res = 0;
    for (int v : adje[u]) res = max(res, val[u] + calc(v));
    f[u] = res;
    return res;
}

void solve(){
    memset(num, 0, sizeof num);
    memset(del, 0, sizeof del);

    for (int i = 1; i <= m*n; i ++)
        if ( !num[i] ) dfs(i);

    for (int u = 1; u <= m*n; u ++){
        int ru = root[u];
        for (int v : adj[u]){
            int rv = root[v];
            if ( ru != rv ) adje[ru].pb(rv);
        }
    }

    memset(f, -1, sizeof f);

    cout << calc(root[1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    init();
    solve();

    return 0;
}
