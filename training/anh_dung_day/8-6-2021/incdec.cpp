#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;

ll n;
ll a[N], sl[N], sc[N];
map<ll, ll> d;

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    ll ans = 0;
    sl[0] = sc[0] = 0;
    d[0] = 1;

    for (int i = 1; i <= n; i ++){
        if ( i % 2 ) sl[i] = sl[i-1] + a[i], sc[i] = sc[i-1];
        else sc[i] = sc[i-1] + a[i], sl[i] = sl[i-1];
        ans += d[sl[i]-sc[i]];
        d[sl[i]-sc[i]] ++;
    }

    cout << ans;

    return 0;
}
