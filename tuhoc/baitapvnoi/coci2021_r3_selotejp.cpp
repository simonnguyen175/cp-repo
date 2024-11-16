#include<bits/stdc++.h>
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e3 + 5;
const int oo = 1e9;

int n, m;
char a[N][10];
int f[N][10][1<<10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j < m; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
    for (int j = 0; j < m; j ++)
    for (int msk = 0; msk < (1<<m); msk ++)
        f[i][j][msk] = oo;

    if ( a[1][0] == '.' ) f[1][0][0] = 0;
    else f[1][0][0] = f[1][0][1] = 1;


    for (int i = 1; i <= n; i ++)
    for (int j = 0; j < m; j ++)
    for (int msk = 0; msk < (1<<m); msk ++) if ( f[i][j][msk] != oo ){
        int nmsk, w;
        if ( j == m - 1 ){
            if ( a[i+1][0] == '.' ){
                nmsk = msk ^ BIT(msk, 0);
                f[i+1][0][nmsk] = min(f[i+1][0][nmsk], f[i][j][msk]);
            }
            else{
                w = 1 - BIT(msk, 0), nmsk = msk | 1;
                f[i+1][0][nmsk] = min(f[i+1][0][nmsk], f[i][j][msk] + w);
                w = 1, nmsk = msk ^ BIT(msk, 0);
                f[i+1][0][nmsk] = min(f[i+1][0][nmsk], f[i][j][msk] + w);
            }
        }
        else{
            if ( a[i][j+1] == '.' ){
                nmsk = msk ^ ( BIT(msk, j+1) ? (1<<(j+1)) : 0);
                f[i][j+1][nmsk] = min(f[i][j+1][nmsk], f[i][j][msk]);
            }
            else{
                w = 1 - BIT(msk, j+1), nmsk = msk | (1<<(j+1));
                f[i][j+1][nmsk] = min(f[i][j+1][nmsk], f[i][j][msk] + w);
                w = (BIT(msk, j) || a[i][j] == '.'), nmsk = msk ^ ( BIT(msk, j+1) ? (1<<(j+1)) : 0);
                f[i][j+1][nmsk] = min(f[i][j+1][nmsk], f[i][j][msk] + w);
            }
        }
    }

    int ans = oo;
    for (int msk = 0; msk < (1<<m); msk ++)
        ans = min(ans, f[n][m-1][msk]);

    cout << ans;

    return 0;
}
