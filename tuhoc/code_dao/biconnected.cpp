#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int tin[N], low[N];
bool was[N];
vector<int> adj[N];
int n, m, s, t;
stack<pair<int, int> > S;
int Time;

void dfs(int u, int p = 0) {
    tin[u] = ++Time; low[u] = N;
    for (int v : adj[u]) if (v != p) {
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        }else{
            S.push({u, v});
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] >= tin[u]) {
                cout << "get biconnected : ";
                while (S.top() != make_pair(u, v)) {
                    cout << S.top().second << ' ';
                    S.pop();
                }

                cout << u << '\n';

                S.pop();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        if ( !tin[i] ) dfs(i);

    return 0;
}
