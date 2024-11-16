#include <bits/stdc++.h>;
using namespace std;
long long n,a[200000],i,s,ans,mod=1000000007;
int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    s=a[n];
    ans=0;
    for (long long i=n-1; i>=1; i--)
    {
        ans=(ans+a[i]*s)%mod;
        s=(s+a[i])%mod ;
    }
    cout<<ans;
}
