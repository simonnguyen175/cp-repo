#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[100001], s[100001], k;

int main(){
    freopen("SumCMax1.inp","r",stdin);
    freopen("SumCMax1.out","w",stdout);
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> k; s[0]=0;
    for (ll i=1; i<=n; i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    sort(s, s+k);
    cout << s[k]-s[0];
    return 0;
}
