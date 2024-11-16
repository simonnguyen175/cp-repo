#include<bits/stdc++.h>
#define simon "trans"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m;
ll k;
vector<int> adj[N];
int d[N];

void bfs(){
    queue<int> Q; Q.push(1);
    d[1] = 0;
    while ( Q.size() ){
        int u = Q.front(); Q.pop();
        for (int v : adj[u])
            if ( !d[v] && v != 1 ) d[v] = d[u] + 1, Q.push(v);
    }
}

bool check(ll t){
    ll cnt = 0;
    for (int i = 2; i <= n; i ++)
        cnt += t / d[i];
    if ( cnt >= k ) return true;
    return false;
}

void solve(){
    ll lo = 1, hi = k, mid, res;
    while ( lo <= hi ){
        ll mid = lo + hi >> 1;
        if ( check(mid) ){
            res = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << res;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i ++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    bfs();

    solve();

    return 0;
}
