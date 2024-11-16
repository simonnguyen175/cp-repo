#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int oo = 1e9;

struct node{
    int v, w, c;
};

node makenode(int v, int w, int c){
    node res; res.v = v; res.w = w; res.c = c;
    return res;
}

bool operator > (const node& a, const node& b){
    return a.w > b.w;
}

int t, k, n, m;
vector<node> adj[N];
int d[N][10005];

void dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    memset(d, 0x3f, sizeof d);

    heap.push(makenode(1, 0, 0));

    while ( !heap.empty() ){
        int u = heap.top().v;
        int du = heap.top().w;
        int cost = heap.top().c;
        heap.pop();

        //cout << u << ' ' << du << ' ' << cost << '\n';

        for (auto tmp : adj[u] ){
            int v = tmp.v;
            int w = tmp.w;
            int c = tmp.c;

            if ( cost + c > k ) continue;

            if ( d[v][cost + c] > du + w ){
                d[v][cost + c] = du + w;
                heap.push(makenode(v, d[v][cost + c], cost + c));
            }
        }
    }
}

void solve(){
    cin >> k >> n >> m;
    for (int i = 1; i <= n; i ++)
        adj[i].clear();

    int u, v, w, c;
    for (int i = 1; i <= m; i ++){
        cin >> u >> v >> w >> c;
        adj[u].push_back(makenode(v, w, c));
    }

    dijkstra();

    int ans = oo;
    for (int i = 1; i <= k; i ++)
        ans = min(ans, d[n][i]);

    cout << ( ans != oo ? ans : - 1 ) << '\n';
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
