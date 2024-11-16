#include<bits/stdc++.h>
using namespace std;
const int N = 40;

int n, m;
pair<int, int> edges[N];
int Par[N], Rank[N];
bool con[N][N];

int Find(int u){
    if ( u == Par[u] ) return u;
    return Par[u] = Find(Par[u]);
}

void Join(int u, int v){
    u = Find(u), v = Find(v);
    if ( u != v ){
        if ( Rank[u] < Rank[v] ) swap(u, v);

        Par[v] = u;

        if ( Rank[u] == Rank[v] ) Rank[u] ++;
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        edges[i] = {u,v};
    }

    for (int i = 1; i <= n; i ++)
        Par[i] = i, Rank[i] = 0;

    for (int i = 1; i <= m; i ++)
        Join(edges[i].first, edges[i].second);

    memset(con, 0, sizeof con);
    for (int i = 1; i <= n; i ++)
    for (int j = i+1; j <= n; j ++)
        if ( Find(i) == Find(j) ) con[i][j] = con[j][i] = 1;

    int ans = 0;

    for (int t = 1; t <= (1<<m)-1; t ++){
        for (int i = 1; i <= n; i ++)
            Par[i] = i, Rank[i] = 0;

        for (int i = 1; i <= m; i ++)
            if ( t&(1<<(i-1)) )
                Join(edges[i].first, edges[i].second);

        bool flag = 1;

        for (int i = 1; i <= n; i ++)
        for (int j = i+1; j <= n; j ++)
            if ( Find(i) != Find(j) && con[i][j] == 1 ){
                flag = 0;
                break;
            }

        if ( flag ) ans ++;
    }

    cout << ans;

    return 0;
}
