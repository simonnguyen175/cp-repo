#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e2 + 5;
const ll oo = 1e15;

int n, m;
vector<int> adj[N];
ll c[N][N];
bool vis[N];
ll sum = 0;
struct edge{
    int u, v; ll w;
}mxe[N];

void dfs(int u){
    vis[u] = 1;
    for (int v : adj[u]){
        if ( vis[v] ) continue;
        dfs(v);
    }
}

bool cklt(){
    memset(vis, 0, sizeof vis);
    dfs(1);
    for (int i = 1; i <= n; i ++)
        if ( !vis[i] ) return false;
    return true;
}

void dfs1(int u, int pu){
    for (int v : adj[u]){
        if ( v == pu ) continue;
        if ( c[u][v] > mxe[u].w )
            mxe[v] = {u, v, c[u][v]};
        else mxe[v] = mxe[u];
        dfs1(v, u);
    }
}

edge findmx(int u, int v){
    for (int i = 1; i <= n; i ++) mxe[i] = {0, 0, -oo};
    dfs1(u, 0);
    return mxe[v];
}

void del(int u, int v){
    for (int i = 0; i < adj[u].size(); i ++)
        if ( adj[u][i] == v ){
            swap(adj[u][i], adj[u][adj[u].size()- 1]);
            break;
        }
    adj[u].pop_back();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("smst.inp", "r", stdin);
    freopen("smst.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v; ll w;
        cin >> u >> v >> w;

        if ( u == v ){
            if ( cklt() )
            cout << sum << '\n';
            else cout << 123456789 << '\n';
            continue;
        }

        edge med;
        med = findmx(u, v);

        //cerr << u << " -> " << v << " : \n";

        if ( med.w == -oo ){
            sum += w;
            c[u][v] = c[v][u] = w;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        else if ( med.w > w ){
            sum += w - med.w;
            c[u][v] = c[v][u] = w;
            adj[u].push_back(v); adj[v].push_back(u);
            del(med.u, med.v); del(med.v, med.u);
        }
        //cerr << med.u << ' ' << med.v << ' ' << med.w << ' ' << sum << '\n';
        /*
        for (int u = 1; u <= n; u ++){
            cout << u << " : ";
            for (int v : adj[u]) cout << v << ' ';
            cout << '\n';
        }
        */

        if ( cklt() )
            cout << sum << '\n';
        else cout << 123456789 << '\n';
    }

    return 0;
}
