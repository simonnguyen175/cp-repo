#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e2 + 5;

int n;
char a[N][N];
int mxl[N][N], smxu[N][N][N], smxd[N][N][N], g[N][N][N], f[N][N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("eight.inp", "r") ){
        freopen("eight.inp", "r", stdin);
        freopen("eight.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i ++){
        int len = 0;
        for (int j = 1; j <= n; j ++)
            if ( a[i][j] == '.' ) mxl[i][j] = ++ len;
            else len = 0;
    }

    for (int i = 3; i <= n; i ++)
    for (int d = 3; d <= i; d ++){

        int l = 1;
        while ( mxl[l][i] < d && l <= n ) l ++;
        int j = l + 1;

        while ( j <= n ){
            if ( a[j][i] == '*' || a[j][i-d+1] == '*' ){
                l = j + 1;
                while ( mxl[l][i] < d && l < n ) l ++;
                j = l + 1;
                continue;
            }
            else{
                if ( mxl[j][i] >= d ){
                    if ( j-l+1-2 < 0 ) continue;
                    smxu[j][i][d] = (j-l+1-2) * (d-2);
                }
                j ++;
            }
        }

        l = n;
        while ( mxl[l][i] < d && l >= 1 ) l --;
        j = l - 1;

        while ( j >= 1 ){
            if ( a[j][i] == '*' || a[j][i-d+1] == '*' ){
                l = j - 1;
                while ( mxl[l][i] < d && l > 1 ) l --;
                j = l - 1;
                continue;
            }
            else{
                if ( mxl[j][i] >= d ){
                    if ( l-j+1-2 < 0 ) continue;
                    smxd[j][i][d] = (l-j+1-2) * (d-2);
                }
                j --;
            }
        }

    }

    for (int i = 3; i <= n; i ++)
    for (int j = 3; j <= n; j ++)
    for (int d = 3; d <= j; d ++)
        g[i][j][d] = max(g[i][j][d-1], smxu[i][j][d]);

    for (int i = 3; i <= n; i ++)
    for (int j = 3; j <= n; j ++)
    for (int d = 3; d <= j; d ++)
        f[i][j][d] = max(f[i][j-1][d-1], g[i][j][d]);

    ll ans = 0;
    for (int i = 3; i <= n; i ++)
    for (int j = 3; j <= n; j ++)
    for (int d = 3; d <= j; d ++)
        ans = max(ans, 1LL * f[i][j][d] * smxd[i][j][d]);

    if ( !ans ) cout << -1;
    else cout << ans;

    return 0;
}
