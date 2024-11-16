#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],i,m,kq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++) cin>>a[i];
    kq=a[2]-a[1];
    m=min(a[2],a[1]);
    for (i=3;i<=n;i++)
        {
        kq=max(kq,a[i]-m);
        m=min(m,a[i]);
        }
    cout<<kq;
}

