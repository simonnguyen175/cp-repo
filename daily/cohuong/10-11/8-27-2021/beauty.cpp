#include<bits/stdc++.h>
#define simon "beauty"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e15;

int n;
ll a[N], s, f[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    ll ans = -oo;
    s = a[1]; f[0] = 0; f[1] = a[1];

    for (int i = 2; i <= n; i ++){
        s = s + a[i];
        ans = max(ans, s - f[i-4]);
        f[i] = min(s, f[i-2]);
    }

    cout << ans;

    return 0;
}
