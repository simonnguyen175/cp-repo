#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],i,dem;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++) a[i]=i;
    dem=n;
    while (dem>1)
    {
        for (i=1;i<=n-1;i++)
        {
            a[i]=a[i]+a[i+1];
        }
        dem=i; n=n-1;
    }
    cout<<a[1]%1000000000;
}
