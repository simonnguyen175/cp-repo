#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;
const int oo = (int)21e8 + 7;

int sub, n, q;
int child[N], parity[N], parityCount[2], sta[N][2], fin[N][2];
vector<int> adj[N];
struct Top{
    int v[16];

    Top(){
        for (int i = 1; i <= 15; i ++) v[i] = -oo;
    }
};
Top Merge(const Top &a, const Top &b){
    Top res;
    int x = 1, y = 1;
    for (int i = 1; i <= 15; i ++)
        res.v[i] = a.v[x] > b.v[y] ? a.v[x++] : b.v[y++];
    return res;
}
struct node{
    Top top;
    int lazy;
} st[2][4*N];

void dfs(int u, int high){
    for (int i = 0; i <= 1; i ++)
        sta[u][i] = parityCount[i] + 1;

    parity[u] = high;
    parityCount[high] ++;

    for (int v : adj[u])
        dfs(v, high^1);

    for (int i = 0; i <= 1; i ++)
        fin[u][i] = parityCount[i];
}

void build(int t, int id, int l, int r){
    st[t][id].top = Top();
    for (int i = 1; i <= min(r-l+1, 15); i ++)
        st[t][id].top.v[i] = 0;
    if ( l == r ) return;
    int mid = l + r >> 1;
    build(t, id*2, l, mid);
    build(t, id*2+1, mid+1, r);
}

void add(int t, int id, int val){
    for (int i = 1; i <= 15; i ++)
        if ( st[t][id].top.v[i] != -oo )
            st[t][id].top.v[i] += val;
        else break;
    st[t][id].lazy += val;
}

void down(int t, int id){
    for (int i = 0; i <= 1; i ++)
        add(t, id*2+i, st[t][id].lazy);
    st[t][id].lazy = 0;
}

void update(int t, int id, int l, int r, int u, int v, int val){
    if ( l > v || r < u || u > v ) return;
    if ( u <= l && r <= v ){
        add(t, id, val);
        return;
    }

    down(t, id);

    int mid = l + r >> 1;
    update(t, id*2, l, mid, u, v, val);
    update(t, id*2+1, mid+1, r, u, v, val);

    st[t][id].top = Merge(st[t][id*2].top, st[t][id*2+1].top);
}

Top get(int t, int id, int l, int r, int u, int v){
    if ( l > v || r < u || u > v ) return Top();
    if ( u <= l && r <= v ) return st[t][id].top;

    down(t, id);

    int mid = l + r >> 1;
    Top L = get(t, id*2, l, mid, u, v);
    Top R = get(t, id*2+1, mid+1, r, u, v);

    return Merge(L, R);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("query.inp", "r") ){
        freopen("query.inp", "r", stdin);
        freopen("query.out", "w", stdout);
    }

    cin >> sub >> n;
    for (int i = 2, x; i <= n; i ++){
        cin >> x;
        adj[x].pb(i);
    }

    dfs(1, 0);

    for (int i = 0; i <= 1; i ++)
        build(i, 1, 1, parityCount[i]);

    cin >> q;
    string type;
    int u, val, k;
    while ( q -- ){
        cin >> type;

        if ( type[0] == 'a' ){
            cin >> u >> val;
            int t = parity[u];
            update(t, 1, 1, parityCount[t], sta[u][t], fin[u][t], val);
            t ^= 1;
            update(t, 1, 1, parityCount[t], sta[u][t], fin[u][t], -val);
        }

        if ( type[0] == 'g' ){
            cin >> u;
            int t = parity[u];
            Top res = get(t, 1, 1, parityCount[t], sta[u][t], sta[u][t]);
            cout << res.v[1] << ' ';
        }

        if ( type[0] == 'p' ){
            cin >> u >> k;
            int t = parity[u];
            Top res1 = get(t, 1, 1, parityCount[t], sta[u][t], fin[u][t]);
            t ^= 1;
            Top res2 = get(t, 1, 1, parityCount[t], sta[u][t], fin[u][t]);
            Top res = Merge(res1, res2);

            cout << ( res.v[k] == -oo ? 0 : res.v[k] ) << ' ';
        }
    }

    return 0;
}
