#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

struct canh{
    int u, v;
    long long w;
};

struct query{
    int a, b;
    long long k;
    int id;
};

int t, n, m, nt;
vector<int> adj[N];
long long cmpTree[N], pos[N], gr[N];
canh edge[N];
query q[N];
long long bit[N], ans[N];

bool cmpc(canh a, canh b){
    return a.w < b.w;
}

bool cmpq(query x, query y){
    return x.k < y.k;
}

void dfs(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        cmpTree[++nt] = v;
        pos[v] = nt;
        dfs(v, u);
        gr[v] = nt;
    }
}

void init(){
    cin >> n;
    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1; i <= n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i] = {u, v, w};
    }

    cin >> m;
    for (int i = 1; i <= m; i ++){
        int a, b, k;
        cin >> a >> b >> k;
        q[i] = {a, b, k, i};
    }
    nt = 0; cmpTree[++nt] = 1; pos[1] = 1; gr[1] = n;
    dfs(1, 0);
    sort(edge + 1, edge + n, cmpc);
    sort(q + 1, q + 1 + m, cmpq);

    cout << '\n';
    for (int i = 1; i <= n; i ++)
        cout << i << ' ' << pos[i] << ' ' << gr[i] << '\n';
    cout << '\n';
}

void update(int u, int v){
    int idx = u;
    while ( idx <= n ){
        bit[idx] ^= v;
        idx += idx & (-idx);
    }
}

long long get(int p){
    int idx = p;
    long long res = 0;
    while ( idx > 0 ){
        res ^= bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}

void solve(){
    init();
    memset(bit, 0, sizeof bit);
    int j = 1;
    for (int i = 1; i <= m; i ++){
        while ( edge[j].w <= q[i].k && j <= n - 1){
            int u = edge[j].u, v = edge[j].v;
            if ( pos[v] > pos[u] ) update(pos[v], edge[j].w), update(gr[v] + 1, edge[j].w);
            else update(pos[u], edge[j].w), update(gr[u] + 1, edge[j].w);
            j ++;
        }
        ans[q[i].id] = ( get(pos[q[i].a]) ^ get(pos[q[i].b]) );
    }

    for (int i = 1; i <= m; i ++)
        cout << ans[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    while ( t -- ){
        solve();
    }
}
