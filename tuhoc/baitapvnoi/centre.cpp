#include<bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, m;
vector<ii> adj[N];
int d1[N], dn[N], f1[N], fn[N];

void dijkstra(bool c){
    if ( c ){
        priority_queue<ii, vector<ii>, greater<ii>> heap;
        for (int i = 1; i <= n; i ++) d1[i] = oo;
        d1[1] = 0; f1[1] = 1; heap.push({0, 1});

        while ( heap.size() ){
            int u = heap.top().se;
            int du = heap.top().fi;
            heap.pop();

            for (auto it : adj[u]){
                int v = it.se, w = it.fi;
                if ( d1[v] > du + w ){
                    d1[v] = du + w;
                    f1[v] = f1[u];
                    heap.push({d1[v], v});
                }
                else if ( d1[v] == du + w ) f1[v] += f1[u];
            }
        }
    }
    else{
        priority_queue<ii, vector<ii>, greater<ii>> heap;
        for (int i = 1; i <= n; i ++) dn[i] = oo;
        dn[n] = 0; fn[n] = 1; heap.push({0, n});

        while ( heap.size() ){
            int u = heap.top().se;
            int du = heap.top().fi;
            heap.pop();

            for (auto it : adj[u]){
                int v = it.se, w = it.fi;
                if ( dn[v] > du + w ){
                    dn[v] = du + w;
                    fn[v] = fn[u];
                    heap.push({dn[v], v});
                }
                else if ( dn[v] == du + w ) fn[v] += fn[u];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dijkstra(1);
    dijkstra(0);
    int cnt = 0; vector<int> ans;
    for (int i = 2; i <= n - 1; i ++)
        if ( d1[i] + dn[i] > d1[n] || fn[i] * f1[i] < f1[n] ) cnt ++, ans.push_back(i);
    cout << cnt << '\n'; for (auto u : ans) cout << u << '\n';
    return 0;
}
