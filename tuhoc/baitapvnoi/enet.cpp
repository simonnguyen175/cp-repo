#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;

int tin[N], low[N];
bool was[N];

vector<int> adj[N];
set<int> answer;

int n, m, s, t;

void visit(int u) {
    was[u] = true;
    for (int v : adj[u]) if ( !was[v] ) visit(v);
}

bool sameComponent() {
    visit(s);
    return was[t];
}

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
                set<int> cur;

                while (S.top() != make_pair(u, v)) {
                    cur.insert(S.top().second);
                    //cout << S.top().second << ' ';
                    S.pop();
                }
                //cout << u << '\n';
                cur.insert(u); cur.insert(v); S.pop();

                if (cur.count(s) && cur.count(t)) {
                    //for (int u : cur) cout << u << ' '; cout << '\n';
                    answer = cur;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m >> s >> t;

    bool hasEdge = false;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
        hasEdge |= (u == s && v == t) || (u == t && v == s);
    }

    if ( !sameComponent() ) {cout << 0; return 0;}

    if ( !hasEdge ) adj[s].push_back(t), adj[t].push_back(s);

    for (int i = 1; i <= n; ++i)
        if ( !tin[i] ) dfs(i);

    //for (int i = 1; i <= n; i ++) cout << low[i] << ' ' << tin[i] << '\n';

    cout << answer.size() << '\n';
    for (int u : answer)
        cout << u << ' ';

    return 0;
}
