#include <bits/stdc++.h>
using namespace std;
long long a[100001],i,n,s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; s=0;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i] % 2 ==0) s+=2*a[i];
            else s+=3*a[i];
    }
    cout<<s;
}
