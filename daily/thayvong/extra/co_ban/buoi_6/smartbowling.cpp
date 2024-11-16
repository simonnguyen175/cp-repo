#include <bits/stdc++.h>
using namespace std;
long long n,k,v[1000001],i,s;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>k;
    for (i=1; i<=n; i++) cin>>v[i];
    sort (v+1, v+1+n, greater <int>());
    if (k>n) {cout<<n; return 0;}
    s=k;
    for (i=k+1; i<=n; i++)
        s+=v[i];
    cout<<s;
}
