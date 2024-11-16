#include <bits/stdc++.h>
#define TASK "num9"

using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int N = (int) 1e6 + 10;
const int inf = (int) 1e18;
int n, m;
int a[N], b[N];
int f[N];
bool mark[N];

int get(int x, int k) {
    return (x >> k) & 1;
}
void on(int &x, int k) {
    x |= (1 << k);
}
int turn(int x, int i, int j, int k) {
    on(x, i);
    on(x, j);
    on(x, k);
    return x;
}
int cal(int BIT, int numBIT) {
    if (mark[BIT]) return f[BIT];
    if (numBIT == 9) return 0;
    mark[BIT] = true;
    int &ans = f[BIT];
    ans = -inf;
    for(int i = 0; i < m; ++i) if (!get(BIT, i))
        for(int j = i+1; j < m; ++j) if (!get(BIT, j))
            for(int k = j+1; k < m; ++k) if (!get(BIT, k))
                ans = max(ans, b[i] * b[j] * b[k] + cal(turn(BIT, i, j, k), numBIT + 3));

    return ans;
}
main() {
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    fast;

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1, a+1+n);
    m = 0;
    for(int i = 1; i <= 6; ++i)
        b[m++] = a[i];
    for(int i = max(7LL, n-9+1); i <= n; ++i)
        b[m++] = a[i];
    cout << cal(0, 0);
}
