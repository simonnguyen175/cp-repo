#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[1001], b[499501];

int main(){
    freopen("SumPairs.inp","r",stdin);
    freopen("SumPairs.out","w",stdout);
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> a[i];
    ll m=0;
    for (ll i=1; i<=n; i++)
    for (ll j=i+1; j<=n; j++) b[++m]=a[i]+a[j];
    sort(b+1, b+1+m);
    for (int i=1; i<=m; i++) cout << b[i] <<' ';
    return 0;
}
