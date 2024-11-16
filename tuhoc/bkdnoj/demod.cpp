#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e2 + 5;

int n;
vector<int> g[N];
int cnt, ans, vis[N];

void dfs(int u){
    cnt ++;
    vis[u] = 1;
    for (int v : g[u]) if ( !vis[v] )
        dfs(v);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ans = 0;
    for (int i = 1; i <= n; i ++) if ( !vis[i] ){
        cnt = 0;
        dfs(i);
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}
