#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
bool vis[N];
vector <int> ver;
int a[N][N], Queue[N];

void bfs(int s) {
    /// khoi tao
    for (int i = 1; i <= n; i++)
        vis[i] = false;

    /// day S vao queue
    vis[s] = true;
    int L = 1, R = 0;
    Queue[++R] = s;

    /// while queue khac rong
    while (L <= R) {
        int u = Queue[L++];
        ver.push_back (u);
        for (int v = 1; v <= n; v++) if (a[u][v]) {
            if (vis[v]) continue;
            vis[v] = true;
            Queue[++R] = v;
        }
    }
}

int main() {
    freopen ("graph.inp", "r", stdin);
    freopen ("graph.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }

    bfs(1);

    cout << ver.size() << '\n';
    for (int i = 0; i < (int) ver.size(); i++)
        cout << ver[i] << ' ';

    return 0;
}
