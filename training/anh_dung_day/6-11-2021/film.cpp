#include<bits/stdc++.h>
#define simon "film"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<long long, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int n, m;
vector<ii> adj[N];
long long a[N], d[N];

void solve(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (int i = 1; i <= n; i ++)
        d[i] = a[i];

    for (int i = 1; i <= n; i ++)
        pq.push({d[i], i});

    while ( !pq.empty() ){
        int u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();

        for (auto x : adj[u]){
            int v = x.fi;
            int uv = x.se;

            if ( d[v] > du + 2*uv ){
                d[v] = du + 2*uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    solve();

    for (int i = 1; i <= n; i ++)
        cout << d[i] << ' ';

    return 0;
}
