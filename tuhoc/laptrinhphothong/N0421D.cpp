#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],i;
int main()
{
    ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
    cin>>n; float ans;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if (n%2==0) ans=(float)(a[n/2]+a[n/2+1])/2;
    if (n%2!=0) ans=a[n/2+1];
    cout<<ans;
}
