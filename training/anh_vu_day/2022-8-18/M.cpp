#include<bits/stdc++.h>
#define pb push_back
#define BIT(x,k) ((x>>k)&1)
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int M = 1e4 + 5;
const int N = 17;

int m, n;
int a[M][N], dp[N+5][1<<N], id[N];
vector<int> adj[1<<N];

void print(int msk){
    for (int i = 0; i < n; i ++)
        cout << BIT(msk, i);
    cout << '\n';
}

void solve(){
    cin >> m >> n;
    vector<pi> cont;
    for (int i = 1; i <= m; i ++){
        int mx = 0;
        for (int j = 1; j <= n; j ++)
            cin >> a[i][j], mx = max(mx, a[i][j]);
        cont.pb({mx, i});
    }
    sort(cont.begin(), cont.end(), greater<pi>());
    m = min(m, n);
    for (int i = 0; i < m; i ++)
        id[i+1] = cont[i].se;

    for (int msk = 0; msk < (1<<n); msk ++)
        adj[msk].clear();

    for (int msk = 0; msk < (1<<n); msk ++){
        int root = (1<<16), tmp = msk;
        for (int i = 1; i <= n; i ++){
            int t = BIT(tmp, 0);
            tmp >>= 1;
            tmp |= t * (1<<(n-1));
            root = min(root, tmp);
        }
        adj[root].pb(tmp);
    }

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= m; i ++){
        for (int msk = 0; msk < (1<<n); msk ++)
            dp[i][msk] = dp[i-1][msk];
        for (int msk = 0; msk < (1<<n); msk ++)
        for (int j = 1; j <= n; j ++) if ( !BIT(msk, j-1) )
            dp[i][msk|(1<<(j-1))] = max({dp[i][msk|(1<<(j-1))],
                                    dp[i-1][msk] + a[id[i]][j],
                                    dp[i][msk] + a[id[i]][j]});

        for (int msk = 0; msk < (1<<n); msk ++){
            int tmp = 0;
            for (int t : adj[msk])
                tmp = max(tmp, dp[i][t]);
            for (int t : adj[msk])
                dp[i][t] = tmp;
        }
    }

    cout << dp[m][(1<<n)-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
