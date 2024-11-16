#include <bits/stdc++.h>
using namespace std;
long long n,k,a[100000],b[100000],p[100000],q[100000],i;
int main()
{
    ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
    freopen("Pseq.inp","r",stdin);
    freopen("soday.out","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    for (i=1;i<=k;i++)
    {
        cin>>p[i]>>q[i];
        cout<<b[q[i]]-b[p[i]-1]<<"\n";
    }
}
