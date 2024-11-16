#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

struct job {
    ll w, t;
    bool operator < (const job&a) const{
        return w * a.t > a.w * t;
    }
};

int n, id[N];
ll ans = 0;
job a[N];
vector<int> adj[N];
multiset<job> s[N];

void dfs(int u ){
    id[u] = u;

    for ( auto v : adj[u] ){
        dfs(v);
        if ( s[id[v]].size() > s[id[u]].size() )
            id[u] = id[v];
    }

    for ( auto v : adj[u] ){
        if ( id[v] == id[u] ) continue;
        for (auto it : s[id[v]])
            s[id[u]].insert(it);
    }

    job Top;
    Top.w = a[u].w, Top.t = a[u].t;

    while ( s[id[u]].size() ){
        job it = *s[id[u]].begin();
        if ( Top.w * it.t >= it.w * Top.t ) break;

        s[id[u]].erase(s[id[u]].begin());

        ans += it.w * Top.t;
        Top.t += it.t; Top.w += it.w;
    }

    s[id[u]].insert(Top);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x ;
        if ( i == 0 ) continue;
        adj[x].pb(i);
    }

    for(int i = 0; i < n; i ++) cin >> a[i].w;
    for(int i = 0; i < n; i ++) cin >> a[i].t;
    for(int i = 0; i < n; i ++) ans += a[i].w * a[i].t;

    dfs(0);

    ll time = 0;
    for(auto it : s[id[0]]) {
        ans += time * it.w;
        time += it.t;
    }

    cout << ans;

    return 0;
}
