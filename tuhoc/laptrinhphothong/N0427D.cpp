#include <bits/stdc++.h>
using namespace std ;
long long ans,f[50],f1,f2,j,n,temp,dem;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    f1=1; f2=1; j=3; f[1]=1;f[2]=1;dem=0;
    while (j<=50)
                {
                    f[j]=f1+f2;
                    f1=f2;
                    f2=f[j];
                    j++;
                }
    while (n>=0)
    {
        j=1;
        while (f[j]<=n)
        {
            temp=f[j];
            j++;
        }
        n=n-temp;
        dem++;
    }
    cout<<dem-1;
}
