#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, q;
vector<int> adj[N];
int d[N], p[N][20];
int x, y, a, b, k;

void dfs(int u, int pu){
    for (int i = 1; i <= log2(n); i ++)
        p[u][i] = p[p[u][i-1]][i-1];
    for (auto v : adj[u]){
        if ( v == pu ) continue;
        d[v] = d[u] + 1;
        p[v][0] = u;
        dfs(v, u);
    }
}

int lca(int x, int y){
    if ( x == 1 || y == 1 ) return 1;
    if ( d[x] < d[y] ) swap(x, y);

    int diff = d[x] - d[y];

    for (int i = log2(n); i >= 0; i --)
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

int dis(int u, int v){
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

bool check(int len){
    return ( len <= k && ( len + k ) % 2 == 0 );
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cin >> q;
    for (int i = 1; i <= q; i ++){
        cin >> x >> y >> a >> b >> k;
        int opt1 = dis(a,x) + 1 + dis(y,b);
        int opt2 = dis(a,y) + 1 + dis(x,b);
        int opt3 = dis(a,b);
        //cout << opt1 << ' ' << opt2 << ' ' << opt3 << '\n';
        if ( check(opt1) || check(opt2) || check(opt3) ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
