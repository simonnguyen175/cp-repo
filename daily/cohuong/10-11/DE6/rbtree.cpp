#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 2;
const int MOD = 1e9 + 7;

int n, m, timeDfs = 0;
vector<int> adj[N], f[N];
bool red[N];
int cred[N], num[N];

int add(int a, int b){
    a += b;
    if ( a >= MOD ) a -= MOD;
    if ( a < 0 ) a += MOD;
    return a;
}

int mul(int a, int b){
    return 1LL * a * b % MOD;
}

void dfs(int u){
    num[u] = ++timeDfs;
    if ( red[u] ) cred[u] = 1;
    for (int v : adj[u]){
        dfs(v);
        cred[u] += cred[v];
    }
}

void anal(int u){
    f[u].resize(cred[u]+1);
    int s = 0;

    if ( adj[u].size() == 0 ){
        if ( red[u] ) f[u][1] = add(f[u][1], 1);
        else f[u][0] = add(f[u][0], 1);
    }
    else{
        f[u][0] = 1;

        for (int v : adj[u]){
            for (int cur = s; cur >= 0; cur --)
            for (int bon = cred[v]; bon >= 0; bon --)
                f[u][cur+bon] = add(f[u][cur+bon], mul(f[u][cur], f[v][bon]));
            s += cred[v];
        }

        f[u][0] -= 1;

        if ( red[u] ) f[u][1] = add(f[u][1], 1);
        else f[u][0] = add(f[u][0], 1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("rbtree.in", "r") ){
        freopen("rbtree.in", "r", stdin);
        freopen("rbtree.out", "w", stdout);
    }

    cin >> n >> m;
    for (int i = 2, x; i <= n; i ++)
        cin >> x, adj[x].pb(i);

    for (int i = 1, x; i <= m; i ++)
        cin >> x, red[x] = 1;

    dfs(1);

    vector<int> cont;
    for (int i = 1; i <= n; i ++) cont.pb(i);
    sort(cont.begin(), cont.end(), [](int a, int b){
        return num[a] > num[b];
    });

    for (int u : cont) anal(u);

    for (int i = 0; i <= m; i ++)
        cout << f[1][i] + ( i == 0 ) << '\n';

    return 0;
}
