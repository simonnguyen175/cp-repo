#include<bits/stdc++.h>
#define ll long long
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e3 + 5;
const ll oo = 1e18;

int r, c, k;
ll a[N][10], f[2][35][N*10], sum[N][35];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("domine.inp", "r")  ){
        freopen("domine.inp", "r", stdin);
        freopen("domine.out", "w", stdout);
    }

    cin >> r >> c >> k;
    for (int i = 1; i <= r; i ++)
    for (int j = 1; j <= c; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= r; i ++)
    for (int mask = 0; mask < (1<<c); mask ++)
    for (int j = 1; j <= c; j ++)
        if ( BIT(mask, j-1) )
            sum[i][mask] += a[i][j];


    memset(f, -0x3f, sizeof f);

    f[0][0][0] = 0;

    for (int i = 0; i <= r; i ++)
    for (int mask = 0; mask < (1<<c); mask ++)
    for (int j = 0; j <= k; j ++) if ( f[i&1][mask][j] > -oo ){
        f[(i+1)&1][0][j] = max(f[(i+1)&1][0][j], f[i&1][mask][j]);

        if ( j < k ){
            for (int t = 1; t < c; t ++)
            if ( !BIT(mask, t-1) && !BIT(mask, t) )
                f[i&1][mask|(1<<(t-1))|(1<<t)][j+1]
                = max(f[i&1][mask|(1<<(t-1))|(1<<t)][j+1], f[i&1][mask][j] + a[i+1][t] + a[i+1][t+1]);
        }

        if ( i + 1 < r ){
            int other = ((1<<c)-1) ^ mask;
            for (int t = other; t > 0; t = (t-1)&other){
                if ( j + __builtin_popcount(t) <= k ){
                    int nj = j + __builtin_popcount(t);
                    f[(i+1)&1][t][nj] = max(f[(i+1)&1][t][nj], f[i&1][mask][j] + sum[i+1][t] + sum[i+2][t]);
                }
            }
        }

        if ( i < r ) f[i&1][mask][j] = -oo;
    }

    cout << f[r&1][0][k];

    return 0;
}
