#include<bits/stdc++.h>
#define pb push_back
#define BIT(x, k) ((x>>k)&1)
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 20;
const int oo = 1e9;

int n, m;
vector<int> adj[N];
int d[1<<15][16];

void ckmn(int &a, int b){
    a = min(a, b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        u --, v --;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int t = 1; t < (1<<n); t ++)
    for (int i = 0; i < n; i ++)
        d[t][i] = oo;
    queue<pi> q;
    for (int i = 0; i < n; i ++)
        d[1<<i][i] = 0, q.push({1<<i, i});
    while ( q.size() ){
        int t = q.front().fi;
        int u = q.front().se;
        q.pop();

        for (int v : adj[u])
            if ( d[t|(1<<v)][v] == oo ){
                d[t|(1<<v)][v] = d[t][u] + 1;
                q.push({(t|(1<<v)), v});
            }
    }

    int ans = oo;
    for (int i = 0; i < n; i ++)
        ans = min(ans, d[(1<<n)-1][i]);

    cout << ans;

    return 0;
}
