#include<bits/stdc++.h>
#define simon "twopress"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 1e3 + 5;

ll n, s, x;
ll a[N], c[105], bit[100*N];

int get(int p){
    int res = 0, idx = p;
    while ( idx > 0 ){
        res += bit[idx];
        idx -= idx & (-idx);
    }
    return res;
}

void update(int p, int v){
    int idx = p;
    while ( idx <= s ){
        bit[idx] += v;
        idx += idx & (-idx);
    }
}

ll calc(int k){
    ll t = x, res = 0;

    if ( k == 1 ) return t;

    while ( t ){
        if ( t == 1 ){ res ++; break; }
        while ( t % k != 0 ) t --, res ++;
        if ( t == 0 ) break;
        t /= k, res ++;
    }

    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> s >> x;
    for (int i = 1; i <= 100; i ++) c[i] = calc(i);

    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) cout << c[a[i]] << ' '; cout << '\n';

    ll ans = 0;
    if ( c[a[1]] < s ) update(c[a[1]], 1);

    for (int i = 2; i < n; i ++){
        for (int j = i + 1; j <= n; j ++){
            ll t = c[a[i]] + c[a[j]];
            if ( s - t > 0 ) ans += get(s-t);
        }
        if ( c[a[i]] < s ) update(c[a[i]], 1);
    }

    cout << ans;

    return 0;
}
