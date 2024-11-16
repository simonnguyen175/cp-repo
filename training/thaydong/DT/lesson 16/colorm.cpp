#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 100;

int m, n, ck1;
vector<int> g[N];
int a[N][N], vis[N], col[N];

void dfs(int u){
    vis[u] = 1;

    for (int v : g[u]){
        if ( col[v] == -1 ) col[v] = col[u] ^ 1;
        else if ( col[v] == col[u] ) { ck1 = 0; return; }

        if ( !vis[v] ) dfs(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n;
    bool ck = 1;
    memset(col, -1, sizeof col);
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];

        if ( a[i][j] == 1 || a[i][j] == 2 ){
            if ( col[i] == -1 ) col[i] = a[i][j] - 1;
            else if ( col[i] != a[i][j] - 1 ) return cout << 0, 0;

            if ( col[m+j] == -1 ) col[m+j] = a[i][j] - 1;
            else if ( col[m+j] != a[i][j] - 1 ) return cout << 0, 0;
        }

        if ( a[i][j] == 3 ){
            g[i].pb(m+j);
            g[m+j].pb(i);
        }

        ck &= (a[i][j] == 3 || a[i][j] == 0);
    }

    for (int i = 1; i <= m + n; i ++) if ( !vis[i] && col[i] != -1 ){
        ck1 = 1;
        dfs(i);
        if ( !ck1 ) return cout << 0, 0;
    }

    int cnt = 0;
    for (int i = 1; i <= m + n; i ++) if ( !vis[i] ){
        ck1 = 1;
        cnt ++;
        dfs(i);
        if ( !ck1 ) return cout << 0, 0;
    }

    cout << (1ll << cnt) - ck;

    return 0;
}
