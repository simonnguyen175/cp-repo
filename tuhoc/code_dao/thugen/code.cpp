#include <bits/stdc++.h>
using namespace std;

#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << '\n';
using ll = long long;
using ld = long double;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

void solve() {
    for (int t = 1; t <= 10; ++t) {
        string add = (t <= 9 ? "0" : "");
        string testin = "Testcases/input/input" + add + to_string(t) + ".txt"; // filename Test/input01.txt
        string testout = "Testcases/output/output" + add + to_string(t) + ".txt"; // filename
        ifstream cin(testin);
        ofstream cout(testout);
        int a, b;
        cin >> a >> b; cout << a + b;
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cout.tie(0); cin.tie(0);
    solve();
    return 0;
}
