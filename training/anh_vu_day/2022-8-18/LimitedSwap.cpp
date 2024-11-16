#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, k;
int ans[N];
struct node{
    int val, pos, cnt, num1;
} st[4*N];

node combine(node lef, node rig){
    node res;
    if ( lef.val >= rig.val ){
        res = lef;
        res.num1 += rig.num1;
        return res;
    }
    else{
        res = rig;
        res.cnt += lef.num1;
        res.num1 += lef.num1;
        return res;
    }
}

void update(int id, int l, int r, int u, int val, int add){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id] = {val, u, add, add};
        return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, val, add);
    update(id*2+1, mid+1, r, u, val, add);
    st[id] = combine(st[id*2], st[id*2+1]);
}

node get(int id, int l, int r, int lim){
    if ( l == r ){
        if ( st[id].cnt <= lim ) return st[id];
        else return {-1, 0, 0, 0};
    }

    int mid = l + r >> 1;

    if ( st[id].cnt <= lim ) return st[id];

    if ( st[id*2].num1 > lim ) return get(id*2, l, mid, lim);
    else return combine(st[id*2], get(id*2+1, mid+1, r, lim-st[id*2].num1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("in.inp", "r") ){
        freopen("in.inp", "r", stdin);
        freopen("out.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;
        update(1, 1, n, i, x, 1);
    }

    for (int i = 1; i <= n; i ++){
        node tmp = get(1, 1, n, k+1);
        k -= tmp.cnt-1;
        ans[i] = tmp.val;
        update(1, 1, n, tmp.pos, -1, 0);
    }

    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
