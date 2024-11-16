#include <bits/stdc++.h>
#define ld long double
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 5;

const ld INF = 1e15;

int n, opt[N];
pair<ld, ld> a[N];
ld F[7][N];

ld sqr(ld x){
    return x*x;
}

ld W(int x, int y) {
    return sqrt(sqr(a[x].fi - a[y].fi) + sqr(a[x].se - a[y].se));
}

void calc(int k, int l, int r, int optL, int optR) {
    if(l > r) return;
    int mid = (l + r) / 2;

    for (int i = optL; i <= min(optR, mid - 1); ++i) {
        ld newVal = F[k - 1][i] + W(i, mid);
        if(F[k][mid] < newVal) {
            opt[mid] = i;
            F[k][mid] = newVal;
        }
    }

    calc(k, l, mid - 1, optL, opt[mid]);
    calc(k, mid + 1, r, opt[mid], optR);
}

int main() {
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i].fi >> a[i].se;

    for (int id = 1; id <= n; id ++){
        for (int i = 0; i < 7; ++i)
            for (int j = 0; j <= n; ++j)
                F[i][j] = -INF;
        F[1][1] = 0;

        for (int i = 2; i <= 6; ++i)
            calc(i, 1, n, 1, n);

        ld res = 0;
        for (int i = 6; i <= n; ++i)
            res = max(res, F[6][i] + W(1, i));
        cout << fixed << setprecision(15) << res << '\n';

        a[n + 1] = a[1];
        for (int i = 1; i <= n; ++i) a[i] = a[i + 1];
    }
}
