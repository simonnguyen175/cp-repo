#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, T;
int a[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

namespace sub1{
    int f[N];

    void solve(){
        ll sum = 0;
        for (int i = 1; i <= n; i ++){
            sum = add(sum, -f[a[i]]);
            f[a[i]] = add(f[a[i]], add(sum, 1));
            sum = add(sum, f[a[i]]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i ++)
            ans = add(ans, f[i]);

        cout << ans;
    }
}

namespace sub2{
    int d[N], f[N], st[4*N], ans = 0;

    void update(int id, int l, int r, int u, int v){
        if ( l > u || r < u ) return;
        if ( l == r ){
            st[id] = v;
            return;
        }
        int mid = l + r >> 1;
        update(id*2, l, mid, u, v);
        update(id*2+1, mid+1, r, u, v);
        st[id] = add(st[id*2], st[id*2+1]);
    }

    int get(int id, int l, int r, int u, int v){
        if ( l > v || r < u ) return 0;
        if ( u <= l && r <= v ) return st[id];
        int mid = l + r >> 1;
        return add(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
    }

    void solve(){
        for (int i = 1; i <= n; i ++){
            if ( !d[a[i]] ) f[i] = add(get(1, 1, n, 1, i-1), 1);
            else{
                f[i] = get(1, 1, n, d[a[i]], i-1);
                f[d[a[i]]] = 0;
                update(1, 1, n, d[a[i]], 0);
            }
            update(1, 1, n, i, f[i]);
            d[a[i]] = i;
        }


        for (int i = 1; i <= n; i ++){
            ans = add(ans, f[i]);
        }
        cout << ans;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

//    if ( fopen("subsequence.inp", "r") ){
//        freopen("subsequence.inp", "r", stdin);
//        freopen("subsequence.out", "w", stdout);
//    }

    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    if ( T == 1 ) sub1::solve();
    else sub2::solve();

    return 0;
}
