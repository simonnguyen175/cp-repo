#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, q, ans = 0;
vector<pi> adj[N];
int press[N], deg[N], cntBlue[N];

bool cmp(pi a, pi b){
    return deg[a.fi] > deg[b.fi];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("light5.inp", "r") ){
        freopen("light5.inp", "r", stdin);
        freopen("light5.out", "w", stdout);
    }

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        cntBlue[u] += w, cntBlue[v] += w;
        deg[u] ++, deg[v] ++;
        ans += w;
    }

    for (int i = 1; i <= n; i ++)
        sort(adj[i].begin(), adj[i].end(), cmp);

    int lim = sqrt(m);

    while ( q -- ){
        int u; cin >> u;
        press[u] ++;
        if ( deg[u] <= lim ){
            for (auto it : adj[u]){
                int v = it.fi;
                int tmp = ( it.se + press[u] + press[v] ) % 2;
                ans += ( tmp ? 1 : -1 );
                if ( deg[v] > lim ) cntBlue[v] += ( tmp ? 1 : -1 );
            }
        }
        else{
            ans += deg[u] - 2 * cntBlue[u];
            cntBlue[u] = deg[u] - cntBlue[u];
            for (auto it : adj[u]){
                int v = it.fi;
                int tmp = ( it.se + press[u] + press[v] ) % 2;
                if ( deg[v] <= lim ) break;
                cntBlue[v] += ( tmp ? 1 : -1 );
            }
        }
        cout << ans << ' ';
    }

    return 0;
}
