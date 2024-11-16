#include <bits/stdc++.h>
#define EL cout<<endl
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pil pair<int,ll>
#define can(n, q) round(exp(log(n) / q))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define FU(x,a,b) for(int x=int(a);x<=int(b);x++)
#define FD(x,a,b) for(int x=int(a);x>=int(b);x--)
#define PROB "kiosks"
using namespace std;
typedef long long ll;
typedef double db;


void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen(PROB".inp", "r")){
        freopen(PROB".inp", "r",stdin);
        freopen(PROB".out", "w",stdout);
    }
}

const int mod = 1e9 + 7;
const int N = 1e4 + 2;
int n, k;
int c[N];
int dp[N];
vector < vector < int > > a;
void readinp(){
    cin >> n >> k; a.resize(n + 1);
    FU(i, 1, n){
        cin >> c[i];
        c[i]--;
    }
    FU(i, 2, n){
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
}

void dfs (int u, int p, int mask){
    dp[u] = 1;
    if (c[u] < k && (mask >> c[u]) & 1) dp[u] = 0;
    for (auto v : a[u]) if (v != p){
        dfs(v, u, mask);
        dp[u] = (ll(dp[u]) * ll(dp[v] + 1)) % mod;
    }
}

void solve(){
    int res = 0;
    FU(i, 0, (1 << k) - 1){
        dfs(1, 1, i);
        int t = (__builtin_popcount(i) & 1) ? -1 : +1;
        cout << "mask " << i << '\n';
        for (int i = 1; i <= n; i ++) cout << dp[i] << ' ';
        cout << '\n';
        FU(u, 1, n) res = (ll(res) + ll(t * dp[u]) + ll(mod)) % mod;
    }
    cout << res;
}

int main(){
    setIO();
    readinp();
    solve();
    return 0;
}
