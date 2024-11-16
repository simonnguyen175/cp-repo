#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, k, l;
int a[N], b[N];
vector<pi> adj[N];
ll d[N][2], grp[N][2];

struct node{
    ll du;
    int t, u;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> k >> l;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= l; i ++) cin >> b[i];
    for (int i = 1, u, v, w; i <= m; i ++){
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (int i = 1; i <= n; i ++)
        d[i][0] = d[i][1] = oo;

    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1, u; i <= l; i ++){
        u = b[i];
        d[u][0] = 0;
        grp[u][0] = a[u];
        heap.push({0LL, 0, u});
    }

    while ( heap.size() ){
        ll du = heap.top().du;
        int t = heap.top().t;
        int u = heap.top().u;
        int gr = grp[u][t];
        heap.pop();

        if ( du != d[u][t] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v][0] > du + w ){
                if ( grp[v][0] != gr && d[v][0] != oo ){
                    d[v][1] = d[v][0];
                    grp[v][1] = grp[v][0];
                    heap.push({d[v][1], 1, v});
                }
                d[v][0] = du + w;
                grp[v][0] = gr;
                heap.push({d[v][0], 0, v});
            }
            else if ( d[v][1] > du + w && grp[v][0] != gr ){
                d[v][1] = du + w;
                grp[v][1] = gr;
                heap.push({d[v][1], 1, v});
            }
        }
    }

    for (int i = 1; i <= n; i ++){
        ll res = -1;
        if ( grp[i][0] && grp[i][0] != a[i] ) res = d[i][0];
        else if ( grp[i][1] ) res = d[i][1];
        cout << res << ' ';
    }

    return 0;
}
