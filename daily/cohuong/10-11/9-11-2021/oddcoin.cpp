#include <bits/stdc++.h>
#define simon "oddcoin"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int money[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};

int q, x, t;

int Change(int a) {
    int res = 0;
    for (int i = 14; i >= 0; i --) {
        res += a / money[i];
        a = a % money[i];
    }
    return res;
}

void solve() {
    int res = 1e9;
    for (int i = 0; i <= t / x; ++i) {
        if (res >= i + Change(t - i * x)) {
            res = i + Change(t - i * x);
        }
    }
    cout << res << '\n';
}
int main() {
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> q;
    while ( q -- ){
        cin >> x >> t;
        solve();
    }

    return 0;
}
