#include <bits/stdc++.h>
using namespace std;
long long x,n,a[1000000],i,dem;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>x;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n;i++)
    {
        for (long long j=i+1;j<=n; j++)
            if (a[i]+a[j]==x) dem++;
    }
    cout<<dem;
}
