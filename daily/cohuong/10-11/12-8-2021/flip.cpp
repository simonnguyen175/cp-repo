#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 3e6 + 5;

int n, m;
int a[N], b[N], p[N], cnt[N];
pi c[N], q[N];
int st[N], bit[N];
vector<int> cont;
map<int, int> id;

void update(int id, int l, int r, int u, int v){
    if ( l > u || r < u ) return;
    if ( l == r ){ st[id] = v; return; }
    int mid = l + r >> 1;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    st[id] = max(st[id*2], st[id*2+1]);
}

int get(int id, int l, int r, int u, int v){
    if ( l > v || r < u ) return 0;
    if ( u <= l && r <= v ) return st[id];
    int mid = l + r >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void updbit(int u){
    for (; u >= 1; u -= u&(-u)) bit[u] ++;
}

int getbit(int u){
    int res = 0;
    for (; u <= m; u += u&(-u)) res += bit[u];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("flip.inp", "r") ){
        freopen("flip.inp", "r", stdin);
        freopen("flip.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
        cont.pb(a[i]), cont.pb(b[i]);
        q[i] = {max(a[i], b[i]), i};
    }

    for (int i = 1; i <= m; i ++)
        cin >> c[i].fi, c[i].se = i, cont.pb(c[i].fi);

    sort(cont.begin(), cont.end());
    cont.erase(unique(cont.begin(), cont.end()), cont.end());

    for (int i = 0; i < cont.size(); i ++) id[cont[i]] = i + 1;
    int sl = cont.size();
    for (int i = 1; i <= m; i ++){
        update(1, 1, sl, id[c[i].fi], i);
    }

    for (int i = 1; i <= n; i ++){
        int u = min(a[i], b[i]), v = max(a[i], b[i]);
        p[i] = get(1, 1, sl, id[u], id[v]-1) + 1;
    }

    sort(c + 1, c + 1 + m);
    sort(q + 1, q + 1 + n);

    int j = m;
    for (int i = n; i >= 1; i --){
        while ( c[j].fi >= q[i].fi && j >= 1 )
            updbit(c[j].se), j --;
        cnt[q[i].se] = getbit(p[q[i].se]);
    }

    for (int i = 1; i <= n; i ++){
        if ( p[i] - 1 > 0 && a[i] < b[i] ) swap(a[i], b[i]);
        if ( cnt[i] % 2 ) swap(a[i], b[i]);
        cout << a[i] << ' ';
    }

    return 0;
}
