#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, m;
vector<pi> g[N];
int d[N], c[N], deg[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        g[u].pb({v, i});
        g[v].pb({u, i});
        deg[u] ++;
        deg[v] ++;
    }

    for (int i = 1; i <= n; i ++)
        sort(g[i].begin(), g[i].end(), [&](pi a, pi b){
            if ( deg[a.fi] == deg[b.fi] )
                return a.fi > b.fi;
            return deg[a.fi] > deg[b.fi];
        });

    for (int i = 1; i <= n; i ++){
        for (auto it : g[i]) d[it.fi] = it.se;

        for (auto it : g[i]){
            int j = it.fi;
            if ( deg[j] < deg[i] || ( deg[j] == deg[i] && j < i ) ) break;
            for (auto it1 : g[j]){
                int k = it1.fi;
                if ( deg[k] < deg[j] || ( deg[k] == deg[j] && k < j ) ) break;
                if ( d[k] ){
                    c[it.se] ++, c[it1.se] ++;
                    c[d[k]] ++;
                }
            }
        }

        for (auto it : g[i] ) d[it.fi] = 0;
    }

    ll ans = 0;
    for (int i = 1; i <= m; i ++)
        ans += 1ll * c[i] * (c[i] - 1) / 2;
    cout << ans;

    return 0;
}
