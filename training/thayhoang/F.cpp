#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;

int n, m, q;
struct query{
    int x, y, u, v, id;
};
char a[N][N];
bitset<N> f[N][N], g[N][N];
bool ans[N*N];

void solve(int l, int r, vector<query> &Q){
    int mid = l + r >> 1;

    /// f[i][j][mid] tu i j den cac o hang mid
    /// g[i][j][mid] tu hang mid den cac o i j

    for (int i = l; i <= r; i ++)
    for (int j = 1; j <= m; j ++)
        f[i][j].reset(), g[i][j].reset();

    for (int i = 1; i <= m; i ++) if ( a[mid][i] == '.' )
        f[mid][i][i] = g[mid][i][i] =  1;

    for (int i = mid; i >= l; i --)
    for (int j = m; j >= 1; j --) if ( a[i][j] == '.' ){
        if ( i + 1 <= mid ) f[i][j] |= f[i+1][j];
        if ( j + 1 <= m ) f[i][j] |= f[i][j+1];
    }

    for (int i = mid; i <= r; i ++)
    for (int j = 1; j <= m; j ++) if ( a[i][j] == '.' ){
        if ( i - 1 >= mid ) g[i][j] |= g[i-1][j];
        if ( j ) g[i][j] |= g[i][j-1];
    }

//    cout << mid << " : \n";
    vector<query> L, R;
    for (auto it : Q){
        int x = it.x, y = it.y, u = it.u, v = it.v;

        if ( x <= mid && u >= mid ){
            ans[it.id] = (f[x][y] & g[u][v]).any();
            continue;
        }

        if ( u < mid ) L.pb(it);
        if ( x > mid ) R.pb(it);
    }

    if ( l <= mid - 1 ) solve(l, mid - 1, L);
    if ( mid + 1 <= r ) solve(mid + 1, r, R);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];

    vector<query> sta;
    for (int i = 1; i <= q; i ++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        sta.pb({x, y, u, v, i});
    }
    solve(1, n, sta);

    for (int i = 1; i <= q; i ++)
        if ( ans[i] ) cout << "YES\n";
        else cout << "NO\n";

    return 0;
}
