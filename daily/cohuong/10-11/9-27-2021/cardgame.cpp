#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll oo = 1e15;
const int N = 1e2 + 5;

int t, n;
int red[N], blue[N];
ll f[1000000];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> red[i];
    for (int i = 1; i <= n; i ++) cin >> blue[i];

    for (int i = 1; i <= (1<<n)-1; i ++)
        f[i] = oo;

    f[(1<<n)-1] = 0;
    for (int mask = (1<<n)-1; mask >= 1; mask --)
        for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++){
            if ( i != j && ( mask & (1<<(i-1)) ) && ( mask & (1<<(j-1))) ){
                int nmask = mask ^ (1<<(i-1));
                f[nmask] = min({f[nmask], f[mask] + (red[i]^blue[j]), f[mask] + (blue[i]^red[j])});
            }
        }

    ll ans = oo;
    for (int i = 1; i <= n; i ++)
        ans = min(ans, f[(1<<(i-1))]);

    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("cardgame.in", "r") ){
        freopen("cardgame.in", "r", stdin);
        freopen("cardgame.out", "w", stdout);
    }

    cin >> t;

    while ( t -- )
        solve();

    return 0;
}
