#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;

int n, m, q;
struct ocas{
    int t, u, c, s;
} oca[N];
struct query{
    int d, u, id;
} que[N];
vector<int> adj[N];
int d[N];
queue<int> Q;
ll cost[N], ans[N];

void bfs(int u, int c, int s){
    for (int i = 1; i <= n; i ++) d[i] = -1;
    Q.push(u);
    d[u] = 0;

    while ( Q.size() ){
        int u = Q.front();
        Q.pop();

        if ( d[u] <= s ){
            cost[u] += c;
        }
        else continue;

        for (int v : adj[u]) if ( d[v] == -1 ){
            d[v] = d[u] + 1;
            Q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("firework.inp", "r", stdin);
    freopen("firework.out", "w", stdout);

    cin >> n >> m >> q;
    for (int i = 1, u, v; i < n; i ++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for (int i = 1; i <= m; i ++){
        int t, u, c, s;
        cin >> t >> u >> c >> s;
        oca[i] = {t, u, c, s};
    }
    sort(oca + 1, oca + 1 + m, [&](ocas a, ocas b){
        return a.t < b.t;
    });

    for (int i = 1; i <= q; i ++)
        cin >> que[i].d >> que[i].u, que[i].id = i;
    sort(que + 1, que + 1 + q, [&](query a, query b){
        return a.d < b.d;
    });

    int ptr = 1;
    for (int i = 1; i <= q; i ++){
        while ( ptr <= m && oca[ptr].t <= que[i].d ){
            bfs(oca[ptr].u, oca[ptr].c, oca[ptr].s);
            ptr ++;
        }

        ans[que[i].id] = cost[que[i].u];
    }

    for (int i = 1; i <= q; i ++)
        cout << ans[i] << '\n';


    return 0;
}
