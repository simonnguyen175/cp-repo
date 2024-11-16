#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 2e3 + 5;

int n, Q, nn;
int a[N], bit[N][N];
ll bit1[N], bit2[N], c[N][N], res[N*N];
struct que{
    int l, r, id;
    ll k;
} q[N*N];
struct range{
    int l, r;
    ll val;
} v[N*N];
map<int, int> id;

void upd(int u, int v){
    for (; u <= n; u += u&(-u)) bit1[u] += v, bit2[u] ++;
}

ll get1(int u){
    ll res = 0;
    for (; u >= 1; u -= u&(-u)) res += bit1[u];
    return res;
}

int get2(int u){
    int res = 0;
    for (; u >= 1; u -= u&(-u)) res += bit2[u];
    return res;
}

void update(int x, int y){
    int py = y;
    for (; x <= n; x += x&(-x))
    for (y = py; y <= n; y += y&(-y))
        bit[x][y] ++;
}

int get(int x, int y){
    int res = 0, py = y;
    for (; x >= 1; x -= x&(-x))
    for (y = py; y >= 1; y -= y&(-y))
        res += bit[x][y];
    return res;
}

void init(){
    cin >> n;
    vector<int> cont;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cont.pb(a[i]);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    for (int i = 0; i < cont.size(); i ++)
        id[cont[i]] = i + 1;

    for (int i = 1; i <= n; i ++){
        ll s = 0;
        for (int j = 1; j <= n; j ++) bit1[j] = bit2[j] = 0;
        s = a[i];
        upd(id[a[i]], a[i]);
        v[++nn] = {i, i, 0};

        for (int j = i + 1; j <= n; j ++){
            int cnt = get2(id[a[j]]);
            ll sles = get1(id[a[j]]);
            c[i][j] = c[i][j-1] + ( 1LL * cnt * a[j] - sles ) + ( s - sles - 1LL * (j - i - cnt) * a[j] );
            upd(id[a[j]], a[j]);
            v[++nn] = {i, j, c[i][j]};
            s += a[j];
        }
    }
}

void solve(){
    cin >> Q;
    for (int i = 1; i <= Q; i ++)
        cin >> q[i].l >> q[i].r >> q[i].k, q[i].id = i;

    sort(q + 1, q + 1 + Q, [](que a, que b){
        return a.k < b.k;
    });


    sort(v+1, v+1+nn, [](range a, range b){
        return a.val < b.val;
    });

    int ptr = 1;
    for (int i = 1; i <= Q; i ++){
        while ( ptr <= nn && v[ptr].val <= q[i].k ){
            update(v[ptr].l, v[ptr].r);
            ptr ++;
        }
        res[q[i].id] = get(q[i].r, q[i].r) - get(q[i].l-1, q[i].r);
    }

    for (int i = 1; i <= Q; i ++)
        cout << res[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    init();

    solve();

    return 0;
}
