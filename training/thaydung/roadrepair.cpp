#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e4 + 5;

int n, m;
ll c1, c2;
struct edges{
    int u, v;
    ll d, w;
} edg[N];
int par[N], sz[N];

int Find(int u){
    if ( u == par[u] ) return u;
    else return par[u] = Find(par[u]);
}

bool Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( sz[u] < sz[v] ) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m >> c1 >> c2;

    for (int i = 1; i <= m; i ++)
        cin >> edg[i].u >> edg[i].v >> edg[i].d >> edg[i].w;

    sort(edg + 1, edg + 1 + m, [&](edges a, edges b){
        return a.d < b.d;
    });

//    for (int i = 1; i <= m; i ++)
//        cout << edg[i].u << ' ' << edg[i].v << ' ' << edg[i].d << ' ' << edg[i].w << '\n';

    vector<edges> mst;
    ll ans = LLONG_MAX;
    for (int i = 1; i <= m; i ++){
        for (int j = 0; j < mst.size(); j ++)
            if ( mst[j].w > edg[i].w ){
                mst.insert(mst.begin() + j, edg[i]);
                break;
            }

        if ( !mst.size() ) mst.pb(edg[i]);
        else if ( mst.back().w <= edg[i].w ) mst.pb(edg[i]);

        ll mxd = 0, mxw = 0;
        int del = -1;
        for (int j = 1; j <= n; j ++) par[j] = j, sz[j] = 1;

        for (int j = 0; j < mst.size(); j ++)
            if ( !Join(mst[j].u, mst[j].v) ) del = j;
            else{
                mxd = max(mxd, mst[j].d);
                mxw = max(mxw, mst[j].w);
            }

        if ( sz[Find(1)] == n ) ans = min(ans, mxd * c1 + mxw * c2);

        if ( del != -1 ) mst.erase(mst.begin() + del);
    }

    cout << ( ans == LLONG_MAX ? -1 : ans );

    return 0;
}
