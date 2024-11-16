#include <bits/stdc++.h>
using namespace std;
long long n,a[100000000],i;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=n;i++)
    {
        if (a[i]%3!=0) cout<<a[i]<<" ";
    }
    cout<<"\n";
    for (i=1;i<=n;i++)
    {
        if (a[i]%5!=0 && a[i]%3!=0) cout<<a[i]<<" ";
    }
}
