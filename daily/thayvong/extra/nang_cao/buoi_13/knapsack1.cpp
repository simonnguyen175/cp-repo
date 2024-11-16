#include <bits/stdc++.h>
using namespace std;

long long n, W, w[101], c[101], f[101][100001];

int main(){
    freopen("Knapsack1.inp","r",stdin);
    freopen("Knapsack1.out","w",stdout);
    cin >> n >> W;
    for (int i=1; i<=n; i++)
        cin >> w[i];
    for (int i=1; i<=n; i++)
        cin >> c[i];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=W; j++){
            if ( w[i] > j )
                f[i][j]=f[i-1][j];
            else
                f[i][j]=max(f[i-1][j], f[i-1][j-w[i]] + c[i]);
        }
    cout << f[n][W];
    return 0;
}
