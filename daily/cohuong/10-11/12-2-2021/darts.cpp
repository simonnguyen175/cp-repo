#include<bits/stdc++.h>
#define simon "darts"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e3 + 5;

int n, m;
ll p[N];
vector<ll> a;

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;

    p[0] = 0;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    for (int i = 0; i <= n; i ++)
        for (int j = 0; j <= n; j ++)
            a.push_back(p[i]+p[j]);

    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            ll x = p[i] + p[j];
            if ( x >= m ) continue;
            auto it = upper_bound(a.begin(), a.end(), m - x);
            it --;
            if ( *it <= m - x ) ans = max(ans, x + *it);
        }

    cout << ans;

    return 0;
}
