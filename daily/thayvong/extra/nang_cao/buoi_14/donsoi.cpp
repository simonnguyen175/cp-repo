#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long oo=1e18;

int n;
ll a[501], f[501][501], s[501];

int main(){
    freopen("donsoi.inp","r",stdin);
    freopen("donsoi.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=1; i<=n; i++)
        f[i][i]=0;
    for (int i=n-1; i>=1; i--)
        for (int j=i+1; j<=n; j++){
            f[i][j]=oo;
            for (int k=i; k<j; k++)
                f[i][j]=min(f[i][j], f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
    cout << f[1][n];
    return 0;
}