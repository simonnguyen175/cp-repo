#include <bits/stdc++.h>
using namespace std;
long long a[1000][1000],s,n,i,j,ans;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; s=0;ans=-1000000;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    cin>>a[i][j];
    for (j=1;j<=n;j++)
    {
        for (i=1;i<=n;i++)
        {s=s+a[i][j];}
        ans=max(ans,s);
        s=0;
    }
    cout<<ans;
}

