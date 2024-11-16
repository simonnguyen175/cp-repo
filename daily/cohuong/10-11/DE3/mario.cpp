#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e3 + 5;
const int row[] = {0, 0, 1, -1};
const int col[] = {1, -1, 0, 0};

int m, n, x, y, t;
int a[N][N];
ll ans = 0;
vector<vector<ll>> f[N];

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("mario.inp", "r") ){
        freopen("mario.inp", "r", stdin);
        freopen("mario.out", "w", stdout);
    }

    cin >> m >> n >> x >> y >> t;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int k = 0; k <= min(m*n, t); k ++){
        f[k].resize(m+2);
        for (int i = 1; i <= m; i ++)
            f[k][i].resize(n+2, -1);
    }

    f[0][x][y] = a[x][y];

    for (int k = 0; k <= min(m*n, t); k ++){
        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++) if ( f[k][i][j] != -1 ){
            int s = 0;
            for (int tt = 0; tt < 4; tt ++){
                int x = i + row[tt], y = j + col[tt];
                if ( inside(x, y) ) s = max(s, a[x][y]);
            }
            s += a[i][j];
            ll tmp = f[k][i][j] + 1LL * (t-k) / 2 * s + ( (t-k) % 2 ? s - a[i][j] : 0 );
            ans = max(ans, tmp);
        }

        if ( k == min(m*n, t) ) break;

        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++) if ( f[k][i][j] != -1 )
        for (int tt = 0; tt < 4; tt ++){
            int x = i + row[tt], y = j + col[tt];
            if ( inside(x, y) )
                f[k+1][x][y] = max(f[k+1][x][y], f[k][i][j] + a[x][y]);
        }

    }

    cout << ans;

    return 0;
}
