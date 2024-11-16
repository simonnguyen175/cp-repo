#include <bits/stdc++.h>
using namespace std;
long long n,a[100001],i;
long long tinh(long long n)
{
    return n*(n+1)*(2*n+1)/6;
}
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1; i<=n; i++) cin>>a[i];
    for (i=1; i<=n; i++)
        cout<<tinh(a[i])<<"\n";
    return 0;
}
