#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

int n, m, ans, numCat[N];
vector<int> ver[N];
bool cat[N], vis[N];

void bfs(){
    ans=0;
    vis[1]=1;
    if ( cat[1] ) numCat[1]=1;
    queue<int> q;
    q.push(1);
    while ( !q.empty() ){
        int u=q.front();
        q.pop();
        if ( ver[u].size() == 1 && vis[ver[u][0]] && numCat[u] <= m)
            ans++;
        else{
            for (int i=0; i < ver[u].size(); i++){
                int v=ver[u][i];
                if ( !vis[v] ){
                    if ( cat[v] == 1 )
                        numCat[v]=numCat[u]+1;
                    else if ( numCat[u] > m )
                        numCat[v]=numCat[u];
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        cin >> cat[i];
    for (int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    bfs();
    cout << ans;
    return 0;
}
