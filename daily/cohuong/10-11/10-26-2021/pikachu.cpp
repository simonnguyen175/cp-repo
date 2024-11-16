#include<bits/stdc++.h>
#define simon "pikachu"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 55;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n, len, ans = 0;
char a[N][N];
int id[N][N], vis[N*N][N*N];
pi l[N][N], r[N][N], u[N][N], d[N][N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n >> len;

    int tt = 0;
    for (int i = 1; i <= m + 2; i ++)
    for (int j = 1; j <= n + 2; j ++)
        a[i][j] = '.', id[i][j] = ++tt;

    m ++; n ++;
    for (int i = 2; i <= m; i ++)
    for (int j = 2; j <= n; j ++)
        cin >> a[i][j];
    m ++; n ++;

    /*
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= n; j ++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    */


    for (int i = 2; i < m; i ++)
    for (int j = 2; j < n; j ++) if ( a[i][j] != '.' ) {
        for (int k = 0; k < 4; k ++){
            int x = i + row[k], y = j + col[k];
            if ( a[x][y] == a[i][j] && !vis[id[x][y]][id[i][j]] ){
                ans ++; vis[id[x][y]][id[i][j]] = vis[id[i][j]][id[x][y]] = 1;
            }
        }
    }

    //cout << ans << '\n';

    if ( len == 0 ){
        cout << ans;
        return 0;
    }

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( a[i][j] == '.' ){
        // make u, d
        for (int k = i; k >= 1; k --) if ( a[k][j] != '.' ) { u[i][j] = {k, j}; break; }
        for (int k = i; k <= m; k ++) if ( a[k][j] != '.' ) { d[i][j] = {k, j}; break; }


        // make l, r
        for (int k = j; k >= 1; k --) if ( a[i][k] != '.' ) { l[i][j] = {i, k}; break; }
        for (int k = j; k <= n; k ++) if ( a[i][k] != '.' ) { r[i][j] = {i, k}; break; }
    }

    vector<pi> cont;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++) if ( a[i][j] == '.' ){
        // canh doc
        //cout << " make doc " << '\n';
        for (int k = i; k <= m; k ++){
            if ( a[k][j] != '.' ) break;
            cont.clear();

            if ( l[i][j].fi != 0 ) cont.pb(l[i][j]);
            if ( r[i][j].fi != 0 ) cont.pb(r[i][j]);
            if ( u[i][j].fi != 0 ) cont.pb(u[i][j]);
            if ( d[i][j].fi != 0 ) cont.pb(d[i][j]);
            if ( k != i ){
                if ( l[k][j].fi != 0 ) cont.pb(l[k][j]);
                if ( r[k][j].fi != 0 ) cont.pb(r[k][j]);
                if ( u[k][j].fi != 0 ) cont.pb(u[k][j]);
                if ( d[k][j].fi != 0 ) cont.pb(d[k][j]);
            }

            /*
            cout << i << ' ' << j << ' ' << " and " << k << ' ' << j << '\n';
            for (int x = 0; x < cont.size(); x ++){
                int ux = cont[x].fi, uy = cont[x].se;
                cout << a[ux][uy] << ' ';
            }
            cout << '\n';
            */

            for (int x = 0; x < cont.size(); x ++)
            for (int y = x + 1; y < cont.size(); y ++){
                int ux = cont[x].fi, uy = cont[x].se;
                int vx = cont[y].fi, vy = cont[y].se;

                //cout << ux << ' ' << uy << ' ' << vx << ' ' << vy << '\n';

                if ( vis[id[ux][uy]][id[vx][vy]] || a[ux][uy] != a[vx][vy] || id[ux][uy] == id[vx][vy] ) continue;
                if ( len == 3 )
                    ans ++, vis[id[ux][uy]][id[vx][vy]] = vis[id[vx][vy]][id[ux][uy]] = 1;
                else if ( len == 2 ){
                    if ( uy == vy && uy != j ) continue;
                    if ( uy != vy && uy != j && vy != j && ux != vx ) continue;
                    ans ++; vis[id[ux][uy]][id[vx][vy]] = vis[id[vx][vy]][id[ux][uy]] = 1;
                }
                else if ( uy == vy && uy == j ){
                    ans ++; vis[id[ux][uy]][id[vx][vy]] = vis[id[vx][vy]][id[ux][uy]] = 1;
                }
            }
            //cout << ans << '\n';
        }

        //cout << " make ngang " << '\n';
        // canh ngang
        for (int k = j; k <= n; k ++){
            if ( a[i][k] != '.' ) break;
            cont.clear();

            if ( l[i][j].fi != 0 ) cont.pb(l[i][j]);
            if ( r[i][j].fi != 0 ) cont.pb(r[i][j]);
            if ( u[i][j].fi != 0 ) cont.pb(u[i][j]);
            if ( d[i][j].fi != 0 ) cont.pb(d[i][j]);
            if ( k != j ){
                if ( l[i][k].fi != 0 ) cont.pb(l[i][k]);
                if ( r[i][k].fi != 0 ) cont.pb(r[i][k]);
                if ( u[i][k].fi != 0 ) cont.pb(u[i][k]);
                if ( d[i][k].fi != 0 ) cont.pb(d[i][k]);
            }

            /*
            cout << i << ' ' << j << ' ' << " and " << i << ' ' << k << '\n';
            for (int x = 0; x < cont.size(); x ++){
                int ux = cont[x].fi, uy = cont[x].se;
                cout << a[ux][uy] << ' ';
            }
            cout << '\n';
            */

            for (int x = 0; x < cont.size(); x ++)
            for (int y = x + 1; y < cont.size(); y ++){
                int ux = cont[x].fi, uy = cont[x].se;
                int vx = cont[y].fi, vy = cont[y].se;

                //cout << ux << ' ' << uy << ' ' << vx << ' ' << vy << '\n';

                if ( vis[id[ux][uy]][id[vx][vy]] || a[ux][uy] != a[vx][vy] || id[ux][uy] == id[vx][vy] ) continue;
                if ( len == 3 )
                    ans ++, vis[id[ux][uy]][id[vx][vy]] = vis[id[vx][vy]][id[ux][uy]] = 1;
                else if ( len == 2 ){
                    if ( ux == vx && ux != i ) continue;
                    if ( ux != vx && ux != i && vx != i && uy != vy ) continue;
                    ans ++; vis[id[ux][uy]][id[vx][vy]] = vis[id[vx][vy]][id[ux][uy]] = 1;
                }
                else if ( ux == vx && ux == i ){
                        ans ++; vis[id[ux][uy]][id[vx][vy]] = vis[id[vx][vy]][id[ux][uy]] = 1;
                }
            }
            //cout << ans << '\n';
        }
    }

    cout << ans;

    return 0;
}
