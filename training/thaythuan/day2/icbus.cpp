#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e3 + 5;
const ll oo = 1e10;

int n, m;
int c[N], b[N];
ll d[N][N];
vector<int> adj[N];

struct node{
    int du, u, rem;

    bool operator > (const node &a) const{
        return du > a.du;
    }
};

void dijkstra(){
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= n; j ++)
        d[i][j] = oo;

    priority_queue<node, vector<node>, greater<node>> heap;
    d[1][0] = 0;
    heap.push({0, 1, 0});
    while ( heap.size() ){
        int u = heap.top().u, rem = heap.top().rem;
        ll du = heap.top().du;
        heap.pop();

        if ( du != d[u][rem] ) continue;

        if ( !rem ){
            if ( d[u][b[u]] > du + c[u] ){
                d[u][b[u]] = du + c[u];
                heap.push({d[u][b[u]], u, b[u]});
            }
        }
        else{
            if ( d[u][0] > du ){
                d[u][0] = du;
                heap.push({d[u][0], u, 0});
            }

            for (int v : adj[u])
                if ( d[v][rem-1] > du ){
                    d[v][rem-1] = du;
                    heap.push({d[v][rem-1], v, rem-1});
                }
        }
    }

    ll ans = oo;
    for (int i = 0; i <= n; i ++)
        ans = min(ans, d[n][i]);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> c[i] >> b[i];

    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dijkstra();

    return 0;
}
