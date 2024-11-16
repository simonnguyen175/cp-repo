#include <bits/stdc++.h>
using namespace std;
long  long n,i,a[1001],ln;
int main()
{
    ln=0;
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n-1;i++)
    {
        for(long long j=i+1;j<=n;j++)
        if (ln<a[i]*a[i]+a[j]*a[j]) ln=a[i]*a[i]+a[j]*a[j];
    }
    cout<<ln;
}
