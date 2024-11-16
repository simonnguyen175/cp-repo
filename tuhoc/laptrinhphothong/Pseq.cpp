#include <bits/stdc++.h>
using namespace std;
map <long long, long long> mp;
long long n,k,a[100001],s[100001],i,ans;
int main()
{
    freopen("pseq.inp","r",stdin);
    freopen("pseq.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>k;
    s[0]=0;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    mp[0]=1;
    for (i=1; i<=n; i++)
    {
        mp[s[i]]++;
        ans+=mp[s[i]-k];
    }
    cout << ans ;
}
