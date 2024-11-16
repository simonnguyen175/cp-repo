#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, sta, d, nn;
int a[N];
ll s[N];
vector<int> cont;
struct node{
    int cnt = 0;
    ll sum = 0;
} st[4*N];
ll ans = 0;

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){
//        cout << "update " << l << ' ' << v << '\n';
        st[id].cnt += v;
        st[id].sum = st[id].cnt * cont[u-1];
        return;
    }

    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);

    st[id].cnt = st[id*2].cnt + st[id*2+1].cnt;
    st[id].sum = st[id*2].sum + st[id*2+1].sum;
}

ll get(int k){
    if ( k <= 0 ) return 0;
    if ( st[1].cnt <= k ) return st[1].sum;
    int l = 1, r = nn, id = 1;
    ll res = 0;
    while ( l <= r ){
        if ( l == r ){
            res += k * cont[l-1];
            break;
        }
        int mid = l + r >> 1;
        if ( st[id*2+1].cnt >= k ) l = mid+1, id = id*2+1;
        else res += st[id*2+1].sum, k -= st[id*2+1].cnt, r = mid, id = id*2;
    }
    return res;
}

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void solve(int l, int r, int u, int v){
    if ( l > r || u > v ) return;

    int mid = l + r >> 1;

    for (int i = r; i >= mid; i --)
        update(1, 1, nn, id(a[i]), 1);

    int pos = u;
    ll res = 0;

    /// sang trai roi sang phai
    for (int i = u; i <= v; i ++){
        update(1, 1, nn, id(a[i]), 1);
        int rem = d - 2 * (sta - mid) - (i - sta);
        ll tmp = get(rem);
        if ( res < tmp ) res = tmp, pos = i;
    }

    for (int i = u; i <= v; i ++)
        update(1, 1, nn, id(a[i]), -1);

    /// sang phai roi sang trai
    for (int i = u; i <= v; i ++){
        update(1, 1, nn, id(a[i]), 1);
        int rem = d - (sta - mid) - 2 * (i - sta);
        ll tmp = get(rem);
        if ( res < tmp ) res = tmp, pos = i;
    }

    for (int i = u; i <= v; i ++)
        update(1, 1, nn, id(a[i]), -1);

    ans = max(ans, res);

    solve(l, mid-1, u, pos);

    for (int i = r; i >= mid; i --)
        update(1, 1, nn, id(a[i]), -1);

    solve(mid+1, r, pos, v);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> sta >> d;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        cont.pb(a[i]);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    nn = cont.size();

    /// di 1 phia
    for (int i = sta; i >= 0; i --){
        update(1, 1, nn, id(a[i]), 1);
        int rem = d - (sta - i);
        ll tmp = get(rem);
        ans = max(ans, tmp);
    }

    for (int i = sta - 1; i >= 0; i --)
        update(1, 1, nn, id(a[i]), -1);

    for (int i = sta+1; i < n; i ++){
        update(1, 1, nn, id(a[i]), 1);
        int rem = d - (i - sta);
        ll tmp = get(rem);
        ans = max(ans, tmp);
    }

    for (int i = sta+1; i < n; i ++)
        update(1, 1, nn, id(a[i]), -1);

    /// di ca 2 phia
    solve(0, sta - 1, sta + 1, n - 1);

    cout << ans;

    return 0;
}
