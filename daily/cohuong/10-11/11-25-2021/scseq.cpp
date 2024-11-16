#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e15;

ll n, k;
ll a[N], s[N], t[N], g[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("scseq.inp", "r") ){
        freopen("scseq.inp", "r", stdin);
        freopen("scseq.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] + a[i];

    for (int i = 1; i <= n; i ++)
        t[i] = -s[i] - i * k;

    g[n+1] = -oo;
    for (int i = n; i >= 1; i --)
        g[i] = max(g[i+1], t[i] - s[i]);

    ll ans = -oo;

    for (int i = 1; i <= n; i ++)
        ans = max(ans, s[i-1] + g[i] + s[n] - t[i-1]);

    cout << ans;

    return 0;
}
