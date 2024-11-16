#include<bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define fi first
#define se second
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int n;
ll k;
vector<pair<int, ll>> adj[N];

void dfs(int u, int pu){
    for (auto it : adj[u]){
        int v = it.fi;
        ll w = it.se;
        if ( v == pu ) continue;
        f[v] = f[u] ^ w;
        dfs(v, u);
    }
}

void add(ll val){
    cur = 0;
    for (int i = 0; i <= 63; i ++){
        int t = (vall >> i) & 1;
        if ( trie[cur][t] == -1 )
            trie[cur][t] = ++ ntrie;
        cur = trie[cur][t];
        cnt[cur] ++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int pi, wi;
        cin >> pi >> wi;
        adj[pi].pb({i, wi});
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i ++){
        add(f[i]);
    }



    return 0;
}
