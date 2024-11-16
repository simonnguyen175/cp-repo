#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, m, c;
pi a[N];
int st[N], lazy[N];
vector<int> cont;

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

void down(int id){
    for (int i = 0; i <= 1; i ++){
        st[id*2+i] += lazy[id];
        lazy[id*2+i] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
        st[id] ++;
        lazy[id] ++;
        return;
    }
    down(id);
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    down(id);
    int mid = l + r >> 1;
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> c >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i].fi >> a[i].se;
        a[i].se --;
        cont.pb(a[i].fi), cont.pb(a[i].se);
    }
    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());
    sort(a + 1, a + 1 + n, [&](pi x, pi y){
        if ( x.se == y.se ) return x.fi > y.fi;
        return x.se < y.se;
    });

    m = cont.size();
    int ans = 0;
    for (int i = 1; i <= n; i ++){
        int mxc = get(1, 1, m, id(a[i].fi), id(a[i].se));
        if ( mxc < c ){
//            cout << mxc << ' ' << a[i].fi << ' ' << a[i].se << '\n';
            update(1, 1, m, id(a[i].fi), id(a[i].se)), ans ++;
        }
    }

    cout << ans;

    return 0;
}
