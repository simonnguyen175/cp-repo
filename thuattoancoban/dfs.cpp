#include<bits/stdc++.h>
#define ll long long
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
ll n, m, bd, kt, visited[101], ans[101] , u , v;
vector<int> a[101];
void dfs(int u, int i)
{
    visited[u] = false;
    ans[i] = u;
    if(u == kt)
    {
        for(int j = 1 ; j <= i ; j++) cout << ans[j] << ' ';
        return;
    }
    for(int v = 0 ; v < a[u].size(); v++)
    {
        int k = a[u][v];
        if(visited[k]) dfs(k, i + 1);
    }
}
int main()
{
    memset(visited, true, sizeof visited);
    memset(ans, 0, sizeof(ans));
    FASTio
    freopen("PathDFS.inp", "r", stdin);
    freopen("PathDFS.out", "w", stdout);
    cin >> n >> m >> bd >> kt;
    for(ll i = 1 ; i <= m; i++)
    {
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(bd, 1);
    return 0;
}
