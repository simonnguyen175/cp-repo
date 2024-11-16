#include<bits/stdc++.h>
#define simon "dancer2"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, m, lim;
ll ans = 0;
int d[N];
vector<int> adj[N], g[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    lim = sqrt(m);

    for (int i = 1; i <= n; i ++)
        if ( adj[i].size() >= lim ){
            for (int x : adj[i]) d[x] = 1;
            for (int j = 1; j <= n; j ++){
                if ( j == i || ( j < i && adj[j].size() >= lim ) ) continue;
                ll cnt = 0;
                for (int x : adj[j]) cnt += d[x];
                ans += ( cnt * (cnt - 1) / 2 );
            }
            for (int x : adj[i]) d[x] = 0;
        }
        else{
            sort(adj[i].begin(), adj[i].end());
            for (int j = 0; j < adj[i].size(); j ++)
            for (int k = j + 1; k < adj[i].size(); k ++)
                g[adj[i][j]].pb(adj[i][k]);
        }

    for (int i = 1; i <= n; i ++){
        for (auto x : g[i]) ans += d[x], d[x] ++;
        for (auto x : g[i]) d[x] = 0;
    }

    cout << ans;

    return 0;
}
