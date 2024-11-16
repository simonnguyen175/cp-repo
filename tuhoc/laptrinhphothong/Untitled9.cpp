#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],b[100000],c[10000000000],i,p;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; p=1;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        c[p]=a[i]; p++;
    }
    for (i=1;i<=n;i++)
    {
        cin>>b[i];
        c[p+1]=b[i];
    }
    sort(c+1,c+1+2*n);
    for(i=1;i<=2*n;i++) cout<<c[i]<<" ";
}

