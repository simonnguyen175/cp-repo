#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, timeDfs = 0, scc = 0;
int num[N], low[N], del[N], root[N], vis[N], ans[N];
vector<int> g[N], adj[N], cont[N];
stack<int> st;
pi edges[N];
ll s[N];

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
            cont[scc].pb(v);
            st.pop();
            del[v] = 1;
        } while ( v != u );
    }
}

void topo(int u){
    vis[u] = 1;
    for (int v : adj[u])
        if ( !vis[v] ) dfs(v);
    st.push(u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("gnum.inp", "r") ){
        freopen("gnum.inp", "r", stdin);
        freopen("gnum.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        edges[i] = {u, v};
    }

    for (int i = 1; i <= n; i ++) s[i] = s[i-1] + 1LL*(i+1)*i/2;

    for (int i = 1; i <= n; i ++)
        if ( !num[i] ) dfs(i);

    for (int i = 1; i <= m; i ++)
        if ( root[edges[i].fi] != root[edges[i].se] )
            adj[root[edges[i].fi]].pb(root[edges[i].se]);

    for (int i = 1; i <= scc; i ++){
        sort(cont[i].begin(), cont[i].end());
        if ( !vis[i] ) topo(i);
    }

    int cnt = 0;
    while ( st.size() ){
        int u = st.top();
        for (int x : cont[u]) ans[x] = ++cnt;
        st.pop();
    }

    ll res = 0;
    for (int i = 1; i <= scc; i ++)
        res += s[cont[i].size()-1];

    cout << res << '\n';
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
