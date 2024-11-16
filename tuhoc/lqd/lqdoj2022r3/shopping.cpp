#include<bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, q;
int a[N];
struct query{
    int l, u, v, k, id;
} que[N];

namespace sub1{
    ll s[N];

    void solve(){
        s[0] = 0;
        for (int i = 1; i <= n; i ++)
            s[i] = s[i-1] + a[i];
        for (int i = 1; i <= q; i ++){
            int lo = que[i].l, hi = n, res = -1;
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( s[mid]-s[que[i].l-1] <= que[i].k ) res = mid, lo = mid + 1;
                else hi = mid - 1;
            }
            if ( res == -1 ) cout << 0 << '\n';
            else cout << res-que[i].l+1 << '\n';
        }
    }
}

namespace sub2{
    pi b[N];
    int ans[N];
    ll bit[N];

    void update(int u, int v){
        for (; u <= n; u += u&-u)
            bit[u] += v;
    }

    ll get(int u){
        ll res = 0;
        for (; u >= 1; u -= u&-u)
            res += bit[u];
        return res;
    }

    void solve(){
        sort(que + 1, que + 1 + q, [&](query x, query y){
            return x.v < y.v;
        });
        for (int i = 1; i <= n; i ++) b[i] = {a[i], i};
        sort(b + 1, b + 1 + n);

        int id = 1;
        for (int i = 1; i <= q; i ++){
            while ( id <= que[i].v && id <= n ){
                update(b[id].se, b[id].fi);
                id ++;
            }

            int lo = que[i].l, hi = n, res = -1;
            ll pre = get(que[i].l-1);
            while ( lo <= hi ){
                int mid = lo + hi >> 1;
                if ( get(mid) - pre <= que[i].k ) res = mid, lo = mid + 1;
                else hi = mid - 1;
            }
            if ( res == -1 ) ans[que[i].id] = 0;
            else ans[que[i].id] = res - que[i].l + 1;
        }

        for (int i = 1; i <= q; i ++)
            cout << ans[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];

    bool sub1 = 1, sub2 = 1;
    for (int i = 1; i <= q; i ++){
        cin >> que[i].l >> que[i].u >> que[i].v >> que[i].k;
        que[i].id = i;
        sub1 &= ( que[i].u == 1 && que[i].v == 1e9 );
        sub2 &= ( que[i].u == 1 );
    }

    if ( sub1 ) { sub1::solve(); return 0; }
    if ( sub2 ) { sub2::solve(); return 0; }

    return 0;
}
