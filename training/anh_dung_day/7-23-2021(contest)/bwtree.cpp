#include<bits/stdc++.h>
#define simon "bwtree"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int oo = 1e9;

int n;
vector<int> adj[N];
int dp[N][3];

void dfsToDp(int u, int pu){
    bool check = 0;
    int mn = oo;
    for (int v : adj[u]){
        if ( v == pu ) continue;
        dfsToDp(v, u);

        // dp[u][0] chua to chua ke den
        // dp[u][1] chua to ke den
        // dp[u][2] to den

        dp[u][0] += dp[v][1];
        dp[u][2] += min({dp[v][0], dp[v][1], dp[v][2]});

        if ( adj[v].size() == 1 ){
            dp[u][1] += dp[v][2];
            dp[u][0] = oo;
            check = 1;
        }
        else{
            if ( dp[v][2] <= dp[v][1] ) check = 1;
            dp[u][1] += min(dp[v][2], dp[v][1]);
        }

        mn = min(dp[v][2] - dp[v][1], mn);
    }

    if ( check == 0 ) dp[u][1] += mn;
}

int main(){
    FASTio
    if ( fopen(simon".inp", "r") ){
        freopen(simon".inp", "r", stdin);
        freopen(simon".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i ++)
        dp[i][2] = 1;

    dfsToDp(1, 0);

    cout << min(dp[1][1], dp[1][2]);

    return 0;
}
