#include<bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;
const int N = 5e4 + 5;
const ll oo = 1e12;

struct node{
    ll lsum;
    ll rsum;
    ll sum;
    ll gss;
};

int n, m, a[N];
node st[4*N];

void update(int id, int l, int r, int i){
    if ( l > i || r < i ) return;
    if ( l == r ){
        st[id].lsum = a[l];
        st[id].rsum = a[l];
        st[id].sum = a[l];
        st[id].gss = a[l];
        return;
    }

    int mid = ( l + r ) / 2;

    update(id*2, l, mid, i);
    update(id*2+1, mid + 1, r, i);

    st[id].lsum = max(st[id*2].lsum, st[id*2].sum + st[id*2+1].lsum);
    st[id].rsum = max(st[id*2+1].rsum, st[id*2+1].sum + st[id*2].rsum);
    st[id].sum = st[id*2].sum + st[id*2+1].sum;
    st[id].gss = max({st[id*2].gss, st[id*2+1].gss, st[id*2].rsum + st[id*2+1].lsum});
}

node query(int id, int l, int r, int u, int v){
    if ( l >= u && r <= v ) return st[id];

    int mid = ( l + r ) / 2;

    if ( mid < u ) return query(id*2+1, mid+1, r, u, v);
    if ( mid >= v ) return query(id*2, l, mid, u, v);

    node left = query(id*2, l, mid, u, v);
    node right = query(id*2+1, mid+1, r, u, v);
    node res;

    res.lsum = max(left.lsum, left.sum + right.lsum);
    res.rsum = max(right.rsum, right.sum + left.rsum);
    res.sum = left.sum + right.sum;
    res.gss = max({left.gss, right.gss, left.rsum + right.lsum});

    return res;
}

int main(){
    FASTio
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    for (int i = 1; i <= n; i ++)
        update(1, 1, n, i);

    /*
    for (int i = 1; i <= 4 * n; i ++)
        cout << st[i].gss << '\n';
    */

    cin >> m;
    while ( m-- ){
        int x, y;
        cin >> x >> y;
        node res = query(1, 1, n, x, y);
        cout << res.gss << '\n';
    }

    return 0;
}
