#include <bits/stdc++.h>
using namespace std ;
long long ans,f[50],f1,f2,j,n,temp,dem;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    f1=1; f2=1; j=3; f[1]=1;f[2]=1;
    while (j<=50)
                {
                    f[j]=f1+f2;
                    f1=f2;
                    f2=f[j];
                    j++;
                }
    cout<<f[6];
}
