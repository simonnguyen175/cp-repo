#include<bits/stdc++.h>
#define simon "divexp"
#define ll long long
using namespace std;
const int N = 1e7 + 5;

int l, r, k;
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> l >> r >> k;

    ll ans = 0;

    for (int i = 2; i <= r; i ++){
        ans += r/i - (l-1)/i;
        int x = i, ok = 1;
        for (int j = 1; j < k; j ++){
            if ( r / i < x ) { ok = 0; break; }
            else x *= i;
        }
        if ( ok ) ans -= r/x - (l-1)/x;
    }

    cout << ans;

    return 0;
}
