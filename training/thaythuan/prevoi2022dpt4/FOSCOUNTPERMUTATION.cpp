#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
int fact[N], inv[N], p[N], c[N], f[N], sz[N];
vector<int> adj[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

int Pow(int a, int b){
    if ( b == 0 ) return 1;
    int tmp = Pow(a, b/2);
    if ( b % 2 ) return mul(tmp, mul(tmp, a));
    else return mul(tmp, tmp);
}

int C(int n, int k){
    return mul(fact[n], mul(inv[n-k], inv[k]));
}

void dfs(int u){
    f[u] = 1;

    for (int v : adj[u]){
        dfs(v);
        sz[u] += sz[v];
        f[u] = mul(mul(f[u], f[v]), C(sz[u]-1, sz[v]-1));
    }

    sz[u] ++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i ++) fact[i] = mul(fact[i-1], i);
    inv[N-1] = Pow(fact[N-1], MOD-2);
    for (int i = N-2; i >= 0; i --) inv[i] = mul(inv[i+1], i+1);

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];

    stack<int> stk;
    for (int i = n; i >= 1; i --){
        while ( stk.size() && p[stk.top()] < p[i] ) stk.pop();
        if ( stk.size() ) c[i] = stk.top();
        else c[i] = n + 1;
        stk.push(i);
    }

    for (int i = n; i >= 1; i --)
        adj[c[i]].pb(i);

    dfs(n+1);

    cout << f[n+1];

    return 0;
}
