#include<bits/stdc++.h>
#define simon "L1L2K"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e6 + 5;

int n, k, m = 0, ans = 0;
int a[N], bit[N];

void update(int u, int v){
    for (; u <= n; u += u & (-u))
        bit[u] = max(bit[u], v);
}

int get(int u){
    int res = 0;
    for (; u > 0; u -= u & (-u))
        res = max(res, bit[u]);
    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        for (int j = min(n, x+k); j >= max(1, x-k); j --)
            a[++m] = j;
    }

    for (int i = 1; i <= m; i ++){
        int best = get(a[i]-1) + 1;
        update(a[i], best);
        ans = max(ans, best);
    }

    cout << ans;

    return 0;
}
