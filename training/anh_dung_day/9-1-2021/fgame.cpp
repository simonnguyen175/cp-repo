#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 255;

int n, m = 0, t = 1;
int a[N][N], id[N][N];
int c[N*N], cnt[N*N], tt[N*N];
int row[] = {0, 0, 1, -1};
int col[] = {1, -1, 0, 0};
vector<int> adj[N*N], color[1000005];
vector<pair<int, int>> cont;
map<int, int> d[1000005];

void dfs(int i, int j){
    if ( id[i][j] ) return;

    if ( i < 1 || j < 1 || i > n || j > n ) return;

    cnt[m] ++;
    id[i][j] = m;

    for (int k = 0; k < 4; k ++){
        int x = i + row[k], y = j + col[k];
        if ( a[x][y] == a[i][j] ) dfs(x, y);
        else if ( id[x][y] ){
            int u = id[i][j], v = id[x][y];

            auto it1 = find(adj[u].begin(), adj[u].end(), v);
            auto it2 = find(adj[v].begin(), adj[v].end(), u);
            if ( it1 == adj[u].end() ) adj[u].pb(v);
            if ( it2 == adj[v].end() ) adj[v].pb(u);

            if ( c[u] > c[v] ) swap(u, v);
            if ( !d[c[u]][c[v]] ){
                cont.pb({c[u], c[v]});
                d[c[u]][c[v]] = 1;
            }
        }
    }
}

int get(int id, int u, int v){
    tt[id] = t;
    int res = cnt[id];
    for (int nxt : adj[id]){
        if ( tt[nxt] == t ) continue;
        if ( c[nxt] != u && c[nxt] != v ) continue;
        res += get(nxt, u, v);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j];

    memset(id, 0, sizeof id);
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= n; j ++){
        if ( !id[i][j] ){
            ++ m;
            c[m] = a[i][j];
            color[a[i][j]].pb(m);
            dfs(i, j);
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i ++) ans = max(ans, cnt[i]);

    cout << ans << '\n';

    ans = 0;

    for (auto it : cont){
        int u = it.first, v = it.second;
        for (int id : color[u]){
            if ( tt[id] == t ) continue; t ++;
            ans = max(ans, get(id, u, v));
        }
    }

    cout << ans << '\n';

    return 0;
}
