#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],i,j,k,x,y,ans;
long long baso(long long a,long long b,long long c)
    {
        long long m;
        m=min(a,b);
        m=min(m,c);
        return m;
    }
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n; ans=-10000000;
    for(i=1;i<=n;i++) cin>>a[i];
    ans=a[1]+a[2]-a[3];
    k=baso(a[1],a[2],a[3]);
    if (k==a[1]) {x=a[2];y=a[3];}
    if (k==a[2]) {x=a[1];y=a[3];}
    if (k==a[3]) {x=a[1];y=a[2];}
    for (i=4;i<=n;i++)
    {
        ans=max(ans,x+y-a[i]);
        k=baso(x,y,a[i]);
        if (k==x) {x=y;y=a[i];}
        if (k==y) {x=x;y=a[i];}
        if (k==a[i]) {x=x;y=y;}
    }
    cout<<ans;
}

