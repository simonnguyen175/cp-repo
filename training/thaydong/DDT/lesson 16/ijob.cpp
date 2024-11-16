#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 2e5 + 5;

int n;
vector<int> adj[N];

set<int> dfs(int u, int pu){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int x; cin >> x;
        if ( i == 0 ) continue;
        adj[x].pb(i);
    }

    set<>

    return 0;
}
