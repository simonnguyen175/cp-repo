#include <bits/stdc++.h>
#define simon "oddcoin"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int money[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};

int q, x, t;

int Change(int a) {
    int res = 0;
    for (int i = 14; i >= 0; i --) {
        res += a / money[i];
        a = a % money[i];
    }
    return res;
}

void solve(){
    int res = 1e9;
    for (int i = 0; i <= t / x; ++i) {
        if (res >= i + Change(t - i * x)) {
            res = i + Change(t - i * x);
        }
    }
    cout << res << ' ';
}
int main() {
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> x;
    while ( cin >> t )
        solve();

    return 0;
}
