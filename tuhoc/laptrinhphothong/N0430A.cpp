#include <bits/stdc++.h>
using namespace std;
long long n,a[10000],i;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]<=0) a[i]=0;
    }
    for (i=1;i<=n;i++) cout<<a[i]<<" ";
}
