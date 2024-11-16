#include <bits/stdc++.h>
using namespace std;
long long n,x[1000001],y[1000001],a[1000001],b[1000001];
long long c[5][5],u,v,i,j,res;
int main()
{
    freopen("ColourRect2.inp","r",stdin);
    freopen("ColourRect2.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n ;
    for (i=1; i<=n; i++) cin >> x[i];
    for (i=1; i<=n; i++) cin >> a[i];
    for (i=1; i<=n; i++) cin >> y[i];
    for (i=1; i<=n; i++) cin >> b[i];
    i=1; j=1;
    while (i <= n && j <=n)
    {
        if (x[i]==y[j])
        {
            {
                u=a[i]; v=b[j];
                if (u > v) swap (u,v);
                c[u][v]++;
                i++; j++;
            }
        }
        else
            if (x[i]<y[j]) i++;
                else j++;
    }
    res+=(c[0][1]*c[2][3]+c[0][2]*c[1][3]+c[0][3]*c[1][2]);
    cout << res;
    return 0 ;
}
