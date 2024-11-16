#include <bits/stdc++.h>
using namespace std;

#define Fname "lazycows"
void files() {
	if(fopen(Fname".inp", "r")) {
		freopen(Fname".inp", "r", stdin);
		freopen(Fname".out", "w", stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

#define ll long long

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
#define fi first
#define se second

#define pb push_back
#define pf push_front
#define eb emplace_back

const int N = 1e3 + 5;
const ll INF = 1e8;

int n, t, k, B;
ll dp[N][4][N];

pair<int, int> a[N];
bool cmp(pii x, pii y) {
    return x.se < y.se;
}

struct ps {
    bool l[3];
    int vt;
} b[N];

int cnt;
void solve() {
    cin >> n >> k >> B;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, cmp);

    cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ++cnt;

        for (int i = 1; i < 3; ++i) b[cnt].l[i] = false;
        b[cnt].vt = a[i].se;

        if(i + 1 <= n && a[i].se == a[i + 1].se) {
            b[cnt].l[1] = true; b[cnt].l[2] = true;
            ++i;
        }
        else b[cnt].l[a[i].fi] = true;
    }

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 4; ++j)
            for (int d = 0; d <= k; ++d)
                dp[i][j][d] = INF;
    for (int i = 0; i < 4; ++i)
        dp[0][i][0] = 0;

    b[0].vt = -INF;
    for (int i = 1; i <= cnt; ++i)
        for (int j = 1; j <= k; ++j) {
            ll ans, dist = b[i].vt - b[i - 1].vt;

            // case 0
            if(!b[i].l[2]) {
                ans = INF;
                ans = min(ans, min(dp[i - 1][0][j] + dist, dp[i - 1][0][j - 1] + 1));
                ans = min(ans, dp[i - 1][1][j - 1] + 1);
                ans = min(ans, min(dp[i - 1][2][j] + dist, dp[i - 1][2][j - 1] + 1));
                ans = min(ans, dp[i - 1][3][j - 1] + 1);
                dp[i][0][j] = ans;
            }

            // case 1
            if(!b[i].l[1]) {
                ans = INF;
                ans = min(ans, dp[i - 1][0][j - 1] + 1);
                ans = min(ans, min(dp[i - 1][1][j] + dist, dp[i - 1][1][j - 1] + 1));
                ans = min(ans, min(dp[i - 1][2][j] + dist, dp[i - 1][2][j - 1] + 1));
                ans = min(ans, dp[i - 1][3][j - 1] + 1);

                dp[i][1][j] = ans;
            }

            // case 2
            ans = INF;
            ans = min(ans, min(dp[i - 1][0][j - 1], dp[i - 1][1][j - 1]) + dist + 1);
            if(j >= 2)
                ans = min(ans, min(dp[i - 1][0][j - 2], dp[i - 1][1][j - 2]) + 2);

            if(j >= 2) ans = min(ans, dp[i - 1][2][j - 2] + 2);
            ans = min(ans, dp[i - 1][2][j - 1] + dist + 1);
            ans = min(ans, dp[i - 1][2][j] + 2 * dist);

            if(j >= 2) ans = min(ans, dp[i - 1][3][j - 2] + 2);

            dp[i][2][j] = ans;

            // case 3
            ans = INF;
            ans = min(ans, min(dp[i - 1][0][j - 1], dp[i - 1][1][j - 1]) + 2);

            ans = min(ans, dp[i - 1][2][j - 1] + 2);

            ans = min(ans, dp[i - 1][3][j] + 2 * dist);
            ans = min(ans, dp[i - 1][3][j - 1] + 2);

            dp[i][3][j] = ans;
        }

    ll res = INF;
    if(!b[cnt].l[2]) res = min(res, dp[cnt][0][k]);
    if(!b[cnt].l[1]) res = min(res, dp[cnt][1][k]);
    res = min(res, min(dp[cnt][2][k], dp[cnt][3][k]));

    cout << res << '\n';
}

int main() {
	files();
    cin >> t;
    while(t--)
        solve();
	return 0;
}
