#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int oo = 1e9;

int n, k, na, nb;
pi a, b;

void update(int u, int v){
    for (; u >= 1; u -= u&(-u)) bit[u] = min(bit[u], v);
}

int get(int u){
    int res = oo;
    for (; u <= n; u += u&(-u)) res = min(res, bit[u]);
    return res;
}

void update1(int u, int v){
    for (; u <= n; u += u&(-u)) bit[u] = max(bit[u], v);
}

int get1(int u){
    int res = 0;
    for (; u >= 1; u += u&(-u)) res = max(res, bit[u]);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i ++){
        int l, r;
        cin >> l >> r;
        if ( l <= r ) a[++na] = {l, r};
        else b[++nb] = {l, r};
    }

    for (int i = 1; i <= n; i ++) bit[i] = oo;
    sort(a + 1, a + 1 + na);
    for (int i = 1; i <= na; i ++){
        f[i] = min(a[i].fi, get(a[i].fi));
        update(a[i].se, f[i]);
    }

    sort(b + 1, b + 1 + nb, greater<pi>);
    for (int i = 1; i <= nb; i ++)
        g[i] = max(b[i].se, g[i-1]);

}

