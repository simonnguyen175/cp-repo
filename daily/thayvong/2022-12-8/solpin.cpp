#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2005;

int m, n, q;
int s[N][N], a[N][N];

int get(int x, int y, int u, int v){
    return s[u][v] - s[u][y-1] - s[x-1][v] + s[x-1][y-1];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("solpin.inp", "r") ){
        freopen("solpin.inp", "r", stdin);
        freopen("solpin.out", "w", stdout);
    }

    cin >> m >> n;
    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        cin >> a[i][j];
        a[i+m][j] = a[i][j];
        a[i][j+n] = a[i][j];
        a[i+m][j+n] = a[i][j];
    }

    for (int i = 1; i <= 2*m; i ++)
    for (int j = 1; j <= 2*n; j ++)
        s[i][j] = s[i][j-1] + s[i-1][j] + a[i][j] - s[i-1][j-1];

    cin >> q;
    int crow = 1, ccol = 1;
    int p, x, y, u, v;
    while ( q -- ){
        cin >> p;
        if ( p == 0 ){
            cin >> x >> y;
            crow += y;
            ccol += x;
            crow %= m; ccol %= n;
            if ( crow == 0 ) crow = m;
            if ( ccol == 0 ) ccol = n;
        }
        else{
            cin >> x >> y >> u >> v;
            cout << get(x+crow-1, y+ccol-1, u+crow-1, v+ccol-1) << '\n';
        }
    }

    return 0;
}
