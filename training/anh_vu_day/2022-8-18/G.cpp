#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e6 + 5;

int n, k;
int a[N], deg[N], d[N];
vector<int> adj[N], ans;

void topo(){
    priority_queue<int, vector<int>, greater<int>> q;
    for (int u = 1; u <= N-5; u ++)
        if ( !deg[u] && d[u] ) q.push(u);
    while ( q.size() ){
        int u = q.top();
        q.pop();
        ans.pb(u);
        for (auto v : adj[u]){
            deg[v] --;
            if ( !deg[v] ) q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> k;
        for (int j = 1; j <= k; j ++)
            cin >> a[j], d[a[j]] = 1;
        for (int j = 1; j < k; j ++){
            adj[a[j]].pb(a[j+1]);
            deg[a[j+1]] ++;
        }
    }

    topo();

    for (auto x : ans) cout << x << ' ';

    return 0;
}
