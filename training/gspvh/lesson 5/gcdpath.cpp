#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair < int , int >
using namespace std;

const int maxn = 1500000;

int n , a[maxn + 5] , u[maxn + 5] , v[maxn + 5] , par[maxn + 5] , siz[maxn + 5];
long long f[maxn + 5];
bool vs[maxn + 5];
vector < int > edge[maxn + 5];

int fin(int u) {
    if (par[u] != u) par[u] = fin(par[u]);
    return par[u];
}

void join(int u,int v) {
    u = fin(u);
    v = fin(v);
    if (u == v) return;
    if (siz[u] < siz[v]) swap(u , v);
    par[v] = u;
    siz[u] += siz[v];
    return;
}

int main() {
    freopen("gcdpath.inp","r",stdin);
    freopen("gcdpath.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int sub;
    cin >> sub;
    cin >> n;
    for (int i = 1 ; i <= n ; ++i) {
        cin >> a[i];
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 1 ; i < n ; ++i) {
        cin >> u[i] >> v[i];
        edge[__gcd(a[u[i]] , a[v[i]])].push_back(i);
    }
    long long res = 0;
    for (int i = maxn ; i > 0 ; --i) {
        int d = 0;
        for (int j = 1 ; j <= maxn / i ; ++j)
        for (auto x : edge[i * j])
        join(u[x] , v[x]);
        for (int j = 1 ; j <= maxn / i ; ++j)
        for (auto id : edge[i * j]) {
            int x = u[id] , y = v[id];
            x = fin(x) , y = fin(y);
            if (!vs[x]) {
                vs[x] = 1;
                f[i] += 1ll * siz[x] * (siz[x] - 1) / 2;
            }
            if (!vs[y]) {
                vs[y] = 1;
                f[i] += 1ll * siz[y] * (siz[y] - 1) / 2;
            }
        }
        for (int j = 1 ; j <= maxn / i ; ++j) {
            if (j > 1) f[i] -= f[i * j];
            for (auto x : edge[i * j]) {
                vs[u[x]] = 0;
                vs[v[x]] = 0;
                par[u[x]] = u[x];
                par[v[x]] = v[x];
                siz[u[x]] = siz[v[x]] = 1;
            }
        }
        res += f[i] * i;
    }
    cout << res;
}
