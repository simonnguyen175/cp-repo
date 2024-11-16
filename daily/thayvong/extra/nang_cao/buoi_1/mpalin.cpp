#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],i,l,r,ans;
int main()
{
    freopen("mpalin.inp","r",stdin);
    freopen("mpalin.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; l=1; r=n; ans=0;
    for (i=1; i<=n; i++) cin>>a[i];
    while (l<r)
    {
        if (a[l]==a[r]) {l++; r--; continue;}
        if (a[l]<a[r])
        {
            ans++;
            a[l+1]+=a[l];
            l++;
        }
        else
        {
            ans++;
            a[r-1]+=a[r];
            r--;
        }
    }
    cout <<  ans;
}
