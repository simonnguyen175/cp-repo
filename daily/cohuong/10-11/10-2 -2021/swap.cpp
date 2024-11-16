#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int n, q;
ll bit[N];

void update(int u, ll v){
    for (; u <= n; u += u & (-u)) bit[u] += v;
}

ll get(int u){
    ll res = 0;
    for (; u > 0; u -= u & (-u)) res += bit[u];
    return res;
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        ll x; cin >> x;
        update(i, x);
    }
    while ( q -- ){
        int k, u, v;
        cin >> k >> u >> v;
        if ( k == 0 ){
            ll valu = get(u) - get(u-1);
            ll valv = get(v) - get(v-1);
            ll diff = valv - valu;
            update(u, diff); update(v, -diff);
        }
        else{
            cout << get(v) - get(u-1) << '\n';
        }
    }
    return 0;
}
