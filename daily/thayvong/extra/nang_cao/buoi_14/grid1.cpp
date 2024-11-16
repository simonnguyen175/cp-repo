#include <bits/stdc++.h>
#define emerald "GRID"
#define l2 long long
using namespace std;
l2 a[1005][1005],f[1005][1005][55],mx=-1e18,n,k,temp,inf=-1e18;
int main()
{
    freopen(emerald".INP","r",stdin);
    freopen(emerald".OUT","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            for(int z=0; z<=k; z++)
                f[i][j][z]=inf;

    if(a[1][1]>=0) f[1][1][0]=a[1][1];
    else f[1][1][1]=a[1][1];

    for(int i=2; i<=n; i++)
        for(int z=0; z<=k; z++)
            if(a[1][i]>=0)
            {
                if(f[1][i-1][z]!=inf) f[1][i][z]=f[1][i-1][z]+a[1][i];
            }
            else
            {
                if(z!=0)
                if(f[1][i-1][z-1]!=inf) f[1][i][z]=f[1][i-1][z-1]+a[1][i];
            }

    for(int i=2; i<=n; i++)
        for(int z=0; z<=k; z++)
            if(a[i][1]>=0)
            {
                if(f[i-1][1][z]!=inf) f[i][1][z]=f[i-1][1][z]+a[i][1];
            }
            else
            {
                if(z!=0)
                if(f[i-1][1][z-1]!=inf) f[i][1][z]=f[i-1][1][z-1]+a[i][1];
            }

    for(int i=2; i<=n; i++)
        for(int j=2; j<=n; j++)
            for(int z=0; z<=k; z++)
            {
                if(a[i][j]>=0)
                {
                    if(f[i-1][j][z]!=inf) f[i][j][z]=f[i-1][j][z]+a[i][j];
                    if(f[i][j-1][z]!=inf) f[i][j][z]=max(f[i][j][z],f[i][j-1][z]+a[i][j]);
                }
                else
                {
                    if(z!=0)
                    {
                        if(f[i-1][j][z-1]!=inf) f[i][j][z]=f[i-1][j][z-1]+a[i][j];
                        if(f[i][j-1][z-1]!=inf) f[i][j][z]=max(f[i][j][z],f[i][j-1][z-1]+a[i][j]);
                    }
                }
            }

    for(int i=0; i<=k; i++)
    {
        mx=max(mx,f[n][n][i]);
       // cout<<f[n][n][i]<<endl;
    }
    if(mx==inf) cout<<"NO";
    else cout<<mx;
}