#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 3e6 + 5;

int n;
int a[N], lpf[N], d[N], pre[N], t[N];
vector<int> adj[N];
vector<int> c[2], gro1;
bool bip;

void sieve(){
    for (int i = 2; i * i < N; i ++) if ( !lpf[i] )
    for (int j = i * i; j < N; j += i) if ( !lpf[j] )
        lpf[j] = i;
    for (int i = 2; i < N; i ++) if ( !lpf[i] )
        lpf[i] = i;
}

void dfs(int u){
    if ( !bip ) return;
    c[t[u]].pb(u);
    for (int v : adj[u]){
        if ( t[v] == t[u] ) { bip = 0; return; }
        if ( t[v] == -1 ){
            t[v] = t[u] ^ 1;
            dfs(v);
        }
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i ++) adj[i].clear();
    for (int i = 1; i < N; i ++) d[i] = 0, pre[i] = 0;
    for (int i = 1, s; i <= n; i ++){
        cin >> s;
        a[i] = s;
        while ( lpf[s] ){
            int x = lpf[s];
            d[x] ++;
            if ( d[x] > 2 ) { cout << -1 << '\n'; return; }
            if ( d[x] == 2 ) adj[pre[x]].pb(i), adj[i].pb(pre[x]);
            pre[x] = i;
            while ( s % x == 0 ) s /= x;
        }
    }

    bip = 1;
    gro1.clear();
    int mn0 = 0;
    for (int i = 1; i <= n; i ++) t[i] = -1;
    for (int i = 1; i <= n; i ++) if ( t[i] == -1 ){
        c[0].clear(); c[1].clear();

        t[i] = 0;
        dfs(i);

        if ( !bip ) { cout << -1 << '\n'; return; }

        sort(c[0].begin(), c[0].end());
        sort(c[1].begin(), c[1].end());

        if ( c[0].size() == c[1].size() ){
            if ( c[0][0] > c[1][0] ) swap(c[0], c[1]);
            for (int x : c[0]) gro1.pb(x);
        }
        else{
            if ( c[0].size() < c[1].size() ) swap(c[0], c[1]);
            for (int x : c[0]) gro1.pb(x);
        }
    }

    sort(gro1.begin(), gro1.end());
    cout << gro1.size() << ' ';
    for (int x : gro1) cout << x << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    sieve();
    int test;
    cin >> test;
    while ( test -- )
        solve();

    return 0;
}
