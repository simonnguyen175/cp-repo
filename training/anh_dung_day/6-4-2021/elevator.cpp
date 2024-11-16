#include<bits/stdc++.h>
#define simon "elevator"
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 15;
const ll oo = 1e16;

struct opt{
    ll d;
    int u, tt;
};

bool operator > (const opt& a, const opt& b){
    return a.d > b.d;
}

opt makeopt(ll d, int u, int tt){
    opt res; res.d = d; res.u = u; res.tt = tt;
    return res;
}

int t1, w1, t2, w2, s, f1, f2;
vector<ii> adj[N];
ll mindist[N][3];

void solve(){
    priority_queue<opt, vector<opt>, greater<opt>> heap;

    int n = 100010;
    for (int i = 1 ; i <= n + 10; i ++)
        for (int j = 0; j <= 2; j ++)
            mindist[i][j] = oo;

    mindist[f1][0] = mindist[f1][1] = mindist[f1][2] = 0;
    heap.push(makeopt(0, f1, 0));


    while ( !heap.empty() ){
        int u = heap.top().u;
        ll du = heap.top().d;
        int tt = heap.top().tt;
        heap.pop();

        for (auto tmp : adj[u]){
            int v = tmp.fi;
            int uv = tmp.se;

            // th canh noi la thang loai 1
            if ( uv == t1 ){
                if ( tt == 1 && mindist[v][1] > du + t1 ){
                    mindist[v][1] = du + t1;
                    heap.push(makeopt(mindist[v][1], v, 1));
                }
                if ( tt != 1 && mindist[v][1] > du + t1 + w1 ){
                    mindist[v][1] = du + t1 + w1;
                    heap.push(makeopt(mindist[v][1], v, 1));
                }
            }


            // th canh noi la thang loai 2
            if ( uv == t2 ){
                if ( tt == 2 && mindist[v][2] > du + t2 ){
                    mindist[v][2] = du + t2;
                    heap.push(makeopt(mindist[v][2], v, 2));
                }
                if ( tt != 2 && mindist[v][2] > du + t2 + w2 ){
                    mindist[v][2] = du + t2 + w2;
                    heap.push(makeopt(mindist[v][2], v, 2));
                }
            }

            // th canh noi la di  bo
            if ( uv == s )
                if ( mindist[v][0] > du + s ){
                    mindist[v][0] = du + s;
                    heap.push(makeopt(mindist[v][0], v, 0));
                }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> t1 >> w1 >> t2 >> w2 >> s >> f1 >> f2;

    for (int i = 1; i <= 100010; i ++){
        if ( i % 10 == 0 ){
            adj[i].push_back({i + 10, t2});
            adj[i + 10].push_back({i, t2});
        }
        adj[i].push_back({i + 1, t1}); adj[i].push_back({i + 1, s});
        adj[i + 1].push_back({i, t1}); adj[i + 1].push_back({i, s});
    }

    solve();

    cout << min({mindist[f2][1], mindist[f2][0], mindist[f2][2]});

    return 0;
}
