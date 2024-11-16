#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long inv2;

int Power(int a, int b) {
    if (b == 0) return 1;
    int t = Power(a, b/2);
    if (b % 2 == 0)
        return 1LL * t * t % MOD;
    return 1LL * t * t % MOD * a % MOD;
}

long long cal(long long w, long long h) {
    return w * (w+1) % MOD * inv2 % MOD * (h+1) % MOD * h % MOD * inv2  % MOD;
}

void add(long long &a, long long b) {
    a = ((a + b) % MOD + MOD) % MOD;
}

int32_t main() {
    freopen ("fence.inp", "r", stdin);
    freopen ("fence.out", "w", stdout);

    inv2 = Power(2, MOD-2);

    int n; cin >> n;
    vector <int> h(n+2);
    vector <long long> w(n+1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        add(w[i], w[i-1]);
    }

    vector <int> l(n+1);
    stack <int> st; st.push(0);
    for (int i = 1; i <= n; i++) {
        while (st.size() && h[st.top()] > h[i]) st.pop();
        l[i] = st.top(); st.push(i);
    }

    while(st.size()) st.pop(); st.push(n+1);
    vector <int> r(n+1);
    for (int i = n; i >= 1; i--) {
        while (st.size() && h[st.top()] >= h[i]) st.pop();
        r[i] = st.top(); st.push(i);
    }

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << l[i] << ' ' << r[i] << '\n';
        int L = l[i] + 1, R = r[i] - 1;
        long long W = (w[R] + MOD - w[L-1]) % MOD;
        add(res, cal(W, h[i]));
        add(res, -cal(W, max(h[L-1], h[R+1])));
    }

    cout << res << '\n';

    return 0;
}
