#include <bits/stdc++.h>
using namespace std;
long long t,a[50],i,j,f1,f2,ans;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>t; f1=1; f2=1;
    for (i=1; i<=t; i++) cin>>a[i];
    for (i=1; i<=t; i++)
        {
            if (a[i]==1 || a[i]==2) cout<<1<<"\n";
            else
            {
                j=3;
                while (j<=a[i])
                {
                    ans=f1+f2;
                    f1=f2;
                    f2=ans;
                    j++;
                }
                cout<<ans<<"\n";
                j=3; f1=1;f2=1; ans=0;
            }
        }
}
