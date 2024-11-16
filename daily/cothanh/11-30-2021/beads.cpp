#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200005;
const ll INF = 1e9;

ll dp[N][2][2];
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
    ll best0 = -INF, best1 = -INF, best01 = -INF, best11 = -INF;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v == p) continue; dfs(v, u);
        ll tmp = max(dp[v][0][0], dp[v][1][0] + w);
        dp[u][0][0] += tmp;
        best11 = max(best11, max(dp[v][0][1], dp[v][1][1] + w) - tmp);
        best01 = max(best01, max(best0 + max(dp[v][0][0], dp[v][0][1]) + w, best1 + dp[v][0][0] + w) - tmp);
        best0 = max(best0, dp[v][0][0] + w - tmp);
        best1 = max(best1, dp[v][0][1] + w - tmp);
    }
    dp[u][0][1] = dp[u][1][0] = dp[u][1][1] = dp[u][0][0];
    dp[u][1][0] += best0; dp[u][1][1] += best1;
    dp[u][0][1] = max(dp[u][0][1] + best11, dp[u][0][0] + best01);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 0); cout << max(dp[1][0][0], dp[1][0][1]);
}
