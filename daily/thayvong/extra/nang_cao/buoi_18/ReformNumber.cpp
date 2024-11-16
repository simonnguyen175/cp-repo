#include <bits/stdc++.h>
#define simon "ReformNumber"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e7+1;

int a, M, dp[N];
queue<int> q;
bool vis[N];

void BFS(){
    memset(vis, 0, sizeof vis);
    memset(dp, 0, sizeof dp);
    q.push(a);
    vis[a]=1;
    while ( !q.empty() ){
        int x=q.front();
        if ( dp[x] > N ) break;
        if ( x == M ) break;
        q.pop();
        q.push(2*x+1);
        q.push(3*x-1);
        vis[2*x+1]=1;
        vis[3*x-1]=1;
        dp[2*x+1]=dp[x]+1;
        dp[3*x-1]=dp[x]+1;
    }
}

int main(){
    FASTio
    if ( fopen(simon".inp","r") ){
        freopen(simon".inp","r",stdin);
        freopen(simon".out","w",stdout);
    }
    cin >> a >> M;
    BFS();
    if ( dp[M] == 0 ) cout << -1;
    else cout << dp[M];
    return 0;
}
