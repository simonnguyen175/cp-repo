#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, W, w[101], c[101], f[101][100001], g[101][100001];

int main(){
    freopen("Knapsack2.inp","r",stdin);
    freopen("Knapsack2.out","w",stdout);
    cin >> n >> W;
    for (int i=1; i<=n; i++)
        cin >> w[i];
    for (int i=1; i<=n; i++)
        cin >> c[i];
    for (int i=0; i<=n; i++)
        g[i][0]=1;
    for (int i=0; i<=W; i++)
        g[0][i]=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=W; j++){
            if (w[i] > j){
                f[i][j]=f[i-1][j];
                g[i][j]=g[i-1][j];
            }
            else{
                f[i][j]=f[i-1][j];
                g[i][j]=g[i-1][j];
                if ( f[i][j] < f[i-1][j-w[i]] + c[i]){
                    g[i][j] = g[i-1][j-w[i]];
                    f[i][j] = f[i-1][j-w[i]] + c[i] ;
                }
                else
                    if ( f[i][j] == f[i-1][j-w[i]]+c[i])
                        g[i][j] += g[i-1][j-w[i]];
            }
        }
    cout << f[n][W] <<'\n'<<g[n][W];
    return 0;
}
