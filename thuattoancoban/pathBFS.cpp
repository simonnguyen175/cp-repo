#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,trace[105];
vector<int> path[105];
vector<int> res;
void BFS(){
    bool vsed[105];
    memset(vsed,false,sizeof(vsed));
    queue<int> tmp;
    tmp.push(u);
    trace[u] = -1;
    vsed[u] = true;
    while(!tmp.empty()){
        int k = tmp.front();
        for(int i = 0; i < path[k].size(); ++i){
        if(vsed[path[k][i]]) continue;
        tmp.push(path[k][i]);
        trace[path[k][i]] = k;
        vsed[path[k][i]] = true;
        }
    tmp.pop();
    }
}
int main()
{
    freopen("PathBFS.inp","r",stdin);
    freopen("PathBFS.out","w",stdout);
    cin >> n >> m >> u >> v;
    for(int i = 1; i <= m; ++i){
        int x,y;
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    BFS();
    int k = v;
    while(k != u){
        res.push_back(k);
        k = trace[k];
    }
    cout << u << ' ';
    for(int i = res.size() - 1; i >= 0; --i)
    cout << res[i] << ' ';
    return 0;
}
