#include<bits/stdc++.h>
#define simon "heist"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 5;

int t, n, k, m;
struct gem{
    int x, y, c;
} a[N];
map<int, int> idx, idy;
vector<pi> rows[N];
set<int> color[N];
vector<int> contx, conty;
int st[4*N];

void update(int id, int l, int r, int u){
    if ( l > u || r < u ) return;
    if ( l == r ) { st[id] ++; return; }
    int mid = l + r >> 1;
    update(id * 2, l, mid, u);
    update(id * 2 + 1, mid + 1, r, u);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve(){
    cin >> n >> k;
    contx.clear(); conty.clear();
    for (int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y >> a[i].c;
        contx.pb(a[i].x); conty.pb(a[i].y);
    }

    sort(contx.begin(), contx.end());
    contx.erase(unique(contx.begin(), contx.end()), contx.end());
    sort(conty.begin(), conty.end());
    conty.erase(unique(conty.begin(), conty.end()), conty.end());

    for (int i = 0; i < contx.size(); i ++) idx[contx[i]] = i + 1;
    for (int i = 0; i < conty.size(); i ++) idy[conty[i]] = i + 1, rows[i+1].clear();

    for (int i = 1; i <= n; i ++)
        rows[idy[a[i].y]].pb({idx[a[i].x], a[i].c});

//    for (int i = 1; i <= conty.size(); i ++){
//        cout << "row " << i << " : \n";
//        for (auto it : rows[i]) cout << '(' << it.fi << ',' << it.se << ')';
//        cout << '\n';
//    }

    m = contx.size();
    for (int i = 1; i <= k; i ++)
        color[i].clear(), color[i].insert(0), color[i].insert(m + 1);

    int ans = 0;
    for (int i = 1; i <= 4 * m; i ++) st[i] = 0;

    for (int i = 1; i <= conty.size(); i ++){
//        cout << "row " << i << " : \n";
        for (auto it : rows[i]){
            if ( color[it.se].find(it.fi) != color[it.se].end() ) continue;
            auto l = color[it.se].lower_bound(it.fi); l --;
            auto r = color[it.se].upper_bound(it.fi);
//            cout << it.fi << ' ' << it.se << " : " << *l << ' ' << *r << ' ' << get(1, 1, m, *l + 1, *r - 1) << '\n';
            ans = max(ans, get(1, 1, m, *l + 1, *r - 1));
        }
        for (auto it : rows[i])
            update(1, 1, m, it.fi), color[it.se].insert(it.fi);
    }

    int pre;
    for (int i = 1; i <= k; i ++){
        //cout << "color " << i << " : \n";
        for (auto it = color[i].begin(); it != color[i].end(); it ++){
            if ( it == color[i].end() ) break;
            //cout << *it << ' ';
            if ( it == color[i].begin() ) { pre = *it; continue; }
            ans = max(ans, get(1, 1, m, pre + 1, *it - 1));
            pre = *it;
        }
        //cout << '\n';
    }

    cout << ans << '\n';
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> t;
    while ( t -- )
        solve();
    return 0;
}
