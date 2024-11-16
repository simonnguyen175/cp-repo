#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
#define pb push_back
#define BIT(x,k) ((x>>k)&1)
using namespace std;
const int N = 1e5 + 5;

int n, m, timeBfs = 0;
vector<int> adj[N];
int num[N], bit[N];
pi rmq[N][22];

void bfs(){
    queue<int> q;
    q.push(1);
    num[1] = ++timeBfs;

    while ( q.size() ){
        int u = q.front();
        q.pop();
        int child = 0;
        for (int v : adj[u]) if ( !num[v] ){
            num[v] = ++timeBfs;
            q.push(v);
            child ++;
        }
        cerr << u << ' ' << child << '\n';
        rmq[num[u]][0] = {timeBfs-child+1, timeBfs};
    }
}

pi getR(int u, int k){
    pi res = {u, u};

    for (int i = 20; i >= 0; i --)
        if ( BIT(k, i) ){
            res.fi = rmq[res.fi][i].fi;
            res.se = rmq[res.se][i].se;
        }

    return res;
}

void update(int u, int v){
    for (; u <= n; u += u&(-u)) bit[u] += v;
}

int get(int u){
    int res = 0;
    for (; u >= 1; u -= u&(-u)) res += bit[u];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("company.in", "r", stdin);
    freopen("company.out", "w", stdout);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs();

    for (int j = 1; j <= 20; j ++)
    for (int i = 1; i <= n; i ++){
        int l = rmq[rmq[i][j-1].fi][j-1].fi;
        int r = rmq[rmq[i][j-1].se][j-1].se;
        rmq[i][j] = {l, r};
    }

    cin >> m;
    for (int i = 1; i <= m; i ++){
        int type, u, k, e;

        cin >> type;

        if ( type == 1 ){
            cin >> u >> k >> e;

            pi tmp = getR(num[u], k);

            if ( tmp.fi > tmp.se ) continue;

            update(tmp.fi, e);
            update(tmp.se+1, -e);
        }

        if ( type == 2 ){
            cin >> u;
            cout << get(num[u]) << '\n';
        }
    }

    return 0;
}
