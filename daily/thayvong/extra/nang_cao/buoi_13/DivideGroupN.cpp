#include <bits/stdc++.h>
using namespace std;

long long n, W, f[501][62626], g[501][62626], mod=1000000007;

int main(){
    freopen("DivideGroupN.inp","r",stdin);
    freopen("DivideGroupN.out","w",stdout);
    cin >> n;
    W=n*(n+1)/2;
    if ( W % 2 == 1 ){
        cout << 0;
        return 0;
    }
    W/=2;
    for (int i=0; i<=n; i++)
        g[i][0]=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=W; j++){
            g[i][j]=g[i-1][j];
            if ( j >= i ) g[i][j] += g[i-1][j-i] ;
            g[i][j] %= mod;
        }
    cout << g[n][W];
    return 0;
}
