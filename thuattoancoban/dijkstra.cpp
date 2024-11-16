#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
typedef pair<int, int> ii;

int n, m;
vector<ii> a[1001];
int d[1001];

void dijkstra(){
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i=1; i<=n; i++)
        d[i]=INT_MAX;
    d[1]=0;
    pq.push(ii(0, 1));

    while ( !pq.empty() ){
        int u=pq.top().se;
        int du=pq.top().fi;
        pq.pop();

        for (int i=0; i < a[u].size(); i++){
            int v=a[u][i].se;
            int uv=a[u][i].fi;
            if ( d[v] > du + uv ){
                d[v] = du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u, v, l;
        cin >> u >> v >> l;
        a[u].push_back(ii(l, v));
        a[v].push_back(ii(l, u));
    }
    dijkstra();
    for (int i=1; i<=n; i++) cout << i <<' '<<d[i]<<'\n';
    return 0;
}
