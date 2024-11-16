#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const ll oo = 1e18;

int n;
vector<int> g[N], adj[N];
ll ans = oo;
int vis[N];
ll sal[N];

void calc(int u){
    sal[u] = 1;
    for (int v : adj[u]) calc(v), sal[u] += sal[v];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("comp.inp", "r") ){
        freopen("comp.inp", "r", stdin);
        freopen("comp.out", "w", stdout);
    }

    cin >> n;
    for (int i = 1, k; i <= n; i ++){
        cin >> k;
        for (int j = 1, x; j <= k; j ++)
            cin >> x, g[x].pb(i);
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++)
            vis[j] = 0, sal[j] = 0, adj[j].clear();

        queue<int> q;
        q.push(i), vis[i] = 1;
        int cnt = 0;

        while ( q.size() ){
            int u = q.front();
            cnt ++;
            q.pop();
            for (int v : g[u]) if ( !vis[v] ){
                vis[v] = 1;
                q.push(v);
                adj[u].pb(v);
            }
        }

        if ( cnt == n ){
            ll tmp = 0;
            calc(i);
            for (int j = 1; j <= n; j ++) tmp += sal[j];
            ans = min(ans, tmp);
        }
    }

    cout << ans;

    return 0;
}
