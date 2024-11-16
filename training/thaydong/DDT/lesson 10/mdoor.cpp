#include <bits/stdc++.h>
using namespace std;

#define Fname "mdoor"

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

const ll INF = 1e15;
const int X[] = {-1, -1, -1};
const int Y[] = {-1, 0, 1};

int m, n, C;
ll dp[N][N], pi[N][N], f[N][N], cntX = -INF, cntY = -INF, cntZ = -INF;
bool dor[N][N];

bool inmap(int x, int y) {
    return (x >= 0 && x <= m && y >= 1 && y <= n);
}

void solve() {
    cin >> m >> n >> C;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> dor[i][j];
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> pi[i][j];

    // X + (c - 1) * Y + Z
    // cal X
    for (int i = 1; i <= n; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = -INF;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < 3; ++k) {
                int u = i + X[k], v = j + Y[k];
                if(!inmap(u, v)) continue;

                dp[i][j] = max(dp[i][j], dp[u][v] + pi[i][j]);
            }
            if(dor[i][j]) cntX = max(cntX, dp[i][j]);
        }

    // cal Y, Z;
     for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
            f[i][j] = -INF;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j) {
            if(dor[i][j]) f[i][j] = pi[i][j];
            for (int k = 0; k < 3; ++k) {
                int u = i + X[k], v = j + Y[k];
                if(!inmap(u, v)) continue;

                f[i][j] = max(f[i][j], f[u][v] + pi[i][j]);
            }
            if(dor[i][j]) cntY = max(cntY, f[i][j]);
        }

    // combine res
    ll res = -INF;
    for (int i = 1; i <= n; ++i) {
        res= max(res, dp[m][i]);
        cntZ = max(cntZ, f[m][i]);
    }


    if(C > 0) res = max(res, cntX + (C - 1) * cntY + cntZ);
    cout << res;
}

int main() {
	files();
	solve();
	return 0;
}
