#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, q;
int type[N], x[N], y[N];
int Par[N], Rank[N];
vector<pi> Q[4*N];
struct roll{
    int u, v, rnk;
};
vector<roll> Rb[4*N];
map<pi, vector<int>> pos;
map<pi, int> d;
string ans = "";

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Find(Par[u]);
}

void Join(int u, int v, int id){
    u = Find(u); v = Find(v);
    if ( u == v ) return;

    if ( Rank[v] > Rank[u] ) swap(u, v);
    Par[v] = u;
    Rb[id].push_back({u, v, Rank[u]});
    if ( Rank[u] == Rank[v] ) Rank[u] ++;
}

void update(int id, int l, int r, int u, int v, pi val){
    if ( l > v || r < u ) return;
    if ( l >= u && r <= v ){
        Q[id].pb(val); return;
    }
    int mid = l + r >> 1;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
}

void dfs(int id, int l, int r){
    for (auto it : Q[id]) Join(it.fi, it.se, id);
    if ( l < r ){
        int mid = l + r >> 1;
        dfs(id*2, l, mid);
        dfs(id*2+1, mid+1, r);
    }
    else if ( type[l] == 3 ){
        if ( Find(x[l]) == Find(y[l]) ) ans += "1";
        else ans += "0";
    }

    for (auto it : Rb[id])
        Par[it.v] = it.v, Rank[it.u] = it.rnk;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("voscomps.inp", "r") ){
        freopen("voscomps.inp", "r", stdin);
        freopen("voscomps.out", "w", stdout);
    }

    cin >> n >> q;

    for (int i = 1; i <= q; i ++){
        cin >> type[i] >> x[i] >> y[i];

        if ( x[i] > y[i] ) swap(x[i], y[i]);

        if ( type[i] == 1 ) pos[{x[i], y[i]}].pb(i);

        if ( type[i] == 2 ){
            if ( pos[{x[i], y[i]}].empty() ) continue;
            update(1, 1, q, pos[{x[i], y[i]}].back(), i-1, {x[i], y[i]});
            pos[{x[i], y[i]}].pop_back();
        }
    }

    for (int i = 1; i <= q; i ++) if ( type[i] == 1 && !d[{x[i], y[i]}] ){
        d[{x[i], y[i]}] = 1;
        if ( pos[{x[i], y[i]}].size() )
            update(1, 1, q, pos[{x[i], y[i]}][0], q, {x[i], y[i]});
    }

    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;

    dfs(1, 1, q);

    cout << ans;

    return 0;
}
