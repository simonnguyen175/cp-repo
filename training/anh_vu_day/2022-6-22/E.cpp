#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5e5 + 5;

int n, Q;
int a[N], pre0;
struct query{
    int l, r, id;
} q[N];
struct node{
    int sum, cnt0, suf;
} st[4*N];
int res[N];

node combine(node L, node R){
    node res;
    res.sum = L.sum + R.sum;
    res.cnt0 = L.cnt0 + R.cnt0;
    res.suf = min(L.suf+R.sum, R.suf);
    return res;
}

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id].sum = st[id].suf = v;
        st[id].cnt0 = ( v == 0 );
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = combine(st[id*2], st[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return {0, 0, n+1};
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return combine(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        char x;
        cin >> x;
        a[i] = ( x == 'X' ? 1 : -1 );
    }

    cin >> Q;
    for (int i = 1; i <= Q; i ++)
        cin >> q[i].l >> q[i].r, q[i].id = i;
    sort(q+1, q+1+Q, [](query a, query b){
        return a.l > b.l;
    });
    q[0] = {n+1, 0};

    vector<int> pos0;
    for (int i = 1; i <= Q; i ++){
//        cerr << "query " << i << " : \n";

        for (int j = q[i-1].l-1; j >= q[i].l; j --){
            if ( a[j] == -1 ) update(1, 1, n, j, 0), pos0.pb(j);
            if ( a[j] == 1 ){
                update(1, 1, n, j, 1);
                if ( pos0.size() ){
//                    cerr << pos0.back() << '\n';
                    update(1, 1, n, pos0.back(), -1), pos0.pop_back();
                }
            }
        }

//        cerr << q[i].l << ' ' << q[i].r << ' ' << pos0.size() << '\n';

        node tmp = get(1, 1, n, q[i].l, q[i].r);

//        cerr << tmp.cnt0 << ' ' << tmp.suf << '\n';

        res[q[i].id] = tmp.cnt0 - ( tmp.suf < 0 ? tmp.suf : 0 );
    }

    for (int i = 1; i <= Q; i ++)
        cout << res[i] << '\n';

    return 0;
}
