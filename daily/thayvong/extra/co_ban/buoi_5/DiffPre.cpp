#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000],MIN[1000000],i;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n; MIN[0]=INT_MAX;
    for (i=1; i<=n; i++) cin>>a[i];
    for (i=1; i<=n; i++)
        MIN[i]=min(MIN[i-1],a[i]);
    for (i=2; i<=n; i++)
        cout<<a[i]-MIN[i-1]<<"\n";
}
