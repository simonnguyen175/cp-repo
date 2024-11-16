#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5;

int n, m;
int timedfs, used[N], num[N], low[N], joint[N], bri = 0, joints = 0;
vector<pair<int, int>> adj[N];

void dfs(int u, int pu){
    int childs = 0;
    num[u] = low[u] = ++timedfs;
    for (auto it : adj[u]) if ( !used[it.se] ){
        int v = it.fi;
        used[it.se] = 1;
        if ( !num[v] ){
            dfs(v, u);
            childs ++;
            low[u] = min(low[u], low[v]);
            if ( low[v] == num[v] ) bri ++;

            if ( u == pu ){
                if ( childs >= 2 )
                    joint[u] = 1;
            }
            else if ( low[v] >= num[u] )
                joint[u] = 1;
        }
        else low[u] = min(low[u], num[v]);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    memset(joint, 0, sizeof joint);
    for (int i = 1; i <= n; i ++)
        if ( !num[i] ) dfs(i, i);

    for (int i = 1; i <= n; i ++)
        if ( joint[i] ) joints ++;

    cout << joints << ' ' << bri << '\n';

    return 0;
}
