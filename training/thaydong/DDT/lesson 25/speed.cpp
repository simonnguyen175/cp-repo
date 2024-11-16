#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9;

int n, m;
struct edges{
    int u, v, w;
} edg[N];
int Par[N], Rank[N];
queue<int> q;

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
        Par[v] = u;
    }
}

bool check(int l, int r){
    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 1;
    for (int i = l; i <= r; i ++){
        int u = edg[i].u, v = edg[i].v;
        Join(u, v);
    }
    for (int i = 2; i <= n; i ++)
        if ( Find(i) != Find(i-1) ) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edg[i] = {u, v, w};
    }
    sort(edg + 1, edg + 1 + m, [&](edges a, edges b){
        return a.w < b.w;
    });

    int mn, mx, ans = oo, j = 1;
    for (int i = 1; i <= m; i ++){
        while ( !check(i, j) && j <= m ) j ++;
        if ( j == m + 1 ) break;
        if ( edg[j].w - edg[i].w < ans )
            mn = edg[i].w, mx = edg[j].w, ans = mx - mn;
    }

    cout << mn << ' ' << mx;

    return 0;
}
