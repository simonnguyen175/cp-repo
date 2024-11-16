#include <bits/stdc++.h>
using namespace std;
const long long oo=1e18;

int n, m;
long long f[501][501];

int main(){
    freopen("CutNet.inp","r",stdin);
    freopen("CutNet.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            if ( i == j ){f[i][j]=0; continue;}
            else f[i][j]=oo;
            for (int k=1; k<i; k++)
                f[i][j]=min(f[i][j], f[k][j]+f[i-k][j]+1);
            for (int k=1; k<j; k++)
                f[i][j]=min(f[i][j], f[i][k]+f[i][j-k]+1);
        }
    cout << f[n][m];
    return 0;
}
