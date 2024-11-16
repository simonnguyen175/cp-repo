#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 3;
const int base = 17;

int n, q;
vector<int> cont[N];
int pw[N], par[N], st[4*N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1ll * a * b % MOD;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id] = l;
        return;
    }

    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = add(mul(st[id*2], pw[r-mid]), st[id*2+1]);
}

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] = v;
        return;
    }

    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);

    st[id] = add(mul(st[id*2], pw[r-mid]), st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    int lef = get(id*2, l, mid, u, v);
    int rig = get(id*2+1, mid+1, r, u, v);

    return add(mul(lef, pw[max(0, v-mid)]), rig);
}

int Find(int u){
    if ( u == par[u] ) return u;
    else return par[u] = Find(par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( cont[u].size() < cont[v].size() ) swap(u, v);
    par[v] = u;
    for (auto it : cont[v])
        cont[u].pb(it);
    cont[v].clear();
    for (auto it : cont[u])
        update(1, 1, n, it, u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> q;

    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw[i] = mul(pw[i-1], base);

    build(1, 1, n);

//    while ( q -- ){
//        int type;
//        cin >> type;
//
//        if ( type == 1 ){
//            int l, r;
//            cin >> l >> r;
//            int id = l;
//            while ( id <= (l + r)/2 ){
//                if ( Find(id) != Find(r - id + l) ){
//                    Join(id, r - id + l);
//                    id ++;
//                }
//                else{
//                    int lo = id, hi = (l + r)/2, nxt;
//                    while ( lo <= hi ){
//                        int mid = (lo + hi)/2;
//                        if ( get(1, 1, n, id, mid) == get(1, 1, n, r-mid+l, r-id+l) )
//                            nxt = mid, lo = mid + 1;
//                        else hi = mid - 1;
//                    }
//                    id = nxt + 1;
//                }
//            }
//        }
//        else{
//            int a, b, x, y;
//            cin >> a >> b >> x >> y;
//
//            int u = get(1, 1, n, a, b);
//            int v = get(1, 1, n, x, y);
//
//            if ( b-a != y-x ) cout << 1 << '\n';
//            else if ( u == v ) cout << 0 << '\n';
//            else cout << 2 << '\n';
//        }
//    }

    return 0;
}
