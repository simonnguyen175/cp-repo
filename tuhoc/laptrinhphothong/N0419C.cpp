#include <bits/stdc++.h>
using namespace std;
long long n,a[1000],k,i,j,t,ans[1000];
int main()
{
    ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>k; ans[i]=1000000000;
        for (j=1;j<=k;j++)
        {
            ans[i]=min(a[j],ans[i]);
        }
    }
    for(i=1;i<=t;i++) cout<<ans[i]<<"\n";
}

