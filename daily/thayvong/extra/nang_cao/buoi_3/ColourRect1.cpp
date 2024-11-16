#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,x[1000001],y[1000001],r[2000002],b[2000002];
int i,j,ans,cb,cr,dem;
int main()
{
    freopen ("ColourRect1.inp","r",stdin);
    freopen ("ColourRect1.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n;
    cb=0;cr=0,dem=0;
    for (i=1; i<=n; i++) cin >> x[i];
    for (i=1; i<=n; i++)
    {
        cin >> m;
        if (m==0)
            {cb++;b[cb]=x[i];}
        else
            {cr++;r[cr]=x[i];}
    }
    for (i=1; i<=n; i++) cin >> y[i];
    for (i=1; i<=n; i++)
    {
        cin >> m;
        if (m==0)
            {cb++;b[cb]=y[i];}
        else
            {cr++;r[cr]=y[i];}
    }
    sort (b+1,b+1+cb);
    sort (r+1,r+1+cr);
    for (i=2; i<=cb; i++)
        if (b[i]==b[i-1]) dem++;
    ans+=(dem*(dem-1)/2);
    dem=0;
    for (i=2; i<=cr; i++)
        if (r[i]==r[i-1]) dem++;
    ans+=(dem*(dem-1)/2);
    cout << ans;
}
