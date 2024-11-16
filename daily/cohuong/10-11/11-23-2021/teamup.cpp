#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 200;

int n, m = 0;
int side[N], L[N], R[N], f[N][N];
bool G[N][N], bipartite = 1;
vector<int> cont;

void dfs(int u){
    cont.pb(u);
    for (int v = 1; v <= n; v ++) if ( v != u && G[u][v] ){
        if ( side[v] == -1 ){
            side[v] = side[u] ^ 1;
            dfs(v);
        }
        else bipartite &= side[u] != side[v];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    if ( fopen("teamup.inp", "r") ){
        freopen("teamup.inp", "r", stdin);
        freopen("teamup.out", "w", stdout);
    }

    cin >> n;
    memset(G, 1, sizeof G);
    for (int u = 1; u <= n; u ++){
        int v;
        while ( cin >> v )
            if ( v ) G[u][v] = 0;
            else break;
    }

    memset(side, -1, sizeof side);

    for (int i = 1; i <= n; i ++)
        if ( side[i] == -1 ){
            cont.clear(), side[i] = 0, dfs(i);
            m ++;
            for (int u : cont)
                L[m] += side[u], R[m] += !side[u];
        }

    if ( !bipartite ){
        cout << "No solution";
        return 0;
    }

    f[0][0] = 1;
    for (int i = 0; i < m; i ++)
    for (int j = 0; j <= n; j ++) if ( f[i][j] ){
        f[i+1][j+L[i+1]] = 1;
        f[i+1][j+R[i+1]] = 1;
    }

    int ans = n + 1;
    for (int i = 0; i <= n; i ++) if ( f[m][i] ){
        ans = min(ans, abs(n - 2*i));
    }

    cout << ans;

    return 0;
}
