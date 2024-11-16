#include <bits/stdc++.h>
using namespace std;
long long n,x,a[500001],dd[1000001],da[1000001],ddr[],dal[],i,s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>x;
    long long s=0;
    for (i=1; i<=n; i++) cin >> a[i];
    for (i=1; i<=n; i++)
    {
        if (x-a[i]<0) s+=da[abs(x-a[i])];
        if (x-a[i]>=0) s+=dd[x-a[i]];
        if (a[i]>=0) dd[a[i]]++;
        else da[abs(a[i])]++;
    }
    cout << s ;
}
