#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 524288 + 5;

int sub, test, n;
int deg[4*N], idx[N], leaf[4*N], ans[N];
vector<int> g[4*N];
queue<int> q;

void build(int id, int l, int r){
    if ( l == r ){
        idx[l] = id;
        leaf[id] = l;
        return;
    }
    int mid = l + r >> 1;
    g[id*2].pb(id);
    g[id*2+1].pb(id);
    deg[id] += 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
}

void addE(int id, int l, int r, int u, int v, int x){
    if ( u > v ) return;
    if ( l > v || r < u ) return;
    if ( u <= l && r <= v ){
//        cout << "addE " << id << ' ' << l << ".." << r << " -> " << x << '\n';
        g[id].pb(x);
        deg[x] ++;
        return;
    }
    int mid = l + r >> 1;
    addE(id*2, l, mid, u, v, x);
    addE(id*2+1, mid+1, r, u, v, x);
}

void solve(){
    cin >> n;

    for (int i = 1; i <= 4*n; i ++)
        g[i].clear(), deg[i] = 0, leaf[i] = 0;

    build(1, 1, n);

//    for (int i = 1; i <= n; i ++)
//        cout << idx[i] << ' ';
//    cout << '\n';

    bool ck = 1;
    for (int i = 1, x; i <= n; i ++){
        cin >> x;

        if ( x == -1 ) continue;

        if ( x < i ) ck = 0;

        if ( x == n + 1 ){
            addE(1, 1, n, i+1, n, idx[i]);
        }
        else{
            addE(1, 1, n, i+1, x-1, idx[i]);
//            cout << "addE " << idx[i] << " -> " << idx[x] << '\n';
            g[idx[i]].pb(idx[x]);
            deg[idx[x]] ++;
        }
    }

    if ( !ck ) { cout << "No\n"; return; }

    for (int i = 1; i <= 4 * n; i ++)
        if ( !deg[i] ) q.push(i);

//    cout << q.size() << '\n';
//    for (int i = 1; i <= 4 * n; i ++)
//        cout << leaf[i] << ' ';
//    cout << '\n';

    int cur = 0, cnt = 0;
    while ( q.size() ){
        int u = q.front();
        q.pop();
        cnt ++;
        if ( leaf[u] ) ans[leaf[u]] = ++cur;

        for (int v : g[u]){
            deg[v] --;
            if ( !deg[v] ) q.push(v);
        }
    }

    if ( cnt < 4 * n ){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        for (int i = 1; i <= n; i ++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("recover.inp", "r", stdin);
    freopen("recover.out", "w", stdout);

    cin >> sub >> test;
    while ( test -- )
        solve();

    return 0;
}
