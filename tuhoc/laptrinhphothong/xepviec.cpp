#include <bits/stdc++.h>
using namespace std;

int n,k,v[101][101];

int main(){
    cin >> k >> n;
    for (int i=1; i<=k; i++)
        for (int j=1; j<=n; j++)
            cin >> v[i][j];

    int f[101][101];
    memset(f, 0, sizeof f);
    for (int i=1; i<=k; i++)
        for (int j=1; j<=n; j++)
            for (int x=i; x<=j; x++)
                f[i][j]=max(f[i][j], f[i-1][x-1]+v[i][x]);
    cout << f[k][n];
    return 0;
}
