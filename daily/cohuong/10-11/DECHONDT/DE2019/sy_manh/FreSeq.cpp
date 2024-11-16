#include<bits/stdc++.h>
#define simon "freseq"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int n, q;
int a[N], st[4*N];
map<int, int> id;

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ) { st[id] ++; return; }
    int mid = ( l + r ) / 2;
    update(id*2, l, mid, u);
    update(id*2+1, mid+1, r, u);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = ( l + r ) / 2;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

namespace sub1{
    void solve(){
        for (int i = 1; i <= q; i ++){
            int u, v; cin >> u >> v;
            vector<int> tmp;
            for (int j = u; j <= v; j ++) tmp.push_back(a[j]);
            sort(tmp.begin(), tmp.end());
            int res = 0, cnt = 1;
            for (int j = 1; j < tmp.size(); j ++)
                if ( tmp[j] == tmp[j-1] ) cnt ++;
                else{
                    res = max(res, cnt);
                    cnt = 1;
                }
            res = max(res, cnt);
            cout << res << '\n';
        }
    }
}

namespace sub2{
    int f[15][N];

    void solve(){
        for (int j = 0; j <= 10; j ++) f[j][0] = 0;

        for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= 10; j ++)
            if ( a[i] == j ) f[j][i] = f[j][i-1] + 1;
            else f[j][i] = f[j][i-1];

        for (int i = 1; i <= q; i ++){
            int u, v; cin >> u >> v;
            int res = 0;
            for (int j = 0; j <= 10; j ++)
                res = max(res, f[j][v]-f[j][u-1]);
            cout << res << '\n';
        }
    }
}

namespace sub3{
    map<int, int> l, r;
    void solve(){
        for (int i = 1; i <= n; i ++) if ( !l[a[i]] ) l[a[i]] = i;
        for (int i = n; i >= 1; i --) if ( !r[a[i]] ) r[a[i]] = i;

        for (int i = 1; i <= q; i ++){
            int u, v; cin >> u >> v;
            int res = 0;
            int u1 = id[a[u]] + 1, v1 = id[a[v]] - 1;
            if ( u1 > v1 ) res = 0;

            else res = get(1, 1, n, u1, v1);

            res = max({res, r[a[u]] - u + 1, v - l[a[v]] + 1});
            cout << res << '\n';
        }
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> q;
    int mx = 0;
    vector<int> cont;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        mx = max(mx, a[i]);
        cont.push_back(a[i]);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    int cnt = 0;
    for (int v : cont) id[v] = ++cnt;
    for (int i = 1; i <= n; i ++) update(1, 1, n, id[a[i]]);

    if ( n <= 1000 && q <= 1000 ) { sub1::solve(); return 0; }

    if ( mx <= 10 ) { sub2::solve(); return 0; }

    sub3::solve();

    return 0;
}
