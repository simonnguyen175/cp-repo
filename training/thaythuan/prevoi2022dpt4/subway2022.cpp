#include<bits/stdc++.h>
#define BIT(x, k) ((x>>k)&1)
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m;
int p[N];
vector<int> adj[N];

namespace sub1{
    void solve(){
        int ans = 0;
        for (int i = 1; i < (1<<n); i ++){
            int s = 0, ck = 1;
            for (int j = 1; j <= n; j ++) if ( BIT(i, j-1) ){
                s += p[j];
                for (int k : adj[j])
                    ck &= !BIT(i, k-1);
            }
            if ( ck ) ans = max(ans, s);
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if ( n <= 20 ) sub1::solve();

    return 0;
}
