#include <bits/stdc++.h>
using namespace std;
long long n,a[10000],i,ln,ans;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;ln=0;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>=ln)
        {
            ln=a[i];
            ans=i;
        }
    }
    cout<<ans;
}

