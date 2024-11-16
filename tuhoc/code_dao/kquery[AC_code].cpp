#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e4 + 5;
const int T = 2e5 + 5;

struct ques{
    int l, r, k, p;
};

bool compare(ques a, ques b){
    return a.k < b.k;
}

int n, t;
pair<int, int> a[N];
ques q[T];
int st[4*N], res[T];

void update(int id, int l, int r, int u, int w){
    if ( r < u || u < l ) return;

    if ( l == r ){
        st[id] = w;
        return;
    }

    int mid = ( l + r ) / 2;

    update(id * 2, l, mid, u, w);
    update(id * 2 + 1, mid + 1, r, u, w);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v){
    if ( r < u || l > v ) return 0;

    if ( u <= l && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi;
        a[i].se = i;
    }

    cin >> t;
    for (int i = 1; i <= t; i ++){
        cin >> q[i].l >> q[i].r >> q[i].k;
        q[i].p = i;
    }

    sort(a + 1, a + 1 + n);
    sort(q + 1, q + 1 + t, compare);

    for (int i = 1; i <= n; i ++)
        update(1, 1, n, i, 1);

    int pos = 1;

    for (int i = 1; i <= t; i ++){
        while ( pos <= n && a[pos].fi <= q[i].k ){
            update(1, 1, n, a[pos].se, 0);
            pos ++;
        }

        res[q[i].p] = get(1, 1, n, q[i].l, q[i].r);
    }

    for (int i = 1; i <= t; i ++)
        cout << res[i] << '\n';

    return 0;
}
