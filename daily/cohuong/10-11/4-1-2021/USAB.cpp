//    Code by dungdq
#include <bits/stdc++.h>
#define TASK "usab"
using namespace std;

typedef pair < int, int > ii;
#define fi first
#define se second

const int N = 105;

ii a[N];
int p[N], k[N];
int m, lim, res;

void btrk (int id, int mul) {
    if (id > m) { res += (mul <= lim); return; }
    if (1LL * p[id] * mul > 1LL * lim) { res += (mul <= lim); return; }
    for (int t = 0, Pow = 1; t <= k[id]; t++) {
        if (1LL * mul * Pow > 1LL * lim) break;
        btrk (id + 1, mul * Pow);
        if (1LL * Pow * p[id] > 1LL * lim) break;
        Pow *= p[id];
    }
}

int solve (int n) {
    res = 0, lim = n;
    btrk (1, 1);
    return res;
}

int main() {
    if (fopen ("main.in", "r"))
        freopen ("main.in", "r", stdin);
    else
        freopen (TASK".inp", "r", stdin),
        freopen (TASK".out", "w", stdout);

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].fi >> a[i].se;
    sort (a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++)
        p[i] = a[i].fi, k[i] = a[i].se;

    for (int t = 0; t < 3; t++) {
        int a, b; cin >> a >> b;
        cout << solve (b) - solve (a - 1) << '\n';
    }

    return 0;
}
