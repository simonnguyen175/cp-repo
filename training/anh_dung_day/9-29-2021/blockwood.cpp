#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e9;

int t, n, m;
int a[N], h[N];
int hmax[N][N], fl[N][N], fr[N][N];

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i < n; i ++)
        cin >> h[i];

    assert(n<=5000);

    for (int i = 0; i <= n+1; i ++)
    for (int j = 0; j <= n+1; j ++)
        fl[i][j] = fr[i][j] = oo;

    for (int i = 1; i < n; i ++){
        hmax[i][i] = h[i];
        for (int j = i + 1; j < n; j ++)
            hmax[i][j] = max(hmax[i][j-1], h[j]);
    }

    fl[1][n] = fr[1][n] = 0;
    for (int i = 1; i <= n; i ++)
    for (int j = n; j >= i; j --){
        // fl
        fl[i][j] = min(fl[i][j], max(fl[i-1][j] - a[i-1] + h[i-1], h[i-1]));
        fl[i][j] = min(fl[i][j], max(fr[i][j+1] - a[j+1] + h[j], hmax[i][j]));
        //cout << i << ' ' << j << " : " << fl[i][j] << '\n';

        // fr
        fr[i][j] = min(fr[i][j], max(fr[i][j+1] - a[j+1] + h[j], h[j]));
        fr[i][j] = min(fr[i][j], max(fl[i-1][j] - a[i-1] + h[i-1], hmax[i][j]));
        //cout << i << ' ' << j << " : " << fr[i][j] << '\n';
    }

    for (int i = 1; i <= m; i ++){
        int x, y; cin >> x >> y;
        if ( fr[x][x] <= y + a[x] || fl[x][x] <= y + a[x] ) cout << 'Y';
        else cout << 'N';
    }

    cout << '\n';
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("blockwood.inp", "r") ){
        freopen("blockwood.inp", "r", stdin);
        freopen("blockwood.out", "w", stdout);
    }

    cin >> t;

    while ( t -- )
        solve();

    return 0;
}
