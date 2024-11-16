#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, m, k, ptr;
int p[N];
ll ans[N];
struct query{
    int l, r, w;
} que[N];
vector<int> cont[N];
ll bit[N];

void update(int u, int w){
    for (; u <= m; u += u&-u)
        bit[u] += w;
}

void upd(int l, int r, int w){
    update(l, w);
    update(r+1, -w);
}

ll get(int u){
    ll res = 0;
    for (; u >= 1; u -= u&-u)
        res += bit[u];
    return res;
}

void solve(int l, int r, vector<int> &candi){
    int mid = l + r >> 1;

    while ( ptr < mid ){
        ptr ++;
        if ( que[ptr].l <= que[ptr].r )
            upd(que[ptr].l, que[ptr].r, que[ptr].w);
        else{
            upd(que[ptr].l, m, que[ptr].w);
            upd(1, que[ptr].r, que[ptr].w);
        }
    }

    while ( ptr > mid ){
        if ( que[ptr].l <= que[ptr].r )
            upd(que[ptr].l, que[ptr].r, -que[ptr].w);
        else{
            upd(que[ptr].l, m, -que[ptr].w);
            upd(1, que[ptr].r, -que[ptr].w);
        }
        ptr --;
    }

//    cout << l << ' ' << r << " : \n";
    vector<int> L, R;
    for (int x : candi){
        ll cnt = 0;
        for (int y : cont[x])
            cnt += get(y);

//        cout << x << ' ' << cnt << '\n';

        if ( cnt >= p[x] ){
            ans[x] = mid;
            L.pb(x);
        }
        else R.pb(x);
    }
//    cout << '\n';

    if ( l == r ) return;

    if ( L.size() ) solve(l, mid, L);
    if ( R.size() ) solve(mid+1, r, R);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, x; i <= m; i ++)
        cin >> x, cont[x].pb(i);
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    cin >> k;
    for (int i = 1; i <= k; i ++)
        cin >> que[i].l >> que[i].r >> que[i].w;

    vector<int> candi;
    for (int i = 1; i <= n; i ++) candi.pb(i);
    solve(1, k, candi);

    for (int i = 1; i <= n; i ++)
        if ( !ans[i] ) cout << "NIE\n";
        else cout << ans[i] << '\n';

    return 0;
}
