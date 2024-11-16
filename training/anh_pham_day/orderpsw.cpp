#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

void update(int u, int v){
    for (; u <= n; u += u&-u)
        bit[u] = add(bit[u], v);
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res = add(res, bit[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> q;

    fact[0] = 1;
    for (int i = 1; i <= n; i ++)
        fact[i] = mul(fact[i-1], i);

    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    int ans = 1;
    for (int i = 1; i <= n; i ++){
        inv[i] = a[i] - 1 - get(a[i]-1);
        ans = add(ans, mul(inv[i], fact[n-i]));
        update(a[i], 1);
    }

    for (int i = 1; i <= q; i ++){
        int u, v;
        cin >> u >> v;
        if ( u > v ) swap(u, v);
        cont[u].pb({v, i});
        cont[v].pb({u, i});
        res[i] = add(ans, -add(mul(f[u], fact[n-u]), mul(f[v], fact[n-v])));
    }

    for (int i = 1; i <= n; i ++) bit[i] = 0;
    for (int i = 1; i <= n; i ++){
        for (auto it : cont[i]){
            int x = it.fi, id = it.se;
        }
    }


    return 0;
}
