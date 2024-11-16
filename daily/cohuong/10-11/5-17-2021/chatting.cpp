#include<bits/stdc++.h>
#define simon "chatting"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ii pair<ll, ll>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

ll n, s, f, ans;
ll p[N], d[N];
vector<ii> adj[N];
bool cff[N], cfn[N];

void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < n; i ++) d[i] = LLONG_MAX;
    d[0] = 0;
    pq.push({0, 0});

    while ( !pq.empty() ){
        int u = pq.top().se;
        ll du = pq.top().fi;
        pq.pop();

        for (auto x : adj[u]){
            int v = x.fi;
            ll uv = x.se;


            if ( d[v] > du + uv ){
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

void update(int fp, bool c){
    if ( c == 1 ){
        queue<int> q;
        q.push(fp);

        while ( !q.empty() ){
            int u = q.front();
            q.pop();
            if ( u == 0 ) continue;

            for (auto x : adj[u]){
                int v = x.fi;
                int uv = x.se;
                if ( d[v] + uv == d[u] ){
                    cff[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    else{
        queue<int> q;
        q.push(fp);

        while ( !q.empty() ){
            int u = q.front();
            q.pop();
            if ( u == 0 ) continue;

            for (auto x : adj[u]){
                int v = x.fi;
                int uv = x.se;
                if ( d[v] + uv == d[u] ){
                    cfn[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

void solve(){
    dijkstra();

    cfn[p[1]] = 1;
    update(p[1], 0);

    for (int i = 2; i <= f + 1; i ++){
        cff[p[i]] = 1;
        update(p[i], 1);
    }

    for (int i = 1; i < n; i ++)
        if ( cff[i] == cfn[i] && cfn[i] == 1 ) ans = max(ans, d[i]);

    cout << ans;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> s >> f;
    for (int t = 1; t <= s; t ++){
        int i, j, c;
        cin >> i >> j >> c;
        adj[i].push_back({j, c});
        adj[j].push_back({i, c});
    }

    for (int i = 1; i <= f + 1; i ++)
        cin >> p[i];

    solve();

    return 0;
}
