#include <bits/stdc++.h>

using namespace std;

int n , k;
vector < int > g[200003];
int cnt[200002];
long long f[200002][502] , res;

void DFS(int u){
    cnt[u] = 1;
    for (auto v : g[u]) {
        DFS(v);
        cnt[u] += cnt[v];
        for (int i = 1 ; i <= k ; ++i) f[u][i] += f[v][i - 1];
    }
    f[u][0] = f[u][k] + cnt[u] - 1;
}

void GO(int u){
    res += f[u][0];
    for (auto v : g[u]) {
        cnt[u] -= cnt[v];
        for (int i = 1 ; i <= k ; ++i) f[u][i] -= f[v][i - 1];
        f[u][0] = f[u][k] + cnt[u] - 1;
        cnt[v] += cnt[u];
        for (int i = 1 ; i <= k ; ++i) f[v][i] += f[u][i - 1];
        f[v][0] = f[v][k] + cnt[v] - 1;
        GO(v);
        cnt[v] -= cnt[u];
        for (int i = 1 ; i <= k ; ++i) f[v][i] -= f[u][i - 1];
        f[v][0] = f[v][k] + cnt[v] - 1;
        cnt[u] += cnt[v];
        for (int i = 1 ; i <= k ; ++i) f[u][i] += f[v][i - 1];
        f[u][0] = f[u][k] - cnt[u] - 1;
    }
}

int main(){
    freopen("jumping.inp","r",stdin);
    freopen("jumping.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int root = 1;
    cin >> n >> k;
    for (int p , i = 1 ; i <= n ; ++i) {
        cin >> p;
        if (p == 0) root = i;
        else g[p].push_back(i);
    }
    DFS(root);
    GO(root);
    cout << res / 2;
}
