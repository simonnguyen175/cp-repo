#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 5;

int m, n, k;
bool missed[N][N];

bool inside(int x, int y){
    return ( x >= 1 && x <= m && y >= 1 && y <= n );
}

bool check(int x, int y, int u, int v){
    int dc, dr;
    dr = u - x; dc = v - y;
    if ( inside(x-dc, y+dr) && inside(u-dc, v+dr) )
        return ( !missed[x-dc][y+dr] && !missed[u-dc][v+dr] );
    else return false;
}

namespace sub2{
    ll ans = 0;

    void solve(){
        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++) if ( !missed[i][j] )
            for (int u = i + 1; u <= m; u ++)
            for (int v = j; v <= n; v ++){
                //cout << i <<  ' ' << j << ' ' << u << ' ' << v << '\n';
                //cout << ( !missed[u][v] && check(i, j, u, v) ) << '\n';
                if ( !missed[u][v] && check(i, j, u, v) )
                    ans ++;

            }
        cout << ans;
    }
}

namespace sub3{
    ll ans = 0;

    void solve(){
        for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            int len = 0;
            for (int row = i + 1; row <= m; row ++)
                if ( check(i, j, row, j) )
                    len ++;
            ans += len;
            for (int col = j + 1; col <= n; col ++){
                while ( !check(i, j, i + len, col) && len > 0 )
                    len --;
                ans += len;
            }
        }

        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("squares.inp", "r", stdin);
    freopen("squares.out", "w", stdout);

    cin >> m >> n >> k;

    memset(missed, 0, sizeof missed);
    for (int i = 1; i <= k; i ++){
        int x, y; cin >> x >> y;
        missed[x][y] = 1;
    }

    if ( k == 0 ) sub3::solve();
    else sub2::solve();

    return 0;
}

