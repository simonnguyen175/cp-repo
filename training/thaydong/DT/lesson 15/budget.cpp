#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define ll long long
using namespace std;
const int N = 1e2 + 5;

int n, m, p, tt;
int s[N], r[N], t[N];
vector<pi> adj[N];
int vis[N], match[N][N];

bool visit(int i){
    if ( vis[i] != tt ) vis[i] = tt;
    else return false;

    for (auto it : adj[i])
        if ( !match[it.fi][it.se] || visit(match[it.fi][it.se]) ){
            match[it.fi][it.se] = i;
            return true;
        }

    return false;
}

bool check(ll x){
    for (int i = 1; i <= n; i ++) adj[i].clear();

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++){
        for (int k = 1; k <= n; k ++)
            if ( r[k] + 1ll * j * t[i] - 1 <= x ){
                adj[k].pb({i, j});
            }
    }

    for (int i = 1; i <= m; i ++)
    for (int j = 1; j <= n; j ++)
        match[i][j] = 0;

    int cnt = 0;
    for (int i = 1; i <= n; i ++){
        tt ++;
        if ( visit(i) ) cnt ++;
    }

    if ( cnt == n ) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> m >> n >> p;
    for (int i = 1; i <= m; i ++){
        cin >> s[i];
        if ( p % s[i] ) t[i] = p / s[i] + 1;
        else t[i] = p / s[i];
    }

    for (int i = 1; i <= n; i ++)
        cin >> r[i];

//    cout << check(93750000000) << '\n';

    ll lo = 1, hi = 1e12, res = -1;
    while ( lo <= hi ){
        ll mid = (lo + hi) / 2;
        if ( check(mid) ) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    cout << res;

    return 0;
}
