#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n, m, k;
struct node{
    int du, u, tu;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
vector<int> adj[N];
int d[N][4], msk[N];

void dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1; i <= n; i ++)
    for (int t = 1; t <= 3; t ++)
        d[i][t] = oo;
    for (int i = 1; i <= n; i ++)
        d[i][msk[i]] = 0, heap.push({0, i, msk[i]});

    while ( heap.size() ){
        int u = heap.top().u, tu = heap.top().tu, du = heap.top().du;
        heap.pop();

        if ( du != d[u][tu] ) continue;

        for (int v : adj[u])
            if ( d[v][tu] > d[u][tu] + 1 ){
                d[v][tu] = d[u][tu] + 1;
                heap.push({d[v][tu], v, tu});
            }

        if ( d[u][3] > d[u][1] + d[u][2] ){
            d[u][3] = d[u][1] + d[u][2];
            heap.push({d[u][3], u, 3});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("graph.inp", "r", stdin);
    freopen("graph.out", "w", stdout);

    cin >> n >> m >> k;
    for (int i = 1, u; i <= m; i ++){
        cin >> u;
        msk[u] ^= 1;
    }
    for (int i = 1, u; i <= k; i ++){
        cin >> u;
        msk[u] ^= 2;
    }

    for (int i = 1; i <= n; i ++){
        int d;
        cin >> d;
        for (int j = 1, u; j <= d; j ++)
            cin >> u, adj[u].pb(i);
    }

    dijkstra();

    if ( d[1][3] == oo )
        cout << "impossible";
    else cout << d[1][3];

    return 0;
}
