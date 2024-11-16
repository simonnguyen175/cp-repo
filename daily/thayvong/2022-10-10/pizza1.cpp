#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int oo = 2e9;

int n, m;
int s[N], p[N], c[N], x[N], w[N];
vector<int> cont;
pi st[4*N];

void build(int id, int l, int r){
    if ( l == r ){
        if ( w[l] == oo ) st[id] = {oo, oo};
        else st[id] = {w[l]-x[l], w[l]+x[l]};
        return;
    }
    int mid = l + r >> 1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    st[id].fi = min(st[id*2].fi, st[id*2+1].fi);
    st[id].se = min(st[id*2].se, st[id*2+1].se);
}

int get(int t, int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return oo;
    if ( u <= l && r <= v ) return ( t ? st[id].se : st[id].fi );
    int mid = l + r >> 1;
    return min(get(t, id*2, l, mid, u, v), get(t, id*2+1, mid+1, r, u, v));
}

int id(int x){
    return upper_bound(cont.begin(), cont.end(), x) - cont.begin();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("pizza1.inp", "r") ){
        freopen("pizza1.inp", "r", stdin);
        freopen("pizza1.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> s[i] >> p[i];
        cont.pb(s[i]);
    }

    for (int i = 1; i <= m; i ++){
        cin >> c[i];
        cont.pb(c[i]);
    }

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 1; i <= cont.size(); i ++) w[i] = oo;
    for (int i = 1; i <= n; i ++)
        w[id(s[i])] = p[i], x[id(s[i])] = s[i];

    n = cont.size();
    build(1, 1, n);

    for (int i = 1; i <= m; i ++){
        cout << min(c[i] + get(0, 1, 1, n, 1, id(c[i])),
                    get(1, 1, 1, n, id(c[i]), n) - c[i]) << ' ';
    }

    return 0;
}
