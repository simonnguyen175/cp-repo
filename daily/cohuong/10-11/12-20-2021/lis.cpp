#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, x;
int a[N], f[N], g[N], st[4*N];
map<int, int> id;
vector<int> cont;

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ) { st[id] = max(st[id], v); return; }
    int mid = ( l + r ) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( u > v ) return 0;
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = ( l + r ) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void init(){
    cin >> n >> x;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        cont.pb(a[i]);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    int cnt = 0;
    for (int v : cont) {
        id[v] = ++cnt;
    }

    for (int i = n; i >= 1; i --){
        f[i] = get(1, 1, n, id[a[i]]+1, n) + 1;
        update(1, 1, n, id[a[i]], f[i]);
    }
}

int getid(int x){
    int lo = 0, hi = cont.size()-1, res = 0;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( cont[mid] < x ){
            res = cont[mid];
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return id[res];
}

void solve(){
    int ans = 0;

    for (int i = 1; i <= 4 * n; i ++) st[i] = 0;

    //for (int i = n; i >= 1; i --) cout << f[i] << ' '; cout << '\n;

    //cout << a[26] << ' ' << getid(a[26]+x) << '\n';

    for (int i = 1; i <= n; i ++){
        // update ans
        int p = getid(a[i]+x);
        int tmp = get(1, 1, n, 1, p) + f[i];
        ans = max(ans, tmp);

        // update st
        int len = get(1, 1, n, 1, id[a[i]]-1) + 1;
        update(1, 1, n, id[a[i]], len);
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("lis.inp", "r") ){
        freopen("lis.inp", "r", stdin);
        freopen("lis.out", "w", stdout);
    }

    init();
    solve();

    return 0;
}
