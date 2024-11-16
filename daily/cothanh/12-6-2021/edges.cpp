#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m1, m2, scc, timeDfs, S, T;
vector<pi> adj[N], g[N];
int num[N], low[N], deleted[N], deg[N], id[N];
ll d[N], ans = 0;
stack<int> st;

void dfs(int u){
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (auto it : adj[u]){
        int v = it.fi;
        if ( deleted[v] ) continue;
        if ( !num[v] ){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if ( low[u] == num[u] ){
        scc ++; int v;
        do{
            v = st.top();
            st.pop();
            deleted[v] = true;
            id[v] = scc;
        }
        while ( v != u );
    }
}

void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= scc; i ++) d[i] = oo;
    d[T] = 0; heap.push({d[T], T});
    while ( heap.size() ){
        int u = heap.top().se; ll du = heap.top().fi;
        heap.pop();
        if ( du != d[u] ) continue;
        for (auto it : g[u]){
            int v = it.fi, w = it.se;
            if ( d[v] > du + w ){
                d[v] = du + w;
                heap.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("edges.inp", "r", stdin);
    freopen("edges.out", "w", stdout);

    cin >> n >> m1;
    for (int i = 1; i <= m1; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, 0});
    }

    for (int i = 1; i <= n; i ++)
        if ( !num[i] ) dfs(i);

    for (int u = 1; u <= n; u ++)
        for (auto it : adj[u]){
            if ( id[u] == id[it.fi] ) continue;
            g[id[u]].pb({id[it.fi], it.se});
            deg[id[it.fi]] ++;
        }

    for (int i = 1; i <= scc; i ++){
        if ( !deg[i] ) S = i;
        if ( !g[i].size() ) T = i;
    }

    for (int i = 1; i <= n; i ++) adj[i].clear();
    cin >> m2;
    for (int i = 1; i <= m2; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        if ( w < 0 ) ans += w, w = 0;
        adj[u].pb({v, w});
    }

    //cout << scc << '\n';

    for (int u = 1; u <= n; u ++)
        for (auto it : adj[u])
            g[id[u]].pb({id[it.fi], it.se});

    //cout << S << ' ' << T << '\n';

    dijkstra();
    if ( d[S] != oo ){
        cout << "YES\n";
        cout << d[S] + ans;
    }
    else{
        cout << "NO";
    }

    return 0;
}
