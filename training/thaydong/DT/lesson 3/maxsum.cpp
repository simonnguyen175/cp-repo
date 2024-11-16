#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e12;

int n, k;
ll a[N][N], f[N][N][2], ans = -oo;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++)
        cin >> a[i][j];

    for (int i = 0; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        f[i][j][0] = f[i][j][1] = -oo;

    f[1][1][0] = a[1][1];
    for (int t = 0; t <= k; t ++){
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            if ( i < n ) f[i+1][j][t%2] = max(f[i+1][j][t%2], f[i][j][t%2] + a[i+1][j]);
            if ( j < n ) f[i][j+1][t%2] = max(f[i][j+1][t%2], f[i][j][t%2] + a[i][j+1]);

            if ( i > 1 ) f[i-1][j][(t+1)%2] = max(f[i-1][j][(t+1)%2], f[i][j][t%2] + a[i-1][j]);
            if ( j > 1 ) f[i][j-1][(t+1)%2] = max(f[i][j-1][(t+1)%2], f[i][j][t%2] + a[i][j-1]);
        }
        ans = max({ans, f[n][n][0], f[n][n][1]});
    }
    ans = max({ans, f[n][n][0], f[n][n][1]});

    cout << ans;

    return 0;
}
