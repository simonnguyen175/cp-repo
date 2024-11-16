#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e15;

int n, m, C, q, s;
struct ke{
    int v, w, c;
};
vector<ke> adj[N];
struct node{
    ll du;
    int u, cu, t;
    bool operator > (const node &a) const{
        return du > a.du;
    }
};
pi d[N][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> C;
    for (int i = 1, u, v, w, c; i <= m; i ++){
        cin >> u >> v >> w >> c;
        adj[u].pb({v, w, c});
    }

    /// d[u][0/1] = {val, col} duong di ngan nhat/nhi den u voi 2 mau khac nhau
    for (int i = 1; i <= n; i ++)
        d[i][0] = d[i][1] = {oo, 0};
    cin >> s >> q;
    d[s][0] = {0, 0};
    priority_queue<node, vector<node>, greater<node>> heap;
    heap.push({d[s][0].fi, s, 0, 0});
    while ( heap.size() ){
        int u = heap.top().u;
        ll du = heap.top().du;
        int cu = heap.top().cu;
        int t = heap.top().t;
        heap.pop();

        if ( pi(du, cu) != d[u][t] ) continue;

        for (auto it : adj[u]){
            int v = it.v, w = it.w, c = it.c;
            if ( c == cu ) continue;

            if ( d[v][0].fi > du + w ){
                if ( d[v][0].se == c ){
                    d[v][0] = {du + w, c};
                    heap.push({d[v][0].fi, v, d[v][0].se, 0});
                }
                else{
                    d[v][1] = d[v][0];
                    d[v][0] = {du + w, c};
                    heap.push({d[v][0].fi, v, d[v][0].se, 0});
                    heap.push({d[v][1].fi, v, d[v][1].se, 1});
                }
            }
            else if ( d[v][1].fi > du + w && d[v][0].se != c ){
                d[v][1].fi = du + w;
                heap.push({d[v][1].fi, v, d[v][1].se, 1});
            }
        }
    }

    while ( q -- ){
        int u;
        cin >> u;
        ll res = min(d[u][0].fi, d[u][1].fi);
        if ( res == oo ) cout << -1 << '\n';
        else cout << res << '\n';
    }

    return 0;
}
