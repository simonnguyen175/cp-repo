#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, m, timeDfs, scc;
int num[N], low[N], del[N], root[N];
int vis[N], out[N], id[N], bit[N];
bool ck[2][N];
vector<int> g[N], adj[2][N], cont;
stack<int> st;
pi edges[N];

void dfs(int u){
    num[u] = low[u] = ++timeDfs;

    st.push(u);

    for (int v : g[u]){
        if ( del[v] ) continue;
        if ( !num[v] ){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if ( low[u] == num[u] ){
        scc ++;
        int v;
        do{
            v = st.top();
            root[v] = scc;
            st.pop();
            del[v] = 1;
        }
        while ( v != u );
    }
}

void dfs1(int u){
    vis[u] = 1;
    for (int v : adj[0][u])
        if ( !vis[v] ) dfs1(v);
    cont.pb(u);
}

void update(int u, int v){
    for (; u <= n; u += u&(-u))
        bit[u] += v;
}

int get(int u){
    int res = 0;
    for (; u > 0; u -= u&(-u))
        res += bit[u];
    return res;
}

void topo(int t){
    for (int i = 1; i <= scc; i ++){
        adj[0][i].clear(), adj[1][i].clear();
        out[i] = bit[i] = 0;
    }

    for (int i = 1; i <= m; i ++){
        adj[t][root[edges[i].fi]].pb(root[edges[i].se]);
        if ( t == 0 ) out[root[edges[i].fi]] ++;
        else out[root[edges[i].se]] ++;
        adj[1-t][root[edges[i].se]].pb(root[edges[i].fi]);
    }

    if ( t ) reverse(cont.begin(), cont.end());

    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    for (int i = 1; i <= scc; i ++)
        if ( out[i] > 0 ) update(id[i], 1);

    for (int i = cont.size()-1; i >= 0; i --){
        if ( get(i) == i ) ck[t][cont[i]] = 1;
        for (int v : adj[1][cont[i]])
            if ( --out[v] == 0 ) update(id[v], -1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("drumuri.inp", "r") ){
        freopen("drumuri.inp", "r", stdin);
        freopen("drumuri.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        edges[i] = {u, v};
    }

    for (int i = 1; i <= n; i ++)
        if ( !num[i] ) dfs(i);

    for (int i = 1; i <= m; i ++){
        adj[1][root[edges[i].fi]].pb(root[edges[i].se]);
        adj[0][root[edges[i].se]].pb(root[edges[i].fi]);
    }

    for (int i = 1; i <= scc; i ++)
        if ( !vis[i] ) dfs1(i);

    topo(0);
    topo(1);

    vector<int> ans;
    for (int i = 1; i <= n; i ++)
        if ( ck[0][root[i]] && ck[1][root[i]] ) ans.pb(i);

    cout << ans.size() << '\n';
    for (int u : ans) cout << u << ' ';

    return 0;
}
