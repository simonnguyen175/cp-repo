#include<bits/stdc++.h>
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m;
map<pi, int> g, d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i ++){
        cin >> u >> v;
        if ( u > v ) swap(u, v);
        g[{u, v}] = 1;
    }

    int ans = 1;
    queue<pi> q;
    for (int i = 1; i <= n; i ++){
        d[{i, i}] = 1;
        q.push({i, i});
    }
    for (int i = 1; i < n; i ++) if ( g[{i, i+1}] ){
        d[{i, i+1}] = 2;
        q.push({i, i+1});
    }

    while ( q.size() ){
        int u = q.front().fi, v = q.front().se;
        ans = max(ans, d[{u, v}]);
        q.pop();

        if ( u > 1 && v < n && g[{u-1, v+1}] ){
            d[{u-1, v+1}] = d[{u, v}] + 2;
            q.push({u-1, v+1});
        }
    }

    cout << ans;

    return 0;
}

