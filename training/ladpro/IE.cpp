#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ii pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 5;
const ll oo = 1e18;

int n, m, hc, sc, hj, sj;
ll d[4][N];
vector<ii> adj[N];
struct canh{
    int u, v;
    ll w;
} edge[N];

void dijkstra(int x){
    priority_queue<ii, vector<ii>, greater<ii>> heap;

    if ( x == 0 ) d[x][hc] = 0, heap.push({0, hc});
    if ( x == 1 ) d[x][sc] = 0, heap.push({0, sc});
    if ( x == 2 ) d[x][hj] = 0, heap.push({0, hj});
    if ( x == 3 ) d[x][sj] = 0, heap.push({0, sj});

    while ( heap.size() ){
        int u = heap.top().se;
        ll du = heap.top().fi;

        heap.pop();

        for (auto it : adj[u]){
            int v = it.se;
            ll w = it.fi;

            if ( d[x][v] > du + w ){
                d[x][v] = du + w;
                heap.push({d[x][v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    while ( cin >> n >> m ){
        if ( !n && !m ) return 0;
        cin >> hc >> sc >> hj >> sj;

        for (int i = 1; i <= n; i ++) adj[i].clear();

        for (int i = 1; i <= m; i ++){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({w, v});
            adj[v].pb({w, u});
            edge[i] = {u, v, w};
        }

        for (int i = 0; i <= 3; i ++)
        for (int j = 1; j <= n; j ++)
            d[i][j] = oo;

        for (int i = 0; i <= 3; i ++)
            dijkstra(i);

        int cnt = 0;

        // case 1
        for (int i = 1; i <= n; i ++)
            if ( d[0][i] == d[2][i] && d[0][i] + d[1][i] == d[0][sc] && d[2][i] + d[3][i] == d[2][sj] )
                cnt ++;

        // case 2
        bool flag = 0;
        for (int i = 1; i <= m; i ++){
            int u = edge[i].u, v = edge[i].v;
            ll w = edge[i].w;
            if ( d[0][u] + w + d[1][v] == d[0][sc] && d[2][u] + w + d[3][v] == d[2][sj] && d[0][u] == d[2][u] ) {flag = 1; break;}
            if ( d[0][v] + w + d[1][u] == d[0][sc] && d[2][v] + w + d[3][u] == d[2][sj] && d[0][v] == d[2][v] ) {flag = 1; break;}
        }

        if ( flag ){cout << -1 << '\n'; continue;}

        // case 3
        for (int i = 1; i <= m; i ++){
            int u = edge[i].u, v = edge[i].v;
            ll w = edge[i].w;
            if ( d[0][u] + w + d[1][v] == d[0][sc] && d[2][v] + w + d[3][u] == d[2][sj] && abs(d[0][u]-d[2][v]) < w ) cnt ++;
            if ( d[0][v] + w + d[1][u] == d[0][sc] && d[2][u] + w + d[3][v] == d[2][sj] && abs(d[0][v]-d[2][u]) < w ) cnt ++;
        }

        // case 4
        if ( d[0][sc] < d[2][sc] && d[2][sc] + d[3][sc] == d[2][sj] ) cnt ++;
        if ( d[0][sj] > d[2][sj] && d[0][sj] + d[1][sj] == d[0][sc] ) cnt ++;

        cout << cnt << '\n';
    }

    return 0;
}
