#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e4 + 5;
const ll oo = 1e10;

int n, m, p, l, k;
vector<pi> adj[N];
struct node{
    ll du;
    int u, used, cur;

    bool operator > (const node &a) const{
        return du > a.du;
    }
};
ll d[N][11][11];

void dijkstra(){
    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 1; i <= n; i ++)
    for (int j = 0; j <= k; j ++)
    for (int t = 0; t <= l; t ++)
        d[i][j][t] = oo;

    d[1][0][0] = 0;
    heap.push({0, 1, 0, 0});

    // d u i j xet den dinh u da su dung i lan lan hien tai di duoc j kenh

    while ( heap.size() ){
        ll du = heap.top().du;
        int u = heap.top().u, used = heap.top().used, cur = heap.top().cur;
        heap.pop();

        if ( du != d[u][used][cur] ) continue;

        if ( cur > 0 && d[u][used+1][0] > du ){
            d[u][used+1][0] = du;
            heap.push({d[u][used+1][0], u, used+1, 0});
        }

        for (auto it : adj[u]){
            int v = it.fi;
            ll w = it.se;

            if ( cur == 0 ){
                if ( used < k && d[v][used][1] > du + p ){
                    d[v][used][1] = du + p;
                    heap.push({d[v][used][1], v, used, 1});
                }

                if ( d[v][used][0] > du + w ){
                    d[v][used][0] = du + w;
                    heap.push({d[v][used][0], v, used, 0});
                }
            }
            else if ( cur < l && d[v][used][cur+1] > du ){
                d[v][used][cur+1] = du;
                heap.push({d[v][used][cur+1], v, used, cur+1});
            }
        }
    }

    ll ans = oo;
    for (int i = 0; i <= k; i ++)
        ans = min(ans, d[n][i][0]);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> p >> l >> k;

    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijkstra();

    return 0;
}
