#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 5;
const int oo = 1e9;

int n, m, q;
vector<pi> adj[N];
int d[N][2];
struct node{
    int u, t, du;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1; i <= n; i ++)
        d[i][0] = d[i][1] = oo;
    d[1][0] = 0;
    heap.push({1, 0, 0});
    while ( heap.size() ){
        int u = heap.top().u;
        int du = heap.top().du;
        int t = heap.top().t;
        heap.pop();

        if ( du != d[u][t] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v][t] > d[u][t] + w ){
                d[v][t] = d[u][t] + w;
                heap.push({v, t, d[v][t]});
            }

            if ( !t && d[v][1] > d[u][0] ){
                d[v][1] = d[u][0];
                heap.push({v, 1, d[v][1]});
            }
        }
    }

    while ( q -- ){
        int u, t0;
        cin >> u >> t0;
        cout << min(d[u][0], d[u][1] + t0) << '\n';
    }

    return 0;
}
