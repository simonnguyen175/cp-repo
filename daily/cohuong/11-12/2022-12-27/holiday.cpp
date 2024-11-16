#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, sta, d;
int a[N];
vector<int> cont;
struct node{
    int cnt;
    ll sum;
} st[4*N];
ll ans = 0;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
        st[id].cnt += v;
        st[id].sum = 1ll * st[id].cnt * cont[u - 1];
        return;
    }

    int mid = l + r >> 1;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);

    st[id].cnt = st[id * 2].cnt + st[id * 2 + 1].cnt;
    st[id].sum = st[id * 2].sum + st[id * 2 + 1].sum;
}

ll get(int k){
    int id = 1, l = 1, r = n;
    ll res = 0;

    while ( l <= r ){
        if ( l == r ){
            res += 1ll * min(k, st[id].cnt) * cont[l-1];
            break;
        }

        int mid = l + r >> 1;
        if ( st[id * 2 + 1].cnt >= k ) id = id * 2 + 1, l = mid + 1;
        else k -= st[id * 2 + 1].cnt, res += st[id * 2 + 1].sum, id = id * 2, r = mid;
    }

    return res;
}

void solve(int l, int r, int u, int v){
    int mid = l + r >> 1;

    for (int i = l; i < mid; i ++)
        update(1, 1, cont.size(), id(a[i]), -1);

    int pos = -1;
    ll res = 0;
//    cout << mid << " : \n";
    for (int i = u; i <= v; i ++){
        update(1, 1, cont.size(), id(a[i]), 1);
        int rem = d - (sta - mid) * 2 - (i - sta);
        if ( rem <= 0 ) break;
        ll tmp = get(rem);
//        cout << i << ' ' << rem << ' ' << tmp << '\n';
        if ( res < tmp ) res = tmp, pos = i;
    }

    if ( pos == -1 ) return;

//    cout << " -> " << pos << ' ' << res << '\n';

    ans = max(ans, res);

    for (int i = pos; i <= v; i ++)
        update(1, 1, cont.size(), id(a[i]), -1);
    if ( r > mid ) solve(mid + 1, r, pos, v);

    for (int i = l; i < mid; i ++)
        update(1, 1, cont.size(), id(a[i]), 1);
    for (int i = u; i < pos; i ++)
        update(1, 1, cont.size(), id(a[i]), -1);
    if ( l < mid ) solve(l, mid - 1, u, pos);
}

void solve1(int l, int r, int u, int v){
    int mid = l + r >> 1;

    for (int i = r; i > mid; i --)
        update(1, 1, cont.size(), id(a[i]), -1);

    int pos = -1;
    ll res = 0;
    for (int i = v; i >= u; i --){
        update(1, 1, cont.size(), id(a[i]), 1);
        int rem = d - 2 * (mid - sta) - (sta - i);
        if ( rem <= 0 ) break;
        ll tmp = get(rem);
        if ( res < tmp ) res = tmp, pos = i;
    }

    if ( pos == -1 ) return;

    ans = max(res, ans);

    for (int i = pos; i >= u; i --)
        update(1, 1, cont.size(), id(a[i]), -1);
    if ( l < mid ) solve1(l, mid - 1, u, pos);

    for (int i = r; i > mid; i --)
        update(1, 1, cont.size(), id(a[i]), 1);
    for (int i = v; i > pos; i --)
        update(1, 1, cont.size(), id(a[i]), -1);
    if ( r > mid ) solve1(mid + 1, r, pos, v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("holiday.inp", "r") ){
        freopen("holiday.inp", "r", stdin);
        freopen("holiday.out", "w", stdout);
    }

    cin >> n >> sta >> d;
    sta ++;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cont.pb(a[i]);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 1; i <= sta; i ++)
        update(1, 1, cont.size(), id(a[i]), 1);

    solve(1, sta, sta + 1, n);

    for (int i = 1; i <= 4 * (int)cont.size(); i ++)
        st[i].cnt = st[i].sum = 0;
    for (int i = n; i >= sta; i --)
        update(1, 1, cont.size(), id(a[i]), 1);
    solve1(sta, n, 1, sta - 1);

    cout << ans;

    return 0;
}
