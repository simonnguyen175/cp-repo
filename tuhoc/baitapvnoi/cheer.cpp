#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

struct canh{
    int u, v, w;
};

bool cmp(canh a, canh b){
    return a.w < b.w;
}

int n, p;
int c[N];
canh edge[N];
int par[N], Rank[N];
long long ans = 0;

int getroot(int u){
    if ( par[u] == 0 ) return u;
    return par[u] = getroot(par[u]);
}

void maketree(){
    sort(edge + 1, edge + 1 + p, cmp);
    for (int i = 1; i <= p; i ++){
        int u = edge[i].u, v = edge[i].v;
        u = getroot(u); v = getroot(v);

        if ( u == v ) continue;

        ans += edge[i].w;
        if ( Rank[u] < Rank[v] ) swap(u, v);
        par[v] = u;
        if ( Rank[u] == Rank[v] ) Rank[u] ++;
    }
}

int main(){
    ios::sync_with_stdio(false);
        cin.tie(0);
    cin >> n >> p;
    int minfield = INT_MAX;
    for (int i = 1; i <= n; i ++){
        cin >> c[i];
        minfield = min(minfield, c[i]);
    }
    for (int i = 1; i <= p; i ++){
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
        edge[i].w = 2 * edge[i].w + c[edge[i].u] + c[edge[i].v];
    }

    maketree();

    cout << ans + minfield;

    return 0;
}
