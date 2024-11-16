#include <bits/stdc++.h>
using namespace std;
long long dem[1000000],n,k,a[500001],j,s,ans;
int main()
{
    freopen("Kcontinue.inp","r",stdin);
    freopen("Kcontinue.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin>>n>>k;
    for (j=1; j<=n; j++) cin>>a[j];
    s=0; dem[0]=1;
    for (j=1; j<=n; j++)
    {
        s=(s+a[j])%k;
        if (s<0) s=s+k;
        ans+=dem[s];
        dem[s]++;
    }
    cout << ans;
}
