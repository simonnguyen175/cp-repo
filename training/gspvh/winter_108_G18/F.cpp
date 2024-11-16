#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;
const int MOD = 998244353;

int sub, n, k, head = 0, ans = 1;
int vis[N], incir[N], pwk[N], f[N], g[N];
vector<int> adj[N], cir;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

void dfs(int u, int pu){
    vis[u] = 1;
    for (int v : adj[u]) if ( v != pu ){
        if ( vis[v] ){
            if ( head ) continue;
            incir[u] = 1;
            cir.pb(u);
            head = v;
            continue;
        }

        dfs(v, u);

        if ( v != head && incir[v] ){
            incir[u] = 1;
            cir.pb(u);
        }
    }
}

int get_sz(int u, int pu){
    int sz = 1;
    for (int v : adj[u]) if ( v != pu )
        sz += get_sz(v, u);
    return sz;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("paleta.inp", "r", stdin);
    freopen("paleta.out", "w", stdout);

    cin >> sub >> n >> k;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        if ( x == i ) continue;
        adj[i].pb(x);
        adj[x].pb(i);
    }

    for (int i = 1; i <= n; i ++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    pwk[0] = 1;
    for (int i = 1; i <= n; i ++)
        pwk[i] = mul(pwk[i-1], k-1);

    /// dp tinh mau tren vong
    /// f(i) xet i dinh va dinh dau trung mau dinh cuoi
    /// g(i) xet i dinh va dinh dau khac mau dinh cuoi
    f[1] = k;
    g[1] = 0;
    for (int i = 2; i <= n; i ++){
        g[i] = add(mul(g[i-1], k-2), mul(f[i-1], k-1));
        f[i] = g[i-1];
    }

    for (int i = 1; i <= n; i ++) if ( !vis[i] ){
        head = 0;
        cir.clear();
        dfs(i, 0);

//        cout << head << ' ' << cir.size() << '\n';

        if ( !cir.size() ){
            /// cay
            int tmp = get_sz(i, 0);
            ans = mul(ans, mul(k, pwk[tmp-1]));
        }
        else{
            /// do thi mat troi
            for (int u : cir)
            for (int v : adj[u]) if ( !incir[v] ){
                int tmp = get_sz(v, u);
                ans = mul(ans, pwk[tmp]);
            }

            ans = mul(ans, g[cir.size()]);
        }
    }

    cout << ans;

    return 0;
}
