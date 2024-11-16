#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, k;
ll a[100001], d[100001];

int main()
{
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    //freopen("sumdivk.inp","r",stdin);
    //freopen("sumdivk.out","w",stdout);
    cin >> n >> k;
    ll s=0, ans=0; d[0]=1;
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<=n; i++){
        s+=a[i];
        s%=k;
        ans+=d[s];
        d[s]++;
    }
    cout << ans;
}
