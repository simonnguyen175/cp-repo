#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n, m, scc, timeDfs;
vector<int> adj[N], g[N];
pi edg[N];
int num[N], low[N], id[N], sz[N];
bool del[N], ck[N], vis[N];
stack<int> st;

void dfs(int u){
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (int v : adj[u]){
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
            st.pop();
            del[v] = 1;
            id[v] = scc;
            sz[scc] ++;
        }while ( v != u );
    }
}

void go(int u){
    vis[u] = 1;
    for (int v : g[u]){
        if ( !vis[v] ) go(v);
        ck[u] |= ck[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        edg[i] = {u, v};
    }

    for (int i = 1; i <= n; i ++)
        if ( !num[i] ) dfs(i);

    for (int i = 1; i <= m; i ++)
        g[id[edg[i].fi]].pb(id[edg[i].se]);

    for (int i = 1; i <= scc; i ++)
        if ( sz[i] > 1 ) ck[i] = 1;

    for (int i = 1; i <= scc; i ++)
        if ( !vis[id[i]] && !ck[id[i]] ) go(id[i]);

    int ans = 0;
    for (int i = 1; i <= n; i ++)
        if ( ck[id[i]] ) ans ++;

    cout << ans;

    return 0;
}
