#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define BIT(x, k) ((x>>k)&1)
using namespace std;
const int N = 1.5e5 + 5;
const int MOD = (int)1e9 + 19972207;

int sub, n, q, seed, mul, add;
pi edg[N];

int getRandom(int n){
    seed = (1ll * mul * seed + add) % MOD;
    return 1 + seed % n;
}

namespace sub1{
    vector<pi> nedg;
    vector<int> g[N];
    int vis[N];

    bool check(int msk){
        for (int i = 1; i <= n; i ++) g[i].clear(), vis[i] = 0;
        for (int i = 0; i < nedg.size(); i ++) if ( BIT(msk, i) ){
            g[nedg[i].fi].pb(nedg[i].se);
            g[nedg[i].se].pb(nedg[i].fi);
        }

        int cnt = 0, s;
        for (int i = 1; i <= n; i ++) if ( g[i].size() )
            s = i, cnt ++;

        queue<int> q;
        q.push(s);
        vis[s] = 1, cnt --;
        while ( q.size() ){
            int u = q.front();
            q.pop();

            for (int v : g[u]) if ( !vis[v] ){
                q.push(v);
                vis[v] = 1;
                cnt --;
            }
        }

        if ( cnt ) return 0;

        for (int i = 1; i <= n; i ++)
            if ( vis[i] && g[i].size() != 2 ) return 0;

        return 1;
    }

    int query(int e1, int u1, int v1, int e2, int u2, int v2){
        nedg.clear();
        for (int i = 1; i < n; i ++) if ( i != e1 && i != e2 )
            nedg.pb(edg[i]);

        nedg.pb({u1, v1});
        nedg.pb({u2, v2});

        int res = 0;
        for (int t = 1; t <= (1<<(n-1)); t ++) if ( check(t) )
            res ++;

        return res;
    }

    void solve(){
        int res = 0;
        for (int i = 1; i <= q; i ++){
            int e1 = getRandom(n - 1);
            int u1 = getRandom(n); int v1 = getRandom(n);
            int e2 = getRandom(n - 1);
            int u2 = getRandom(n); int v2 = getRandom(n);
            int tmp = e1 == e2 || u1 == v1 || u2 == v2
                     ? MOD - 1 : query(e1, u1, v1, e2, u2, v2);
            res = (227LL * res + tmp) % MOD;
        }

        cout << res;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("chutrinh.inp", "r", stdin);
    freopen("chutrinh.out", "w", stdout);

    cin >> sub >> n;
    for (int i = 1; i < n; i ++)
        cin >> edg[i].fi >> edg[i].se;

    cin >> q >> seed >> mul >> add;

//    if ( n <= 16 && q <= 89 )
        sub1::solve();

    return 0;
}
