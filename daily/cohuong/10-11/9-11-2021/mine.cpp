#include <bits/stdc++.h>
#define simon "mine"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 4e3 + 5;
const int MOD = 1e6 + 3;

int n, m, a[N];
ll f[N][N];

ll calc(int l, int r) {
    if ( l > r ) return 1;
    if ( (r - l + 1) % 2 == 1 ) return 0;
    if ( f[l][r] != - 1 ) return f[l][r];

    ll res = 0;
    for (int i = l + 1; i <= r; i += 2)
        if ( a[i] - a[l] <= m )
            (res += calc(l + 1, i - 1) * calc(i + 1, r) % MOD ) % MOD;
        else break;

    f[l][r] = res;

    return res;
}

int main() {
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }


    cin >> n >> m; n *= 2;

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    memset(f, -1, sizeof f);

    cout << calc(1, n) << '\n';

    return 0;
}
