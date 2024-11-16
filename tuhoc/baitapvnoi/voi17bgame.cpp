#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m;
struct edge{
    int w, u, v;
    bool operator < (const edge &a) const{
        return w < a.w;
    }
    bool operator <= (const edge &a) const{
        return w <= a.w;
    }
    bool operator >= (const edge &a) const{
        return w >= a.w;
    }
    bool operator > (const edge &a) const{
        return w > a.w;
    }
};
vector<edge> edges;
int Par[N], Rank[N];

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);
        Par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
    }
}

bool check(int x){
    for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;

    edge tmp = {(x+1)/2, 0, 0};
    auto it = lower_bound(edges.begin(), edges.end(), tmp);

    int l = it - edges.begin() - 1;
    int r = l + 1;

    while ( r < edges.size() ){
        edge cur = edges[r];
        while ( l >= 0 ){
            tmp = edges[l];
            if ( tmp.w + cur.w < x ) break;
            Join(tmp.u, tmp.v);
            l --;
        }

        if ( Find(cur.u) == Find(cur.v) ) return true;

        Join(cur.u, cur.v);

        r ++;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({w, u, v});
    }

    sort(edges.begin(), edges.end());

    int lo = 0, hi = 2e9, res;
    while ( lo <= hi ){
        int mid = lo + ( hi - lo ) / 2;
        if ( check(mid) ) res = mid, lo = mid + 1;
        else hi = mid - 1;
    }

    cout << res;

    return 0;
}
