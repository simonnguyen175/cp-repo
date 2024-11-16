#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001], c[1001], ans=0;
long long f[1001][50001], s[1001][50001], oo=1e12;

int main(){
    //freopen("Knapagain.inp","r",stdin);
    //freopen("Knapagain.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    int x=0;
    for (int i=1; i<=n; i++){
        cin >> c[i];
        x+=c[i];
    }
    for (int i=0; i<=n; i++)
        for (int j=0; j<=x; j++)
            f[i][j] = oo;
    f[0][0]=0;
    cout << n <<' '<<x <<'\n';
    for (int i=1; i<=n; i++)
        for (int j=1; j<=x; j++)
            if ( j >= c[i] ){
                f[i][j]=min(f[i-1][j-c[i]]+a[i], f[i-1][j]);
            }
            else{
                f[i][j]=f[i-1][j];
            }
    for (int i=1; i<=n; i++)
        for (int j=1; j<=x; j++)
            if ( f[i][j] <= m )
                ans=max(ans,j);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=x; j++)
            cout << f[i][j] <<' ';
        cout << '\n';
    }
    cout << ans;
    return 0;
}
