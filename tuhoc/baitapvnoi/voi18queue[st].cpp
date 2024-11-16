#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int t, n, m, pos;
int a[N], b[N], st[4*N];
vector<pi> cont;

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ) { st[id] = 1; return; }
    int mid = l + r >> 1;
    update(id*2, l, mid, u);
    update(id*2+1, mid+1, r, u);
    st[id] = st[id*2] + st[id*2+1];
}

void go(int id, int l, int r, int u, int v){
    if ( pos ) return;
    if ( l > v || r < u ) return;
    if ( l == r ){
        if ( !st[id] ) pos = l;
        return;
    }

    if ( u <= l && r <= v ){
        int mid = l + r >> 1;
        if ( st[id*2] < ( mid - l + 1 ) ) go(id*2, l, mid, u, v);
        else go(id*2+1, mid + 1, r, u, v);
        return;
    }

    int mid = l + r >> 1;

    go(id*2, l, mid, u, v);
    go(id*2+1, mid+1, r, u, v);
}

bool check(int x){
//    cout << "check " << x << " : \n";

    cont.clear();
    for (int i = 1; i <= x; i ++) cont.pb({b[i], a[i]});
    sort(cont.begin(), cont.end());


    for (int i = 1; i <= 4*m; i ++) st[i] = 0;

    for (auto it : cont){
        int u = it.se, v = it.fi;
        pos = 0;
        go(1, 1, m, u, v);
//        cout << pos << '\n';
        if ( !pos ) return false;
        update(1, 1, m, pos);
    }

    return true;
}

void solve(){
    cin >> m >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
    }

    int lo = 1, hi = n, res = 0;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voi18queue.inp", "r") ){
        freopen("voi18queue.inp", "r", stdin);
        freopen("voi18queue.out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
