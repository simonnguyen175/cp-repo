#include<bits/stdc++.h>
#define simon "connect"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pi pair<int, ll>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, d;
int a[N];

namespace sub1{
    int Par[1005], Rank[1005];
    struct edge{
        int u, v; ll w;
        bool operator < (const edge& a){
            return w < a.w;
        }
    };
    vector<edge> edges;

    int Find(int u){
        if ( u == Par[u] ) return u;
        else return Par[u] = Find(Par[u]);
    }

    bool Join(int u, int v){
        u = Find(u); v = Find(v);
        if ( u != v ){
            if ( Rank[u] < Rank[v] ) swap(u, v);
            Par[v] = u;
            if ( Rank[u] == Rank[v] ) Rank[u] ++;
            return true;
        }
        else return false;
    }

    void solve(){
        for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            edges.pb({i, j, a[i] + a[j] + d * (j-i)});
        sort(edges.begin(), edges.end());

        for (int i = 1; i <= n; i ++) Par[i] = i, Rank[i] = 0;

        ll ans = 0;
        for (auto it : edges){
            int u = it.u, v = it.v;
            if ( Join(u, v) ) ans += it.w;
        }
        cout << ans;
    }
}

namespace sub2{
    void solve(){
        ll ans = 0;
        sort(a + 1, a + 1 + n);
        for (int i = 2; i <= n; i ++)
            ans += a[i] + a[1];
        cout << ans;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> d;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    if ( n <= 1000 ) sub1::solve();
    if ( d == 0 ) sub2::solve();
}
