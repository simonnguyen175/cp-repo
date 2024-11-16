#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
const int N = 40;

int m, n, k;
char a[N][N];
int id[N][N], assigned[N*N], vis[N*N], t;
vector<int> adj[N*N];

void init(){
    cin >> m >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            cin >> a[i][j];
            id[i][j] = ++cnt;
        }
}

bool visit(int u){
    if ( vis[u] != t ) vis[u] = t;
    else return false;

    for (auto v : adj[u]){
        if ( !assigned[v] || visit(assigned[v]) ){
            assigned[v] = u;
            return true;
        }
    }

    return false;
}

bool Empty(int i, int j, int x, int y, int len){
    return ( i >= 1 && i <= m && j >= 1 && j <= n
            && ( i > x+len-1 || i < x || j < y || j > y+len-1 ) && a[i][j] != '#' );
}

bool checkK(int x, int y, int len){
    bool flag = 1;
    FOR(i, x, x+len-1) FOR(j, y, y+len-1)
        if ( a[i][j] == '#' ) {flag = 0; break;}
    if ( !flag ) return false;

    FOR(i, 1, m) FOR(j, 1, n) adj[id[i][j]].clear();

    FOR(i, 1, m) FOR(j, 1, n)
        if ( (i+j)%2 == 1 && Empty(i, j, x, y, len) ){
            if ( Empty(i+1, j, x, y, len) ) adj[id[i][j]].pb(id[i+1][j]);
            if ( Empty(i, j+1, x, y, len) ) adj[id[i][j]].pb(id[i][j+1]);
            if ( Empty(i-1, j, x, y, len) ) adj[id[i][j]].pb(id[i-1][j]);
            if ( Empty(i, j-1, x, y, len) ) adj[id[i][j]].pb(id[i][j-1]);
        }

    memset(assigned, 0, sizeof assigned);
    memset(vis, 0, sizeof vis);

    int cnt = 0;

    t = 0;
    FOR(i, 1, m) FOR(j, 1, n)
        if ( (i+j)%2 == 1 && Empty(i, j, x, y, len) ){
            int u = id[i][j];
            t ++;
            cnt += visit(u);
            if ( cnt >= k ) return true;
        }

    if ( cnt >= k ) return true;
    return false;
}

bool checkLen(int len){
    FOR(i, 1, m-len+1)
    FOR(j, 1, n-len+1)
        if ( checkK(i, j, len) ) return true;
    return false;
}

void solve(){
    int d = 1, c = min(m, n), res = 0;
    while ( d <= c ){
        int mid = ( d + c ) / 2;
        if ( checkLen(mid) ){
            res = mid;
            d = mid + 1;
        }
        else c = mid - 1;
    }
    cout << res << '\n';
}

int main(){
    init();
    solve();
    return 0;
}
