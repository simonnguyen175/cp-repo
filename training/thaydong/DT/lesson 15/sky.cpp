#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e4 + 5;
const int K = 1;
const int oo = 1e9;

int n, m;
vector<pi> adj[N];
vector<int> jump[N];
int pos[N];
int d[N][100];
struct node{
    int u, lu;
    int du;

    bool operator > (const node &a) const{
        return du > a.du;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("trash.inp", "r") ){
        freopen("trash.inp", "r", stdin);
        freopen("trash.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 0; i < n; i ++)
    for (int j = 0; j <= K; j ++)
        d[i][j] = oo;

    priority_queue<node, vector<node>, greater<node>> heap;
    for (int i = 0; i < m; i ++){
        int b, p;
        cin >> b >> p;

        if ( p > K ){
            for (int j = b - p, k = 1; j >= 0; j -= p, k ++) adj[b].pb({j, k});
            for (int j = b + p, k = 1; j < n; j += p, k ++) adj[b].pb({j, k});
            if ( !i ) d[b][p] = 0, heap.push({b, p, 0});
        }
        else{
            if ( !i ) d[b][0] = 0, heap.push({b, 0, 0});
            jump[b].pb(p);
        }

        pos[i] = b;
    }

    while ( heap.size() ){
        int u = heap.top().u;
        int lu = heap.top().lu;
        ll du = heap.top().du;
        heap.pop();

        if ( du != d[u][lu] ) continue;

        if ( u == pos[1] ){
            cout << du;
            return 0;
        }

        // tai cho
        for (int x : jump[u]) if ( d[u][x] > du ){
            d[u][x] = du;
            heap.push({u, x, d[u][x]});
        }
        if ( d[u][0] > du ) d[u][0] = du, heap.push({u, 0, d[u][0]});

        // di chuyen
        if ( u + lu < n && d[u+lu][lu] > du + 1 ){
            d[u+lu][lu] = du + 1;
            heap.push({u+lu, lu, d[u+lu][lu]});
        }

        if ( u - lu >= 0 && d[u-lu][lu] > du + 1 ){
            d[u-lu][lu] = du + 1;
            heap.push({u-lu, lu, d[u-lu][lu]});
        }

        for (auto it : adj[u]){
            int v = it.fi, w = it.se;
            if ( d[v][0] > du + w ){
                d[v][0] = du + w;
                heap.push({v, 0, d[v][0]});
            }
        }
    }

    cout << -1;

    return 0;
}
