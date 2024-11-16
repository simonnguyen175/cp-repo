#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e6 + 1;

int n;
vector<int> adj[N], ans;
bool f[N];
int cnt[N];

void dfs(int u){
    f[u] = 0;
    for (int v : adj[u]){
        dfs(v);
        cnt[u] += f[v];
    }
    if ( !cnt[u] ) f[u] = 1;
}

void dfs1(int u){
    if ( f[u] ) ans.pb(u);

    int cntu, fu, cntv, fv;
    for (int v : adj[u]){
        cntu = cnt[u], fu = f[u], cntv = cnt[v], fv = f[v];

        if ( f[v] ) cnt[u] --;
        f[u] = !cnt[u];

        if ( f[u] ) cnt[v] ++;
        f[v] = !cnt[v];

        dfs1(v);

        cnt[u] = cntu, f[u] = fu, cnt[v] = cntv, f[v] = fv;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1, u; i < n; i ++){
        cin >> u;
        adj[u].pb(i+1);
    }

    dfs(1);
    dfs1(1);
    sort(ans.begin(), ans.end());
    for (int x : ans) cout << x << '\n';

    return 0;
}
