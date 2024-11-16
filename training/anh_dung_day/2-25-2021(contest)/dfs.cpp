#include <bits/stdc++.h>
using namespace std;

int n, m, u, v;
pair<int, int > edge[300001];
vector<int> a[300001], ans;
int vis[300001];

void DFS(int s){
    for (int f=0; f<a[s].size(); f++){
        if ( vis[a[s][f]]==0 ){
            vis[ a[s][f] ]=s;
            DFS( a[s][f] );
        }
    }
}

int main(){
    cin >> n >> m >> u >> v;
    for (int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        edge[i]={x, y};
    }
    sort(edge+1, edge+m+1);
    for (int i=1; i<=m; i++){
        a[edge[i].first].push_back(edge[i].second);
    }
    vis[u]=-1;
    DFS(u);
    if ( vis[v] == 0 ) cout <<-1;
    else{
        while ( v != u ){
            ans.push_back(v);
            v=vis[v];
        }
        cout << ans.size()<<'\n';
        ans.push_back(u);
        for (int i=ans.size()-1; i>=0; i--) cout << ans[i] <<' ';
    }
    return 0;
}
