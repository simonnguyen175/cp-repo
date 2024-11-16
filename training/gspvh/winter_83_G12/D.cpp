#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int sub, n, q;
int a[N], s[N], bit[N], ans[N];
map<int, int> d;
struct query{
    int l, r, id;
} que[N];

void update(int u, int v){
    for (; u <= n; u += u&-u)
        bit[u] ^= v;
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&-u)
        res ^= bit[u];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("sumxor.inp", "r", stdin);
    freopen("sumxor.out", "w", stdout);

    cin >> sub >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], s[i] = s[i-1] ^ a[i];
    cin >> q;
    for (int i = 1; i <= q; i ++)
        cin >> que[i].l >> que[i].r, que[i].id = i;

    sort(que + 1, que + 1 + q, [&](query a, query b){
        return a.r < b.r;
    });

    int id = 1;
    for (int i = 1; i <= q; i ++){
        while ( id <= que[i].r && id <= n ){
            if ( d[a[id]] ) update(d[a[id]], a[id]);
            update(id, a[id]);
            d[a[id]] = id;
            id ++;
        }
        ans[que[i].id] = get(que[i].r) ^ get(que[i].l-1) ^ s[que[i].r] ^ s[que[i].l-1];
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << ' ';

    return 0;
}
