#include<bits/stdc++.h>
#define simon "race"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k;
vector<ii> adj[N];
priority_queue<ll> d[N];

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    priority_queue<ii, vector<ii>, greater<ii>> heap;
    d[1].push(0); heap.push({0, 1});

    while ( !heap.empty() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du > d[u].top() ) continue;

        for (auto it : adj[u] ){
            int v = it.se;
            int w = it.fi;
            ll newDist = w + du;

            if ( d[v].size() < k ){
                d[v].push(newDist);
                heap.push({newDist, v});
            }
            else
                if ( d[v].top() > newDist ){
                    d[v].pop();
                    d[v].push(newDist);
                    heap.push({newDist, v});
                }
        }
    }

    vector<ll> ans;
    while ( d[n].size() ){
        ans.push_back(d[n].top());
        d[n].pop();
    }

    for (int i = ans.size() - 1; i >= 0; i --)
        cout << ans[i] << ' ';

    return 0;
}
