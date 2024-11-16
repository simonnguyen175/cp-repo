#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 3e5 + 5;

int n, s, t;
int a[N], d[N];
vector<int> adj[N];
map<int, int> h;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        h[a[i]] = 1;
    }

    for (int i = 2; i <= N-5; i ++) if ( !adj[i].size() )
    for (int j = i * 2; j <= N-5; j += i) if ( h[j] ){
        adj[i].pb(j);
        adj[j].pb(i);
    }

    for (int i = 1; i <= N-5; i ++)
        d[i] = -1;

    cin >> s >> t;

    queue<int> q;
    d[a[s]] = 0;
    q.push(a[s]);

    while ( q.size() ){
        int u = q.front();
        q.pop();

        for (int v : adj[u]) if ( d[v] == -1 ){
            d[v] = d[u] + 1;
            q.push(v);
        }
    }

    if ( d[a[t]] == -1 ) cout << -1;
    else cout << d[a[t]]/2 + 1;

    return 0;
}
