#include <bits/stdc++.h>
using namespace std;

int n, m, d[1001], f[1001][1001];

int main(){
    freopen("noidiem.inp","r",stdin);
    freopen("noidiem.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> d[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if ( abs(d[j]-i) <= m ) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j], f[i][j-1]);
    cout << f[n][n];
    return 0;
}
