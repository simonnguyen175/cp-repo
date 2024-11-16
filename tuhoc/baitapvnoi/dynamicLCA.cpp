#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, m;
vector<int> adj[N];
int d[N], p[N][22];

void dfs(int u, int pu){
    for (int i = 1; i <= log2(n); i ++)
        p[u][i] = p[p[u][i-1]][i-1];
    for ( auto v : adj[u] ){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if ( x == 1 || y == 1 ) return 1;
    if ( d[x] < d[y] ) swap(x, y);

    int diff = d[x] - d[y];

    for (int i = log2(n) ; i >= 0; i --)
        if ( d[p[x][i]] >= d[y] )
            x = p[x][i];

    if ( x == y ) return x;

    for (int i = log2(n); i >= 0; i --)
        if ( p[x][i] != p[y][i] ){
            x = p[x][i];
            y = p[y][i];
        }

    return p[x][0];
}


void solve(){
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    int root = 1;

    cin >> m;

    for (int i = 1; i <= m; i ++){
        char type;

        cin >> type;



        if ( type == '!' ){
            int newRoot;
            cin >> newRoot;
            root = newRoot;
        }

        if ( type == '?' ){
            int u, v;
            cin >> u >> v;

            int defLca = lca(u, v);
            int lcaru = lca(root, u);
            int lcarv = lca(root, v);


            if ( d[lcaru] == d[lcarv] ){
                cout << defLca << '\n';
            }
            else{
                if ( d[lcaru] > d[lcarv] ) cout << lcaru << '\n';
                else cout << lcarv << '\n';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    while (cin >> n ){
        if ( n == 0 ) return 0;
        memset(p, 0, sizeof p);
        memset(d, 0, sizeof d);
        for (int i = 1; i <= n; i ++) adj[i].clear();
        solve();
    }
    return 0;
}
