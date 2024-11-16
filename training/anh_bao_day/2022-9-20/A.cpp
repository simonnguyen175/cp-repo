#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n, k;
vector<pi> adj[N];
pi range[N];
int s[N];

void dfs(int u, int pu){
    int l = range[u].fi, r = range[u].se;
    if ( l > r ) return;

    int v, w, pv = 0, pw = 0, mw;
    for (auto it : adj[u]) if ( it.se != pu ){
        if ( l > r ) break;
        v = it.se, w = it.fi;

        if ( !pv ){
            range[v] = {l, r};
            pv = v, pw = w;
            continue;
        }

        mw = w + pw >> 1;
        int lo = l, hi = r, pos = -1;
        while ( lo <= hi ){
            int mid = lo + hi >> 1;
            if ( s[mid] <= mw ) pos = mid, lo = mid + 1;
            else hi = mid - 1;
        }

        if ( pos == -1 ){
            range[pv].se = l - 1;
            range[v] = {l, r};
        }
        else{
            range[pv].se = pos;
            range[v] = {pos+1, r};
            l = pos + 1;
        }
        pv = v, pw = w;
    }

//    cout << u << "->\n";
    for (auto it : adj[u]) if ( it.se != pu ){
        int v = it.se;
//        cout << v << ' ' << range[v].fi << ' ' << range[v].se << '\n';
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({w, v});
        adj[v].pb({w, u});
    }

    for (int i = 1; i <= k; i ++)
        cin >> s[i];

    for (int i = 1; i <= n; i ++)
        sort(adj[i].begin(), adj[i].end());
    sort(s + 1, s + 1 + k);
//    for (int i = 1; i <= k; i ++)
//        cout << s[i] << ' '; cout << '\n';

    range[1] = {1, k};
    dfs(1, 0);

    for (int i = 1; i < n; i ++){
        if ( !range[i].fi || range[i].fi > range[i].se ){
            cout << 0 << ' ';
            continue;
        }
        else cout << range[i].se - range[i].fi + 1 << ' ';
    }

    if ( !range[n].fi || range[n].fi > range[n].se ) cout << 0 << '\n';
    else cout << range[n].se - range[n].fi + 1 << '\n';

    return 0;
}
