#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, q, k, a[200001], mink[200001], s[200001], ans[200001];

int main(){
    freopen("SumCMax2.inp","r",stdin);
    freopen("SumCMax2.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n;
    s[0]=0; mink[0]=0;
    for (ll i=1; i<=n; i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    for (ll i=1; i<=n; i++){
        ans[i]=s[i]-mink[i-1];
        mink[i]=min(s[i],mink[i-1]);
    }
    cin >> q;
    for (ll i=1; i<=q; i++){
        cin >> k;
        cout << ans[k] <<'\n';
    }
    return 0;
}
