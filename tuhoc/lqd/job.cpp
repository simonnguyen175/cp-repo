#include<bits/stdc++.h>
#define simon "job"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ii pair<int, int>
using namespace std;
const int N = 3e5 + 1;

int n, m, root, t=0;
vector<int> adj[N];
int depth[N], cnt[N], par[N];
priority_queue<ii> q;

void dfs(int u){
    for (int v : adj[u]){
        depth[v] = depth[u] + 1;
        dfs(v);
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i=1; i<=n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        par[u] = v;
    }

    root = 1;
    while ( par[root] ) root = par[root];
    dfs(root);


    for (int i=1; i<=n; i++){
        cnt[i] = adj[i].size();
        if( cnt[i] == 0 )
            q.push({depth[i], i});
    }

    /*
    cout << root <<'\n';
    for (int i=1; i<=n; i++) cout << depth[i] <<' ' <<cnt[i] <<'\n';
    cout << '\n' << '\n';
    */

    while ( !q.empty() ){
        t++;
        vector<int> nxt;
        for (int i=1; i<=m && !q.empty(); i++){
            ii u = q.top();
            //cout << u.second <<' ';
            q.pop();
            nxt.push_back(par[u.second]);
        }

        for (int i=0; i<nxt.size(); i++){
            cnt[nxt[i]]--;
            if ( cnt[nxt[i]] == 0 ){
                //cout << "push" << ' '<<nxt[i]<<'\n';
                q.push({depth[nxt[i]], nxt[i]});
            }
        }

        //cout << t <<'\n';
    }

    cout << t;
    return 0;
}
