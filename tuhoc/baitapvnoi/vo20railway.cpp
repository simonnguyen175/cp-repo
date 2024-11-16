#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
const ll oo = 1e18;

int n, m, s;
vector<pi> adj[N];
ll a[N], d[N][2], cnt[N][2];
struct node{
    ll du;
    int u, t;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
pi trace[N][2];
map<pi, int> id;

void dijkstra(){
    for (int i = 1; i <= n; i ++)
        d[i][0] = d[i][1] = oo;

    d[s][0] = 0, d[s][1] = a[s];
    cnt[s][0] = cnt[s][1] = 0;

    priority_queue<node, vector<node>, greater<node>> heap;
    heap.push({d[s][0], s, 0});
    heap.push({d[s][1], s, 1});

    while ( heap.size() ){
        int u = heap.top().u, t = heap.top().t;
        ll du = heap.top().du;

        heap.pop();

        if ( du != d[u][t] ) continue;

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;

            if ( t == 0 ){
                if ( d[v][0] > d[u][0] + w ){
                    d[v][0] = d[u][0] + w;
                    cnt[v][0] = cnt[u][0] + 1;
                    trace[v][0] = {u, 0};
                    heap.push({d[v][0], v, 0});
                }

                if ( d[v][1] > d[u][0] + w + a[v] ){
                    d[v][1] = d[u][0] + w + a[v];
                    cnt[v][1] = cnt[u][0] + 1;
                    trace[v][1] = {u, 0};
                    heap.push({d[v][1], v, 1});
                }
            }
            else if ( d[v][1] > d[u][1] + w ){
                d[v][1] = d[u][1] + w;
                cnt[v][1] = cnt[u][1] + 1;
                trace[v][1] = {u, 1};
                heap.push({d[v][1], v, 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("railway.inp", "r") ){
        freopen("railway.inp", "r", stdin);
        freopen("railway.out", "w", stdout);
    }

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        id[{u, v}] = i;
    }

    dijkstra();

    ll ans = -oo;
    int cur, t;
    vector<int> way;

//    for (int i = 1; i <= n; i ++) cout << d[i][1] << ' '; cout << '\n';

    for (int i = 1; i <= n; i ++) if ( d[i][1] != oo )
        if ( d[i][1] > ans ) ans = d[i][1], cur = i, t = 1;

    cout << ans << ' ' << cur << '\n';
    cout << cnt[cur][1] << '\n';

    while ( cur != s ){
        int pre = trace[cur][t].fi, pt = trace[cur][t].se;
        way.pb(id[{pre, cur}]);
        cur = pre, t = pt;
    }

    reverse(way.begin(), way.end());

    for (auto x : way) cout << x << ' '; cout << '\n';

    return 0;
}
