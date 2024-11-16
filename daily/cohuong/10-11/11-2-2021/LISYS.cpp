#include<bits/stdc++.h>
#define simon "LISYS"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int m, n, s, ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> m >> n >> s;
    vector<vector<int>> a; a.resize(m + 2);
    vector<vector<int>> f; f.resize(m + 3);
    vector<int> row, col; row.resize(m + 2); col.resize(n + 2);

    for (int i = 0; i < a.size(); i ++) a[i].resize(n + 2);
    for (int i = 0; i < f.size(); i ++) f[i].resize(n + 3);

    for (int i = 0; i <= m + 1; i ++)
        for (int j = 0; j <= n + 1; j ++)
            f[i][j] = 0;

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    for (int i = 1; i <= s; i ++){
        int t; cin >> t;
        //if ( t <= m ) row[t] ++;
        //else col[t-m] ++;
        if ( t <= m ){
            // update (t,1) -> (t, n)
            f[t][1] ++;
            f[t][n+1] --;
            f[t+1][1] --;
            f[t+1][n+1] ++;
        }
        else{
            t -= m;
            // update (1, t) -> (m, t);
            f[1][t] ++;
            f[1][t+1] --;
            f[m+1][t] --;
            f[m+1][t+1] ++;
        }
    }

    for (int i = 1; i <= m; i ++)
        for (int j = 1; j <= n; j ++){
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
            f[i][j] %= 3; if ( f[i][j] < 0 ) f[i][j] += 3;
            if ( ( a[i][j] + f[i][j] ) % 3 == 0 ) ans ++;
        }

    cout << ans;

    return 0;
}
