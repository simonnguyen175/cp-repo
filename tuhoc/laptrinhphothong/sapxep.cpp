#include <bits/stdc++.h>
using namespace std;
long long n,a[1001],i,j,temp;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n-1;i++)
    {
        for(long long j=i+1;j<=n;j++)
        if (a[i]>a[j])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    for (i=1;i<=n;i++) cout<<a[i]<<" ";
}
