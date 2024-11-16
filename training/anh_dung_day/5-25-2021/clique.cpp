#include<bits/stdc++.h>
#define simon "clique"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e3 + 5e2 + 5;
const int M = 5e3 + 5;

int n, m;
long long ans;
vector<int> adj[N+M];
long long d[N+M], numf[N+M], shortestPath[N+M][N+M];
bool vis[N+M];

void BFS(int x){
    memset(d, 0, sizeof d);
    memset(vis, 0, sizeof vis);
    memset(numf, 0, sizeof numf);


    queue<int> q;
    q.push(x);
    d[x] = 0;
    numf[x] = 0;

    while ( !q.empty() ){
        int u = q.front();
        q.pop();

        for (auto v : adj[u]){
            if ( vis[v] ) continue;
            d[v] = d[u] + 1;
            if ( v > n ) numf[v] = numf[u] + 1;
            else numf[v] = numf[u];
            vis[v] = 1;
            q.push(v);
        }
    }
}


int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }

    cin >> n >> m;

    int fakeV = n;

    while ( m -- ){
        int k, u;
        cin >> k;
        fakeV ++;
        for (int i = 1; i <= k; i ++){
            cin >> u;
            adj[fakeV].push_back(u);
            adj[u].push_back(fakeV);
        }
    }

    for (int i = 1; i <= n; i ++){
        BFS(i);
        for (int j = 1; j <= n; j ++)
            shortestPath[i][j] = d[j] - numf[j];
    }

    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            ans += shortestPath[i][j];

    cout << ans;

    return 0;
}
