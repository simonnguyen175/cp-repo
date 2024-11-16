#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e9 + 7;

int n, m, timeDfs, scc;
vector<int> g[N];
int num[N], low[N], del[N], sz[N];
struct edg{
    int u, v, w;
} edges[N];
stack<int> st;

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
            sz[scc] ++;
            del[v] = 1;
            v = st.top();
            st.pop();
        } while ( v != u );
    }
}

bool check(int l, int r){
    for (int i = 1; i <= n; i ++)
        g[i].clear(), num[i] = low[i] = 0, del[i] = 0, sz[i] = 0;
    timeDfs = scc = 0;


    for (int i = l; i <= r; i ++)
        g[edges[i].u].pb(edges[i].v);

    dfs(1);

    return ( scc == 1 && sz[1] == n );
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("scc.inp", "r", stdin);
    freopen("scc.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges+1, edges+1+m, [](edg &a, edg &b){
        return a.w < b.w;
    });

    if ( n == 1 ) return cout << 0, 0;

    int ans = oo, it = 1;
    for (int i = 1; i <= m; i ++){
        int res = -1;
        while ( check(it, i) && it <= i )
            res = it, it ++;
        if ( res != -1 )
            ans = min(ans, edges[i].w - edges[res].w);
    }

    if ( ans == oo ) cout << -1;
    else cout << ans;

    return 0;
}
