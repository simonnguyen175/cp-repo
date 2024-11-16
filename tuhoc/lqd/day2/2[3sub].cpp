#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int base = 1e4;
const int oo = 1e9 + 7;

int n, X, Y, Z;
int a[N], b[N], f[N][20*N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> X >> Y >> Z;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    for (int i = 0; i <= n; i ++)
    for (int j = -10*n; j <= 10*n; j ++)
        f[i][j+base] = oo;

    f[0][base] = 0;

    for (int i = 0; i <= n; i ++)
    for (int j = -10*i; j <= 10*i; j ++) if ( f[i][j+base] != oo )
    for (int x = 0; x <= 10; x ++){
        int nj = j, w = f[i][j+base];

        nj += (x-a[i+1]);
        w += Z * abs(j) + ( x > b[i+1] ? X * (x-b[i+1]) : Y * (b[i+1]-x) );

        f[i+1][nj+base] = min(f[i+1][nj+base], w);
    }

    cout << f[n][base];

    return 0;
}
