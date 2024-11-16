#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e4 + 5;
const ll MOD = 1e9 + 7;
const ll base = 31;

int n, flag, cur;
string s;
vector<int> adj[N];
int a[N], sz[N], node[N], used[N];
ll hd[N], hu[N], pw[N];
unordered_map<ll, int> mp;

int dfs(int u, int pu){
    sz[u] = 1;
    for (int v : adj[u]) if ( v != pu && !used[v] )
        sz[u] += dfs(v, u);
    return sz[u];
}

int centroid(int u, int pu, int n){
    for (int v : adj[u]) if ( v != pu && !used[v] )
        if ( sz[v] > n/2 ) return centroid(v, u, n);
    return u;
}

void makeH(int u, int pu, int h){
    for (int v : adj[u]) if ( v != pu && !used[v] ){
        hd[v] = ( hd[u] * base + a[v] ) % MOD;
        hu[v] = ( a[v] * pw[h+1] + hu[u] ) % MOD;
//        cout << v << ' ' << hd[v] << ' ' << hu[v] << '\n';
        makeH(v, u, h+1);
    }
}

void go(int u, int pu, int len){
    if ( flag ) return;
    node[cur++] = u;
    if ( cur == len && hd[u] == hu[u] ) flag = 1;

    int x = len - cur + 1;
    int id = cur - x;

    if ( id >= 0 && id < cur && cur >= x ){
        int v = node[id];
//        cout << u << ' ' << v << ' ' << id << ' ' << x << '\n';
        if ( hu[v] == hd[v] ){
            ll tmp = ( hd[u] - ( !id ? 0 : hd[node[id-1]] ) * pw[x] + MOD*MOD) % MOD;
            if ( mp.find(tmp) != mp.end() ) flag = 1;
        }
    }

    for (int v : adj[u]) if ( v != pu && !used[v] )
        go(v, u, len);

    cur --;
}

void add(int u, int pu, int delta){
    if ( !(mp[hd[u]] += delta) ) mp.erase(hd[u]);
    for (int v : adj[u]) if ( v != pu && !used[v] )
        add(v, u, delta);
}

void build(int u, int pu, int len){
    if ( flag ) return;
    int n = dfs(u, pu);
    int c = centroid(u, pu, n);
    used[c] = 1;
    mp.clear();

//    cout << c << " : \n";
    hu[c] = a[c], hd[c] = a[c];
    makeH(c, pu, 0);
    for (int v : adj[c]) if ( !used[v] && v != pu )
        add(v, c, 1);

    cur = 1; node[0] = c;
    for (int v : adj[c]) if ( !used[v] && v != pu ){
        add(v, c, -1);

        cur = 1;
        go(v, c, len);
        if ( flag ) return;

        add(v, c, 1);
    }

    for (int v : adj[c]) if ( !used[v] && v != pu )
        build(v, c, len);
}

bool check(int len){
    flag = 0;
    for (int i = 1; i <= n; i ++) used[i] = 0;
    mp.clear();
    build(1, 0, len);
    return flag;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i ++) a[i] = s[i] - 'a' + 1;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    pw[0] = 1;
    for (int i = 1; i <= n; i ++)
        pw[i] = pw[i-1] * base % MOD;

//    cout << check(35) << '\n';

    // odd length
    int lo = 1, hi = n/2, res = 1;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(2*mid+1) ) res = max(res, 2*mid+1), lo = mid + 1;
        else hi = mid - 1;
    }

    // even length
    lo = 1, hi = n/2;
    while ( lo <= hi ){
        int mid = lo + hi >> 1;
        if ( check(2*mid) ) res = max(res, 2*mid), lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res << '\n';

    return 0;
}
