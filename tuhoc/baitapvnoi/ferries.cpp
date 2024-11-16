#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m;
vector<int> adj[N], edg[N];
ll d[N];


void dijkstra(){
    priority_queue<pi, vector<pi>, greater<pi>> heap;
    for (int i = 1; i <= n; i ++){
        d[i] = oo;
        sort(edg[i].begin(), edg[i].end());
    }

    d[n] = 0;
    heap.push({0, n});
    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;
        heap.pop();

        if ( du != d[u] ) continue;

        for (int v : adj[u]){
            if ( d[v] > d[u] + edg[v].back() ){
                d[v] = d[u] + edg[v].back();
                heap.push({d[v], v});
            }
            edg[v].pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[v].pb(u);
        edg[u].pb(w);
    }

    dijkstra();

    cout << d[1];

    return 0;
}
