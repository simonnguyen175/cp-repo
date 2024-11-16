#include<bits/stdc++.h>
#define simon "bridges"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int k, n, m = 0;
ll a[2*N], s[2*N];
ll ans = 0;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> k >> n;
    for (int i = 1; i <= n; i ++){
        char p, q; int s, t;
        cin >> p >> s >> q >> t;
        if ( p == q ) ans += abs(s-t);
        else ans += 1, a[++m] = s, a[++m] = t;
    }

    sort(a + 1, a + 1 + m);

    for (int i = 1; i <= m; i ++)
        s[i] = s[i-1] + a[i];

    if ( k == 1 ){
        ll med = a[(m+1)/2];
        ans += (m+1)/2 * med - s[(m+1)/2] + s[m] - s[(m+1)/2] - (m-(m+1)/2) * med;
    }

    cout << ans;

    return 0;
}
