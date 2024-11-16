#include <bits/stdc++.h>
using namespace std;
long long n,a[10000],i,nn,ans;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;nn=10000000000;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]<nn)
        {
            nn=a[i];
            ans=i;
        }
    }
    cout<<ans;
}


