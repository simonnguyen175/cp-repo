#include<bits/stdc++.h>
#define pb push_back
using namespace std;
random_device dev;
mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());
const int N = 3e5 + 5;

int n, ans, res;
vector<int> adj[N];
int c[N], a[N], child[N], trie[N][26];

void Insert(int cur, int u){
    for (int i = 0; i <= 25; i ++) if ( trie[cur][i] ){
        if ( trie[u][i] ) Insert(trie[cur][i], trie[u][i]);
    }
    else if ( trie[u][i] ) trie[cur][i] = trie[u][i];

    child[cur] = 1;
    for (int i = 0; i < 26; i ++)
        child[cur] += child[trie[cur][i]];
}

void dfs(int u, int pu){
    child[u] = 1;

    for (int v : adj[u]) if ( v != pu ){
        dfs(v, u);
        if ( trie[u][a[v]] ) Insert(trie[u][a[v]], v);
        else trie[u][a[v]] = v;
    }

    for (int i = 0; i <= 25; i ++) child[u] += child[trie[u][i]];
    if ( c[u] + child[u] > ans ){
//        cout << u << ' ' << c[u] << ' ' << child[u] << '\n';
        ans = c[u] + child[u];
        res = 1;
    }
    else if ( c[u] + child[u] == ans ) res ++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= n; i ++){
        char x;
        cin >> x;
        a[i] = x - 'a';
    }

    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    cout << ans << '\n' << res;

    return 0;
}
