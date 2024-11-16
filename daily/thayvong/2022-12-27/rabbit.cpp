#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, m;
int h[N], bit[N];
vector<int> cont;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void update(int u, int v){
    for (; u <= n; u += u&-u)
        bit[u] = max(bit[u], v);
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res = max(res, bit[u]);
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("rabbit.inp", "r", stdin);
    freopen("rabbit.out", "w", stdout);

    cin >> n >> m;
    int add = 0;
    for (int i = 1; i <= n; i ++){
        cin >> h[i];
        if ( h[i] > i * m ) add ++;
        else cont.pb(h[i] - i * m);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    int ans = n - add;
    for (int i = n; i >= 1; i --) if ( h[i] <= i * m ){
        int cur = get(id(h[i] - i * m)) + 1;
        ans = min(ans, n - add - cur);
        update(id(h[i] - i * m), cur);
    }

    cout << ans + add;

    return 0;
}
