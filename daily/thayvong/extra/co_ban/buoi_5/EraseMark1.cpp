#include <bits/stdc++.h>
using namespace std;
long long n, a[200002],i,s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1; i<=2*n;i++) cin>>a[i];
    for (i=1; i<=n; i++)
    {
        if (a[i]==a[2*n-i+1]) s+=(a[i]*2);
        else continue;
    }
    cout<<s;
}
