#include<bits/stdc++.h>
#define simon "TourU"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, k, s, f;
ll d[N], dp[N], longestPath;
bool des[N];
vector<ii> adj[N];

void DFStoD(int u, int pu){
    for (auto x : adj[u]){
        int v = x.fi;
        int uv = x.se;
        if ( v == pu ) continue;
        d[v] = d[u] + uv;
        DFStoD(v, u);
    }
}

void DFStoDP(int u, int pu){
    for (auto x : adj[u]){
        int v= x.fi;
        int uv = x.se;
        if ( v == pu ) continue;

        DFStoDP(v, u);

        if ( dp[v] > 0 || des[v] ) dp[u] += dp[v] + 2 * uv;
        cout << dp[u] << ' ' << v << "->" << u << '\n';
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n-1; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cin >> s >> k;
    for (int i = 1; i <= k; i ++){
        cin >> f;
        des[f] = 1;
    }

    DFStoD(s, 0);

    for (int i = 1; i <= n; i ++){
        if ( des[i] ) longestPath = max(longestPath, d[i]);
        cout << d[i] << ' ';
    }
    cout << '\n';

    DFStoDP(s, 0);

    cout << dp[s] << '\n';

    cout << dp[s] - longestPath;

    return 0;
}
