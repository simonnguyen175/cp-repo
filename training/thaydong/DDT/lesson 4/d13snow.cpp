#include<bits/stdc++.h>
#define ll long long
#define BIT(x,k) (((x) >> k) & 1)
using namespace std;
const int N = 105;
const ll oo = 1e15;

int n, m, k, t;
ll c[N][N], l[N];
int vip[N], con[N], pos[N];
vector<pair<int, ll>> adj[N];
ll f[N][2000];

struct edge{
    int u, v;
    ll w;
};
vector<edge> edges;
int cha[N], hang[N];

struct opt{
    int u;
    ll val;
    int mask;
};

int Find(int u){
    if ( cha[u] != u ) cha[u] = Find(cha[u]);
    return cha[u];
}

bool Join(int u, int v){
    u = Find(u); v = Find(v);
    if ( u == v ) return false;

    if ( hang[u] == hang[v] ) hang[u] ++;
    if ( hang[u] < hang[v] ) cha[u] = v;
    else cha[v] = u;
    return true;
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

ll kruskal(){
    ll res = 0;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 1; i <= n; i ++) cha[i] = i, hang[i] = 0;
    for (edge e : edges)
        if ( Join(e.u, e.v) )
            res += e.w;
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        if ( con[i] ){
            int root = Find(i);
            if ( root == i ) cnt ++;
            if ( cnt == 2 ) return oo;
            if ( cnt == 2 ) return oo;
        }
    return res;
}

bool operator > (const opt& a, const opt& b){
    return a.val > b.val;
}

void sub1_4(){
    if ( k == n ){
        edges.clear();
        for (int i = 1; i <= n; i ++)
            for (auto j : adj[i]) edges.push_back({i, j.first, j.second});
        cout << kruskal();
    }
    else{
        for (int i = 1; i <= n; i ++)
            for (int j = 0; j <= (1<<k)-1; j ++)
                f[i][j] = oo;

        priority_queue<opt, vector<opt>, greater<opt>> heap;

        for (int i = 1; i <= n; i ++)
            if ( pos[i] > 0 ) f[i][1<<(pos[i]-1)] = 0, heap.push({i, 0, (1<<(pos[i]-1))});
            else f[i][0] = 0, heap.push({i, 0, 0});

        while ( !heap.empty() ){
            int u = heap.top().u;
            ll du = heap.top().val;
            int mask = heap.top().mask;
            heap.pop();

            if ( du != f[u][mask] ) continue;

            for (auto it : adj[u]){
                int v = it.first; ll w = it.second;

                if ( pos[v] > 0 && !BIT(mask, pos[v]-1) ){
                    int nmask = (mask|(1<<(pos[v]-1)));
                    if ( f[v][nmask] > du + w ){
                        f[v][nmask] = du + w;
                        heap.push({v, f[v][nmask], nmask});
                    }
                }
                else{
                    if ( f[v][mask] > du + w ){
                        f[v][mask] = du + w;
                        heap.push({v, f[v][mask], mask});
                    }
                }
            }

            for (int nmask = mask + 1; nmask <= (1<<k)-1; nmask ++)
                if ( (nmask&mask) == mask ){
                    int t = nmask^mask;

                    if ( pos[u] > 0 && (t&(1<<(pos[u]-1))) == 0 ) t |= (1<<(pos[u]-1));

                    if ( f[u][nmask] > f[u][t] + du ){
                        f[u][nmask] = f[u][t] + du;
                        heap.push({u, f[u][nmask], nmask});
                    }
                }
        }

        ll ans = oo;
        for (int i = 1; i <= n; i ++)
            ans = min(ans, f[i][(1<<k)-1]);
        cout << ans;
    }
}

void sub5(){
    ll ans = oo;
    for (int t = 0; t <= (1<<k)-1; t ++){
        edges.clear();
        memset(con, 0, sizeof con);
        for (int i = 1; i <= n; i ++) if ( !pos[i] ) con[i] = 1;
        for (int i = 1; i <= k; i ++)
            if ( BIT(t, i-1) ) con[vip[i]] = 1;
        for (int i = 1; i <= n; i ++)
            if ( con[i] ) for (auto j : adj[i]) if ( con[j.first] )
                    edges.push_back({i, j.first, j.second});

        ans = min(ans, kruskal());
    }
    cout << ans;
}

int main(){
    cin >> n >> k >> m >> t;
    memset(pos, 0, sizeof pos);
    for (int i = 1; i <= k; i ++){
        int node; cin >> node;
        vip[i] = node;
    }
    for (int i = 1; i <= k; i ++) pos[vip[i]] = i;

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            if ( i == j ) c[i][j] = 0;
            else c[i][j] = oo;

    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;
        c[u][v] = min(c[u][v], w);
        c[v][u] = c[u][v];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int l = 1; l <= n; l ++)
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if ( c[i][j] > c[i][l] + c[l][j] )
                    c[i][j] = c[i][l] + c[l][j];

    if ( t == 1 ) sub1_4();
    else sub5();

    return 0;
}
