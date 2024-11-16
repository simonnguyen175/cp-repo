#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int m, n;
ll k, a[N], s[N];

int main(){
    cin >> m >> n >> k;
    s[0] = 0;
    for (int i = 1; i <= m; i ++)
        cin >> a[i];

    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i ++)
        s[i] = s[i-1] + a[i];

    ll ans = 0;

    for (int i = n; i <= m; i ++){
        if ( a[i] - a[i-n+1] > k ) continue;
        ans = max(ans, s[i] - s[i-n]);
    }

    if ( ans == 0 ) cout << -2;
    else cout << ans;

    return 0;
}
