#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 5e4 + 5;

int n, m, t;
int a[N];
pi q[N];
vector<int> adj[N];

namespace sub1{
    set<int> cont;
    queue<int> Q;
    int d[N], cnt[N];

    void bfs(int x){
         for (int i = 1; i <= n; i ++) d[i] = -1, cnt[i] = 0;

        for (auto it : cont)
            d[it] = 0, cnt[it] = 1, Q.push(it);

        while ( Q.size() ){
            int u = Q.front();
            Q.pop();

            for (int v : adj[u]){
                if ( d[v] != -1 ){
                    if ( d[v] == d[u] + 1 ) cnt[v] += cnt[u];
                }
                else{
                    d[v] = d[u] + 1, cnt[v] = cnt[u], Q.push(v);
                }
            }
        }

        cout << d[q[x].se] << ' ' << cnt[q[x].se] << '\n';
    }

    void solve(){
        for (int i = 1; i <= m; i ++) cont.insert(a[i]);

        for (int i = 1; i <= t; i ++){
            if ( q[i].fi == 1 ){
                if ( cont.find(q[i].se) != cont.end() ) cont.erase(q[i].se);
                else cont.insert(q[i].se);
            }
            else bfs(i);
        }
    }
}

namespace sub2{
    queue<int> Q;
    int d[N], cnt[N];

    void solve(){
        for (int i = 1; i <= n; i ++) d[i] = -1, cnt[i] = 0;

        for (int i = 1; i <= m; i ++)
            d[a[i]] = 0, cnt[a[i]] = 1, Q.push(a[i]);

        while ( Q.size() ){
            int u = Q.front();
            Q.pop();

            for (int v : adj[u]){
                if ( d[v] != -1 ){
                    if ( d[v] == d[u] + 1 ) cnt[v] += cnt[u];
                }
                else{
                    d[v] = d[u] + 1, cnt[v] = cnt[u], Q.push(v);
                }
            }
        }

        for (int i = 1; i <= t; i ++)
            cout << d[q[i].se] << ' ' << cnt[q[i].se] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("3.inp", "r") ){
        freopen("3.inp", "r", stdin);
        freopen("3.out", "w", stdout);
    }

    cin >> n >> m >> t;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= m; i ++) cin >> a[i];

    bool ck2 = 1;
    for (int i = 1; i <= t; i ++){
        cin >> q[i].fi >> q[i].se;
        ck2 &= ( q[i].fi == 2 );
    }

    if ( n <= 5000 && t <= 5000 ) sub1::solve();
    else if ( ck2 ) sub2::solve();

    return 0;
}
