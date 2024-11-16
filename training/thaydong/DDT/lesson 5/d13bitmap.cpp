#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int m, n, q;
char a[N][N];
int id[N][N], Par[N*N], Size[N*N];

void init(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> m >> n;
    int cnt = 0;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            cin >> a[i][j];
            id[i][j] = ++cnt;
        }
}

bool check(int i, int j){
    return ( i >= 1 && i <= m && j >= 1 && j <= n && a[i][j] == '1' );
}

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u); v = Find(v);

    if ( u != v ){
        if ( Size[u] < Size[v] ) swap(u, v);
        Par[v] = u;
        Size[u] += Size[v];
    }
    return;
}

void solve(){
    for (int i = 1; i <= n*m; i ++) Par[i] = i, Size[i] = 1;

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            if ( a[i][j] == '1' ){
                if ( check(i+1, j) ) Join(id[i][j], id[i+1][j]);
                if ( check(i, j+1) ) Join(id[i][j], id[i][j+1]);
            }

    int mx = 0;
    for (int i = 1; i <= n*m; i ++) mx = max(mx, Size[i]);

    cin >> q;
    for (int i = 1; i <= q; i ++){
        int x, y;
        cin >> x >> y;
        a[x][y] = '1';
        if ( check(x+1, y) ) Join(id[x][y], id[x+1][y]);
        if ( check(x, y+1) ) Join(id[x][y], id[x][y+1]);
        if ( check(x-1, y) ) Join(id[x][y], id[x-1][y]);
        if ( check(x, y-1) ) Join(id[x][y], id[x][y-1]);
        int root = Find(id[x][y]);
        mx = max(mx, Size[root]);
        cout << mx << '\n';
    }

}

int main(){
    init();
    solve();
    return 0;
}
