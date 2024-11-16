#include <bits/stdc++.h>
#define simon "friend"
#define FASTio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define cc pair<char, char>
using namespace std;
const int N=5e4+1;
const int oo=1e18;

int n, t;
string s[N];
bool vis[130];
queue<char> q;
int adj[130][130], d[130];

int solve(int u, int v){
    int res;
    memset(vis, 0, sizeof vis);
    memset(d, 0, sizeof d);
    while ( !q.empty() ) q.pop();

    for (int i=0; i<s[u].size(); i++){
        q.push(s[u][i]);
        vis[s[u][i]]=1;
    }

    while ( !q.empty() ){
        char x=q.front();
        if ( s[v].find(x) != -1 ) return d[x]+2;
        q.pop();
        for (char y='a'; y<='z'; y++)
            if ( adj[x][y] && !vis[y]){
                d[y]=d[x]+1;
                vis[y]=1;
                q.push(y);
            }
    }
    return -1;
}

int main(){
    //input
    FASTio
    cin >> n >> t;
    memset(adj, 0, sizeof adj);
    for (int i=1; i<=n; i++){
        cin >> s[i];
        for (int j=0; j<s[i].size()-1; j++)
            for (int k=j+1; k<s[i].size(); k++) adj[s[i][j]][s[i][k]]=1, adj[s[i][k]][s[i][j]]=1;
    }
    //solve
    for (int i=1; i<=t; i++){
        int u, v;
        cin >> u >> v;
        cout << solve(u, v) <<'\n';
    }
}
