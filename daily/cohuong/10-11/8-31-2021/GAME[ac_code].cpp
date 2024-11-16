#include <bits/stdc++.h>
using namespace std;

#define Fname "GAME"
void files() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen(Fname".inp", "r")) {
		freopen(Fname".inp", "r", stdin);
		freopen(Fname".out", "w", stdout);
	}
}

#define print(_v) for(auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
void ckmax(int &a, int b) {a = (a > b) ? a : b;}
void ckmin(int &a, int b) {a = (a < b) ? a : b;}

#define ll long long

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define fi first
#define se second

#define pb push_back
#define pf push_front
#define eb emplace_back

const int N = 1e6 + 5;
const int INF = 1e9 + 123;

int n, t, a[N], SPMax[N][21], SPMin[N][21], L[N], far[N], dp[N];

void build() {
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < 21; ++j) {
            SPMin[i][j] = INF;
            SPMax[i][j] = -INF;
        }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 21; ++j) {
            if((1 << j) > i) break;
            if(j == 0) SPMin[i][j] = SPMax[i][j] = a[i];
            else {
                int pos = i - (1 << j) + (1 << (j - 1));
                SPMin[i][j] = min(SPMin[pos][j - 1], SPMin[i][j - 1]);
                SPMax[i][j] = max(SPMax[pos][j - 1], SPMax[i][j - 1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int bit = 0;
        while((1 << (bit + 1)) <= i) ++bit;
        L[i] = bit;
    }
}

int get(int u, int v, int val) {
    int len = v - u + 1, bit = L[len];
    len = (1 << bit);
    return (max(SPMax[u + len - 1][bit], SPMax[v][bit])
            - min(SPMin[u + len - 1][bit], SPMin[v][bit]));
}

void solve() {
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build();
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int d = 1, c = i, ans = 1;
        while(d <= c) {
            int g = (d + c) / 2;
            if(get(i - g + 1, i, a[i]) <= t) ans = g, d = g + 1;
            else c = g - 1;
        }
        res = max(res, ans);
    }
    cout << res << '\n';
}

int main() {
	files();
	solve();
	return 0;
}
