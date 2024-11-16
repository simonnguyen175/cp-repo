#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n;
int a[N], pre[N], pos[N];
struct node{
    int res = n + 1, pos = 0, lazy = 0;
} st[4*N];

void down(int id){
    int t = st[id].lazy;
    st[id*2].lazy += t;
    st[id*2+1].lazy += t;

    if ( st[id*2].res == n + 1 ) st[id*2].res = t;
    else st[id*2].res += t;
    if ( st[id*2+1].res == n + 1 ) st[id*2+1].res = t;
    else st[id*2+1].res += t;

    st[id].lazy = 0;
}

node combine(node left, node right){
    if ( left.res <= right.res ) return left;
    else return right;
}

void build(int id, int l, int r){
    if ( l == r ){
        st[id].res = n + 1;
        st[id].pos = l;
        st[id].lazy = 0;
        return;
    }

    int mid = ( l + r ) / 2;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    st[id] = combine(st[id*2], st[id*2+1]);
}

void update(int id, int l, int r, int u, int v, int val){
    if ( v < l || r < u ) return;

    if ( u <= l && r <= v ){
        if ( st[id].res == n + 1 ) st[id].res = val;
        else st[id].res += val;
        st[id].lazy += val;
        return;
    }

    int mid = ( l + r ) / 2;

    down(id);

    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);

    st[id] = combine(st[id*2], st[id*2+1]);
}

void printtree(int id, int l, int r){
    cout << "node[" << l  << ".." << r << "] : " << st[id].res << ' ' << st[id].pos << ' ' << st[id].lazy << '\n';
}

node get(int id, int l, int r, int u, int v){
    if ( v < l || r < u ) {node res; return res;}

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    down(id);

    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

pair<int, int> minimize(pair<int, int> a, pair<int, int> b){
    if ( a.first < b.first ) return a;
        else
            if ( a.first == b.first ){
                if ( a.second < b.second ) return b;
                else return a;
            }
            else return b;
}

void solve(){
    unordered_map<int, int> pos;
    for (int i = 1; i <= n; i ++) pre[i] = 0;

    for (int i = 1; i <= n; i ++){
        if ( pos[a[i]] ) pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }

    build(1, 1, n);

    pair<int, int> ans;
    ans.first = n + 1;

    for (int i = 1; i <= n; i ++){
        update(1, 1, n, pre[i] + 1, i, 1);
        node l = get(1, 1, n, 1, i);
        ans = minimize(ans, make_pair(l.res, i-l.pos+1));
    }

    cout << ans.first << ' ' << ans.second << '\n';
}

int main(){
    if ( fopen("repseq.inp", "r") ){
        freopen("repseq.inp", "r", stdin);
        freopen("repseq.out", "w", stdout);
    }

    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    while ( cin >> n ){
        for (int i = 1; i <= n; i ++)
            cin >> a[i];
        solve();
    }
}
