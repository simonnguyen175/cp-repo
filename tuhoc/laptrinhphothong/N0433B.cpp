#include <bits/stdc++.h>
using namespace std;
long long n,a[100000],b,i,dem,ans;
int main()
{
    ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
    cin>>n; i=1; dem=0; ans=0; ;
    while (i<=n)
    {
        cin>>a[i];
        if (a[i]==1) {dem++;}
        if (a[i]!=1)
        {
            if (dem>ans)
            {
                ans=dem;
                b=i-dem;
            }
            dem=0;
        }
        i++;
    }
    if (dem>ans)
            {
                ans=dem;
                b=i-dem;
            }
    if (ans==0) cout<<"-1";
        else for(i=b;i<=b+ans-1;i++) cout<<a[i]<<" ";
}
