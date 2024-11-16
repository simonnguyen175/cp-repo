#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

ll range(ll l, ll r) {
    return l + rng() % (r - l + 1);
}

void solve() {
    for (int t = 1; t <= 10; ++t) {
        string add = (t <= 9 ? "0" : "");
        string test= "Testcases/input/input" + add + to_string(t) + ".txt";
        freopen(test.c_str(), "w", stdout);
        cout << range(1, 100) << ' ' << range(1, 100);
    }
}

// input01.txt output01.txt

int main() {
    // ios::sync_with_stdio(0);
    // cout.tie(0); cin.tie(0);
    solve();
    return 0;
}

