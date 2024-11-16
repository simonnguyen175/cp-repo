#include<bits/stdc++.h>
#define simon "stones"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e4 + 5;

int n;

namespace sub1{
    vector<pi> cont[35];
    int sum = 0, s1;
    int f[35][4000];

    void solve(){
        for (int i = 1; i <= 4 * n; i ++){
            int m, c; cin >> m >> c;
            cont[c].pb({m, i});
            sum += m;
        }

        memset(f, 0, sizeof f);

        f[0][0] = 1;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < sum; j ++) if ( f[i][j] )
                for (int t = 0; t < 15; t ++)
                if ( __builtin_popcount(t) == 2 ){
                    int tmp = 0;
                    for (int k = 0; k < 4; k ++) if ( (t>>k)&1 )
                        tmp += cont[i+1][k].fi;
                    f[i+1][j+tmp] |= f[i][j];
                }

        int diff = sum + 1;
        for (int i = 1; i <= sum; i ++)
            if ( f[n][i] && diff > abs(sum-2*i) ){
                diff = abs(sum-2*i);
                s1 = i;
            }


        vector<int> gr1;
        int id = n;
        while ( id ){
            for (int t = 0; t < 15; t ++) if ( __builtin_popcount(t) == 2 ){
                int tmp = 0;
                for (int k = 0; k < 4; k ++) if ( (t>>k)&1 )
                    tmp += cont[id][k].fi, gr1.pb(cont[id][k].se);
                if ( f[id-1][s1-tmp] ){
                    s1 -= tmp, id --;
                    break;
                }
                gr1.pop_back(); gr1.pop_back();
            }
        }

        sort(gr1.begin(), gr1.end());
        for (int x : gr1) cout << x << ' ';
    }
}

namespace sub2{
    int c[4*N], m[4*N];
    vector<int> cont;
    vector<pi> adj[4*N];
    bool vis[4*N], used[4*N];

    void dfs(int u, int id){
        vis[u] = 1;
        while ( adj[u].size() ){
            pi it = adj[u].back();
            adj[u].pop_back();
            if ( !used[it.se] ){
                used[it.se] = 1;
                dfs(it.fi, it.se);
            }
        }
        if ( id ){
            cont.pb(id);
            //cout << id << '\n';
        }
    }

    void solve(){
        for (int i = 1; i <= 4 * n; i ++)
            cin >> m[i] >> c[i];

        memset(vis, 0, sizeof vis);
        memset(used, 0, sizeof used);

        for (int i = 1; i <= 2 * n; i ++){
            adj[c[i]].pb({c[4*n-i+1], i});
            adj[c[4*n-i+1]].pb({c[i], i});
        }

        for (int i = 1; i <= n; i ++)
            if ( !vis[i] ){
                cont.clear();
                dfs(i, 0);
                for (int j = 0; j < cont.size(); j += 2)
                    cout << cont[j] << ' ' << 4*n - cont[j] + 1 << ' ';
            }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n;

    if ( n <= 30 ) sub1::solve();
    else sub2::solve();

    return 0;
}
