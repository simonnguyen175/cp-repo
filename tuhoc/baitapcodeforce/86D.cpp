#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;

int n, t, k;
ll a[N];
struct query{
    int l, r, id;
} q[N];
ll d[N*10];
ll ans[N], res = 0;

bool cmp(query a, query b){
    if ( a.l/k != b.l/k ) return a.l/k < b.l/k;
    else return a.r < b.r;
}

void add(ll x){
    res += 2*d[x]*x + x;
    d[x] ++;
}

void sub(ll x){
    res -= 2*d[x]*x - x;
    d[x] --;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("86D.inp", "r") ){
        freopen("86D.inp", "r", stdin);
        freopen("86D.out", "w", stdout);
    }

    cin >> n >> t;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= t; i ++){
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    k = sqrt(n)+1;
    sort(q+1, q+1+t, cmp);
//
//    for (int i = 1; i <= t; i ++)
//        cout << q[i].l << ' ' << q[i].r << '\n';

    for (int i = q[1].l; i <= q[1].r; i ++) add(a[i]);
    ans[q[1].id] = res;


    for (int i = 2; i <= t; i ++){
        if ( q[i].l > q[i-1].l ) for (int j = q[i-1].l; j < q[i].l; j ++) sub(a[j]);
        else if ( q[i].l < q[i-1].l ) for (int j = q[i-1].l-1; j >= q[i].l; j --) add(a[j]);

        if ( q[i].r > q[i-1].r ) for (int j = q[i-1].r+1; j <= q[i].r; j ++) add(a[j]);
        else if ( q[i].r < q[i-1].r ) for (int j = q[i-1].r; j > q[i].r; j --) sub(a[j]);

        ans[q[i].id] = res;
    }

    for (int i = 1; i <= t; i ++)
        cout << ans[i] << '\n';

    return 0;
}
