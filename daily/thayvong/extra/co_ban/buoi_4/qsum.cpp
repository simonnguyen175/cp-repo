#include <bits/stdc++.h>
using namespace std;
long long n,q,a[10000000],s[1000000],b[10000000],i,k,t;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>q;
    for (i=1; i<=n; i++)
        {
            cin>>a[i];
            s[i]+=s[i-1]+a[i];
        }
    for (i=1; i<=q; i++)
    {
        cin>>k>>t;
        b[i]=s[t]-s[k-1];
    }
    for (i=1; i<=q; i++)
        cout<<b[i]<<"\n";
}
