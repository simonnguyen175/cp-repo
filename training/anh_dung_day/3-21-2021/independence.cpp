#include <bits/stdc++.h>
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e6+1;

int n;
vector<int> adj[N];
long long C[N], dp1[N], dp2[N], ans;

void dfs(int V, int pV){
    long long sum1=0, sum2=0;
    for(auto v: adj[V]){
        if(v == pV) continue;
        dfs(v, V);
        sum1 += dp2[v];
        sum2 += max(dp1[v], dp2[v]);
    }
    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}

int main(){
    FASTio
    cin >> n;

    for (int i=1; i<=n; i++) cin >> C[i];

    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    ans = max(dp1[1], dp2[1]);
    cout << ans;
    return 0;
}
