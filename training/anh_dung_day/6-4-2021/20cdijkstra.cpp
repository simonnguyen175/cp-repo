#include<bits/stdc++.h>
#define ll long long
#define ii pair<ll, int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;
const ll oo = 1e12;

int n, m;
vector<ii> adj[N];
ll d[N];

void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 1; i <= n; i ++)
        d[i] = oo;
    d[1] = 0;
    pq.push({0, 1});

    while ( !pq.empty() ){
        int u = pq.top().se;
        ll du = pq.top().fi;
        pq.pop();

        if ( du != d[u] ) continue;

        for (auto x : adj[u]){
            int v = x.se;
            ll uv = x.fi;

            if ( d[v] > du + uv ){
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    if ( fopen("20cdijkstra.inp", "r" ) ){
        freopen("20cdijkstra.inp", "r", stdin);
        freopen("20cdijkstra.out", "w", stdout);
    }
    ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dijkstra();

    if ( d[n] == oo ) cout << -1;
    else{
        vector<int> ans;
        queue<int> q;
        ans.push_back(n);
        q.push(n);

        while ( !q.empty() ){
            int u = q.front();
            q.pop();

            bool check = 0;
            for (auto x : adj[u] ){
                if ( check ) break;
                int v = x.se;
                ll uv = x.fi;
                if ( d[v] + uv == d[u] ){
                    ans.push_back(v);
                    q.push(v);
                    check = 1;
                }
            }
        }

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i ++)
            cout << ans[i] << ' ';

    }

    return 0;
}
