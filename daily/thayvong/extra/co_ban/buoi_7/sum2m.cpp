#include <bits/stdc++.h>
using namespace std;
long long n,x,a[500001],d[1000001],i,s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>x;
    for (i=1; i<=n; i++) cin>>a[i];
    for (i=1; i<=n; i++)
    {
        s+=d[x-a[i]];
        d[a[i]]++;
    }
    cout <<s ;
}
