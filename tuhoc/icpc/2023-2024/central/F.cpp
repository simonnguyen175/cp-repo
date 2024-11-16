#include <bits/stdc++.h>
#define f(i,a,b) for(int i = a;i <= b;++i)
#define int long long
#define ll long long
#define pii pair<int,int>
#define piii pair<int , pii>
#define piiii pair <pii , pii>
#define F first
#define S second
#define task "nhuhieu193"
#define mod 1000000007
#define endl '\n'
#define minimize(x,y) x = (x > y ? y : x)
#define maximize(x,y) x = (x < y ? y : x)
using namespace std;
const int maxn = 100005;

int gcd(int x , int y) {
    return y ? gcd(y , x % y) : x;
}

string Y = "YES\n" , N = "NO\n" , Al = "Alice\n" , Bo = "Bob\n";

ll POWW(ll t , ll x) {
    if (x == 0) return 1;
    ll B = POWW(t , x / 2);
    ll C = B * B % mod;
    if (x & 1) C = C * t % mod;
    return C;
}

int n,m,k;

/// Author : CBN_K28_nhuhieu193

/// welcome to my amazing code !!!

piiii edges[maxn];

vector <int> a[maxn];
int par[17][maxn];
ll L[17][maxn] , h[maxn];

void dfs(int x , int pX) {
    for (auto id : a[x]) {
        int y = edges[id].F.F + edges[id].F.S - x;
        if (y == pX) continue;
        h[y] = h[x] + 1;
        par[0][y] = x;
        f(i,1,16) par[i][y] = par[i - 1][par[i - 1][y]];
        dfs(y , x);
    }
}

int LCA(int u , int v) {
    if (h[u] < h[v]) swap(u , v);
    int d = h[u] - h[v];
    f(i,0,16) if ((d >> i) & 1) u = par[i][u];
    if (u == v) return u;
    for (int i = 16 ; i >= 0 ; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

void update(int u , int p) {
    int d = h[u] - h[p];
    for (int i = 16 ; i >= 0 ; i--) if ((d >> i) & 1) {
        L[i][u]++;
        u = par[i][u];
    }
}

ll ans = 0;

void solve(int x , int pX) {
    for (auto id : a[x]) {
        int y = edges[id].F.F + edges[id].F.S - x;
        if (y == pX) continue;
        ans += min(edges[id].S.S , edges[id].S.F * L[0][y]);
        solve(y , x);
    }
}

void process() {
    cin >> n;
    f(i,1,n - 1) {
        int x,y,u,v;
        cin >> x >> y >> u >> v;
        edges[i] = {{x , y} , {u , v}};
        a[x].push_back(i);
        a[y].push_back(i);
    }
    dfs(1 , 0);
    f(x,1,n - 1) {
        int p = LCA(x , x + 1);
        update(x , p);
        update(x + 1 , p);
    }
    for (int u = 16 ; u ; u--) {
        f(i,1,n) {
            L[u - 1][i] += L[u][i];
            L[u - 1][par[u - 1][i]] += L[u][i];
        }
    }
    solve(1 , 0);
    cout << ans;
}

/// This is end of my solution.

int32_t main() {
    ios_base::sync_with_stdio(false);
//    freopen(task".inp","r",stdin);
//    freopen(task".out","w",stdout);
    cin.tie(0);
    int ntest = 1;
//    cin >> ntest;
    while (ntest--) {
        process();
    }

}
/// range maxn , memory
/// long long , mod
/// implement
/// file
/// reset testcase
