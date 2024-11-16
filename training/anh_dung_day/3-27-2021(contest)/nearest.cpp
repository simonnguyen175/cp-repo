#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, m, dp[N], b, r, mil[N];
queue<int> q;
vector<int> adj[N];
bool visited[N];

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m >> b >> r;
    memset(visited, false, sizeof visited);
    for(int i = 1; i <= b; ++i){
        int pos;
        cin >> pos;
        visited[pos] = true; dp[pos] = 0;
        q.push(pos);
    }
    for(int i = 1; i <= r; ++i)
        cin >> mil[i];
    for(int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); ++i){
            int v=adj[u][i];
            if ( visited[v] ) continue;
            dp[v] = dp[u] + 1;
            visited[v] = true;
            q.push(v);
        }
    }
    for(int i = 1; i <= r; ++i)
        cout << dp[mil[i]] << ' ';
}
