#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4 + 5;

int n;
struct edg{
    int u, v, w;
} edges[N];
int Par[N], Size[N];
ll ans = 0;

int Find(int u){
    if ( u == Par[u] ) return u;
    else return Par[u] = Find(Par[u]);
}

void Join(int u, int v, int w){
    u = Find(u), v = Find(v);
    ans += 1LL * ( w + 1 ) * Size[u] * Size[v] - w - 1;
    if ( Size[u] < Size[v] ) swap(u, v);
    Par[v] = u;
    Size[u] += Size[v];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
        edges[i] = {u, v, w};
    }

    sort(edges+1, edges+n, [](edg a, edg b){
        return a.w < b.w;
    });

    for (int i = 1; i <= n; i ++) Par[i] = i, Size[i] = 1;

    for (int i = 1; i < n; i ++){
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        Join(u, v, w);
    }

    cout << ans;

    return 0;
}
