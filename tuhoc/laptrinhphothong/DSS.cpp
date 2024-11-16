#include <bits/stdc++.h>
using namespace std;
long long n,a[1000],b[1000],d,dem,i,j,k,ans;
int main()
{
    freopen("dss.inp","r",stdin);
    freopen("dss.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
    cin >> n;
    for (i=1; i<=n; i++) cin >> a[i];
    for (i=1; i<=n; i++)
        for (j=i; j<=n; j++)
            {
                d=0; dem=1;
                for (k=i; k<=j; k++)
                    {
                        d++;b[d]=a[k];
                    }
                sort (b+1,b+1+d);
                for (k=2; k<=d; k++)
                    if (b[k]!=b[k-1]) dem++;
                if (dem==d) ans=max(ans,d);
            }
    cout << ans;
}
