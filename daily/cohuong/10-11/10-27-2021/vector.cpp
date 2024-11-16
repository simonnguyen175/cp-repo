#include<bits/stdc++.h>
#define simon "vector"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int n, m;
int a[N][25];

namespace sub6{
    int f[N], ans = 0;

    bool ckmax(int u, int v){
        for (int i = 1; i <= m; i ++)
            if ( a[u][i] <= a[v][i] ) return false;
        return true;
    }

    void solve(){
        for (int i = 1; i <= n; i ++){
            f[i] = 1;
            for (int j = 1; j < i; j ++)
                if ( ckmax(i, j) )
                    f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        cout << ans;
    }
}

namespace sub5{
    int bit[N], ans = 0;
    map<int, int> id;
    vector<int> cont;

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

    void solve(){
        for (int i = 1; i <= n; i ++)
            cont.push_back(a[i][1]);
        sort(cont.begin(), cont.end());
        cont.erase(unique(cont.begin(), cont.end()), cont.end());

        for (int i = 0; i < cont.size(); i ++)
            id[cont[i]] = i + 1;

        for (int i = 1; i <= n; i ++){
            int best = get(id[a[i][1]]-1) + 1;
            update(id[a[i][1]], best);
            ans = max(ans, best);
        }

        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    for (int j = 1; j <= m; j ++)
        cin >> a[i][j];

    for (int i = 1; i <= n; i ++)
        sort(a[i] + 1, a[i] + 1 + m);

    if ( n <= 1000 ) sub6::solve();
    else sub5::solve();

    return 0;
}
