#include <bits/stdc++.h>
using namespace std;

int n;
long long a[500][500],p[500][500], s[500][500], ans;

int main(){
    freopen("NSQ.inp","r",stdin);
    freopen("NSQ.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            s[i][j]=s[i-1][j-1]+a[i][j];
    for (int i=1; i <= n; i++)
        for (int j=n; j>=1; j--)
            p[i][j]=p[i-1][j+1]+a[i][j];

    ans = INT_MIN;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            int km=min(n-i,n-j);
            for (int k=1; k<=km; k++)
            {
                long long e = s[i+k][j+k]-s[i-1][j-1]- (p[i+k][j]-p[i-1][j+k+1]);
                ans= max(e, ans);
            }
        }
    cout << ans;
    return 0;
}
