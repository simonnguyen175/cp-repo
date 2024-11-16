#include<bits/stdc++.h>
#define simon "smax"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi pair<int, int>
#define pii pair<int, pi>
#define fi first
#define se second
#define pb push_back
#define ld long double
#define ll long long
using namespace std;
const ld eps = 1e-12;

int n;
pi a[20005], cross[20005];

ld stg(pi a, pi b, pi c){
    return abs( (1.0*(b.fi-a.fi)*(c.se-a.se) - 1.0*(c.fi-a.fi)*(b.se-a.se)) / 2 );
}

namespace sub1{
    int cnt = 0, sl = 0;
    int con[3005][3005];
    vector<int> contcr[3005];
    ld val[3005];
    vector<int> adj[3005];
    ld f[3005][2];
    set<pii> tria;

    bool check(int i, int j){
        for (auto it1 : contcr[i])
            for (auto it2 : contcr[j])
                if ( it1 == it2 ) return true;
        return false;
    }

    void dfs(int u, int pu){
        ld sum1 = 0, sum2 = 0;
        //cout << u << '\n';
        for (auto v: adj[u]){
            if ( v == pu ) continue;
            //cout << " -> " << v << '\n';
            dfs(v, u);
            sum1 += f[v][1];
            sum2 += max(f[v][0], f[v][1]);
        }

        f[u][0] = sum1 + val[u];
        f[u][1] = sum2;
    }


    void init(){
        memset(con, 0, sizeof con);
        for (int i = 1; i < n; i ++) con[i][i+1] = con[i+1][i] = ++sl;
        con[n][1] = con[1][n] = ++sl;

        for (int i = 1; i <= n-3; i ++){
            int u = cross[i].fi, v = cross[i].se;
            con[u][v] = con[v][u] = ++sl;
        }

        for (int i = 1; i <= n-3; i ++){
            int u = cross[i].fi, v = cross[i].se;
            for (int j = 1; j <= n; j ++)
                if ( con[u][j] && con[v][j] ){
                    vector<int> tmp;
                    tmp.pb(u), tmp.pb(v), tmp.pb(j);
                    sort(tmp.begin(), tmp.end());
                    if ( tria.find({tmp[0], {tmp[1], tmp[2]}}) != tria.end() ) continue;

                    tria.insert({tmp[0], {tmp[1], tmp[2]}});
                    cnt ++;
                    val[cnt] = stg(a[u], a[v], a[j]);
                    contcr[cnt].pb(con[u][v]);
                    contcr[cnt].pb(con[u][j]);
                    contcr[cnt].pb(con[v][j]);
                }
        }

        for (int i = 1; i <= cnt; i ++)
            for (int j = i + 1; j <= cnt; j ++)
                if ( check(i, j) ){
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
    }


    void solve(){
        init();
        dfs(1, 0);
        ld ans = 0;
        ans = max(f[1][0], f[1][1]);
        ld tmp = abs(ans - (ll)ans);
        if ( tmp > eps ) cout << fixed << setprecision(3) << ans;
        else cout << fixed << setprecision(3) << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r" ) ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].fi >> a[i].se;

    for (int i = 1; i <= n-3; i ++){
        int u, v; cin >> u >> v;
        cross[i] = {u, v};
    }

    sub1::solve();

    return 0;
}
