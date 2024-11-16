#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n;
int a[N], p[N], b[N], c[N], bit[N];

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
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i], p[a[i]] = i;
    for (int i = 1; i <= n; i ++) cin >> b[i], c[i] = p[b[i]];

    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int res = get(c[i] - 1);
        ans = max(ans, res + 1);
        update(c[i], res + 1);
    }

    cout << ans;

    return 0;
}
