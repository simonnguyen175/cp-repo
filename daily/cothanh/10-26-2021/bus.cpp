#include<bits/stdc++.h>
#define simon "bus"
#define FASTio ios_base::sync_with_stdio(0);cout.tie(0);cout.tie(0);
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 5;

int n, m, q;
struct route{
    int u, v, s, f;
    bool operator < (const route& a) const{
        return f < a.f;
    }
} routes[N];
vector<pi> fin[N];

int get(int u, int l){
    int lo = 0, hi = fin[u].size() - 1, res = -1;
    while ( lo <= hi ){
        int mid = ( lo + hi ) / 2;
        if ( fin[u][mid].se <= l ){
            res = fin[u][mid].fi;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r" ) ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, s, f;
        cin >> u >> v >> s >> f;
        routes[i] = {u, v, s, f};
    }

    sort(routes + 1, routes + 1 + m);


    for (int i = 1; i <= m; i ++){
        int u, v, s, f;
        u = routes[i].u, v = routes[i].v;
        s = routes[i].s, f = routes[i].f;

        if ( u == 1 ){
            if ( !fin[v].size() )
                fin[v].pb({s, f});
            else fin[v].pb({max(s, fin[v][fin[v].size()-1].fi), f});
            continue;
        }

        int tmp = get(u, s);
        if ( tmp != -1 ){
            if ( !fin[v].size() )
                fin[v].pb({tmp, f});
            else fin[v].pb({max(tmp, fin[v][fin[v].size()-1].fi), f});
        }
    }

    cin >> q;
    while ( q -- ){
        int l; cin >> l;
        cout << get(n, l) << '\n';
    }

    return 0;
}
