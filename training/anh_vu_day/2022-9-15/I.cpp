#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e3 + 5;
const int oo = 1e9;

int n, m;
vector<pi> adj[N];
int d[N], len[N], inq[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int l, r, k, v;
        cin >> l >> r >> k >> v;
        r ++;
        if ( !v ) adj[r].pb({l, -k});
        else adj[l].pb({r, k-1});
    }

    for (int i = 0; i < n; i ++)
        adj[i].pb({i+1, 1});
    for (int i = 1; i <= n; i ++)
        adj[i].pb({i-1, 0});

//    for (int i = 0; i <= n; i ++){
//        cout << i << " : \n";
//        for (auto it : adj[i]) cout << "(" << it.fi << "," << it.se << ") ";
//        cout << '\n';
//    }

    for (int i = 1; i <= n; i ++) d[i] = oo;
    queue<int> q;
    q.push(0);
    d[0] = len[0] = 0;
    inq[0] = 1;
    while ( q.size() ){
        int u = q.front();
        q.pop();
        inq[u] = 0;

//        cout << u << ' ' << d[u] << ' ' << len[u] << '\n';

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[u] + w < d[v] ){
//                cout << "-> " << v << ' ' << w << '\n';
                len[v] = len[u] + 1;
                if ( len[v] == n + 1 ){
                    cout << -1; return 0;
                }
                d[v] = d[u] + w;
                if ( !inq[v] ){
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }

//    for (int i = 1; i <= n; i ++) cout << d[i] << '\n';

    for (int i = 1; i <= n; i ++)
        cout << !(d[i] - d[i-1]) << ' ';

    return 0;
}
